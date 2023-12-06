/*
TODO:
* Add use expressions
* Add repeat expressions
x Add guards
x Add type patterns if they're not here
* Figure out why this isn't working
* Add simple, compound, binding, non-binding scheme
*/

module.exports = grammar({
  name: 'ludus',
  
  word: $ => $.identifier,

  extras: $ => [
    $._whitespace,
    $.comment,
  ],
  
  rules: {
    source_file: $ => seq(
      optional($._terminator),
      repeat($._source_line),
      $._toplevel,
      optional($._terminator),
    ),

    comment: $ => /\&[^\n]*/,

    _whitespace: $ => token(/\s/),

    _source_line: $ => seq($._toplevel, $._terminator),
 
    _terminator: $ => repeat1(choice(
      "\n",
      ";",
    )),

    _toplevel: $ => choice(
      $.expression,
      $.import,
      $.ns,

    ),

    import: $ => seq("import", $.string, "as", $.name),

    expression: $ => choice(
      $.literal,
      $.if,
      $._collection,
      $.synthetic,
      $.loop,
      $.let,
      $.when,
      $.spawn,
      $.receive,
      $.block,
      $.do,
      $.ref,
      $.fn,
      $.recur,
    ),

    let: $ => seq("let", $.pattern, "=", $.expression),

    spawn: $ => seq("spawn", $.expression),

    pattern: $ => choice(
      $.name,
      $.typed,
      $.literal,
      $.tuple_pattern,
      $.list_pattern,
      $.dict_pattern,
      $.struct_pattern,
      $.placeholder,
    ),

    typed: $ => seq($.name, "as", $.keyword),

    when: $ => choice($.cond, $.match),

    cond_lhs: $ => choice($.expression, "else", $.placeholder),

    cond_clause: $ => seq($.cond_lhs, "->", $.expression),

    _cond_entry: $ => seq($.cond_clause, $._terminator),

    cond: $ => seq(
      "when",
      "{",
      optional($._terminator),
      repeat($._cond_entry),
      $.cond_clause,
      optional($._terminator),
      "}",
    ),

    match_lhs: $ => choice($.pattern, "else"),

    match_clause: $ => seq($.match_lhs, optional($.guard), "->", $.expression),

    guard: $ => seq("if", $.expression),

    _match_entry: $ => seq($.match_clause, $._terminator),

    match: $ => seq(
      "match",
      $.expression,
      "with",
      "{",
      optional($._terminator),
      repeat($._match_entry),
      $.match_clause,
      optional($._terminator),
      "}"
    ),

    receive: $ => seq(
      "receive",
      "{",
      optional($._terminator),
      repeat($._match_entry),
      $.match_clause,
      optional($._terminator),     
      "}",
    ),

    _linear_pattern_entry: $ => prec.left(1, seq($.pattern, $._separator)),

    tuple_pattern: $ => seq(
      "(",
      optional($._separator),
      repeat($._linear_pattern_entry),
      optional(choice($.pattern, $.splat)), // splats only go at the end
      optional($._separator), 
      ")",
    ),

    list_pattern: $ => seq(
      "[",
      optional($._separator),
      repeat($._linear_pattern_entry),
      optional(choice($.pattern, $.splat)), // splats only go at the end
      optional($._separator),
      "]",
    ),

    assoc_pattern: $ => choice(
      $.name,
      seq($.keyword, $.pattern),
    ),

    _assoc_entry: $ => prec.left(1, seq($.assoc_pattern, $._separator)),

    dict_pattern: $ => seq(
      "#{",
      optional($._separator),
      repeat($._assoc_entry),
      optional(choice($.assoc_pattern, $.splat)),
      optional($._separator),
      "}"
    ),

    struct_pattern: $ => seq(
      "@{",
      optional($._separator),
      repeat($._assoc_entry),
      optional(choice($.assoc_pattern, $.splat)),
      optional($._separator),
      "}"
    ),

    fn: $ => choice(
      $.lambda,
      $.named, 
      $.composite
    ),

    fn_clause: $ => seq($.tuple_pattern, "->", $.expression),

    lambda: $ => seq("fn", $.fn_clause),

    named: $ => seq("fn", $.name, $.fn_clause),

    _fn_entry: $ => seq($.fn_clause, $._terminator),

    composite: $ => seq(
      "fn", 
      $.name, 
      "{",
      optional($._terminator),
      optional(seq($.string, $._terminator)),
      repeat($._fn_entry),
      $.fn_clause,
      optional($._terminator),
      "}",
    ),

    _block_line: $ => seq($.expression, $._terminator),

    block: $ => seq("{", repeat1($._block_line), "}"),

    ref: $ => seq("ref", $.name, "=", $.expression),

    do: $ => prec.left(1, seq("do", $.expression, repeat1(seq(optional(repeat("\n")), ">", $.expression)))),

    loop: $ => seq(
      "loop",
      $.tuple,
      "with",
      $.loop_body,
    ),

    loop_body: $ => choice(
      $.fn_clause, 
      $.complex_loop_body
    ),

    complex_loop_body: $ => seq(      
      "{",
      optional($._terminator),
      repeat($._fn_entry),
      $.fn_clause,
      optional($._terminator),
      "}"
    ),

    recur: $ => seq("recur", $.tuple),

    if: $ => seq(
      "if",
      $.expression,
      repeat("\n"),
      "then",
      $.expression,
      repeat("\n"),
      "else",
      $.expression
    ),
    
    name: $ => choice($.identifier, $.reserved),

    identifier: $ => /[a-z][\w\-\!\?\/_]*/,

    reserved: $ => prec(-1, choice(
          "as",
          "do",
          "else",
          "false",
          "fn",
          "if",
          "import",
          "is",
          "let",
          "loop",
          "nil",
          "ns",
          "receive",
          "recur",
          "ref",
          //"send",
          "spawn",
          "then",
          "true",
          "when",
          "with",
        )),

    literal: $ => choice(
      $._atom,
      $.number,
      $.string,
    ),

    string: $ => seq(
      '"',
      /[^\"]*/,
      '"',
    ),

    _atom: $ => choice(
      $.true,
      $.false,
      $.nil,
      $.keyword
    ),

    true: $ => "true",

    false: $ => "false",

    nil: $ => "nil",

    number: $ => /\-?(([1-9]\d*)|0)(\.\d+)?/,

    keyword: $ => /:[a-z][\d\w\-\!\?]*/,

    _collection: $ => choice(
      $.tuple,
      $.dict,
      $.struct,
      $.list,
      $.set,
    ),

    tuple: $ => seq(
      "(",
      optional($._separator),
      repeat($._tuple_entry),
      $.expression,
      optional($._separator),
      ")",
    ),

    splat: $ => seq("...", $.name),

    _tuple_entry: $ => seq($.expression, $._separator),

    _separator: $ => prec.left(1, repeat1(choice(",", "\n"))),

    _linear_term: $ => choice($.expression, $.splat),

    _linear_entry: $ => prec.left(1, seq($._linear_term, $._separator)),

    list: $ => seq(
      "[",
      optional($._separator),
      repeat($._linear_entry),
      optional($._linear_term),
      optional($._separator),
      "]",
    ),

    set: $ => seq(
      "${",
      optional($._separator),
      repeat($._linear_entry),
      optional($._linear_term),
      optional($._separator),
      "}",
    ),

    dict: $ => seq(
      "#{",
      optional($._separator),
      repeat($._dict_entry),
      optional($._dict_term),
      optional($._separator),
      "}",
    ),

    _dict_term: $ => choice(
      $.assoc,
      $.name,
      $.splat
    ),

    _dict_entry: $ => prec.left(1, seq($._dict_term, $._separator)),

    assoc: $ => seq($.keyword, $.expression),

    struct: $ => seq(
      "@{",
      optional($._separator),
      repeat($._struct_entry),
      optional($._struct_term),
      optional($._separator),
      "}",
    ),

    ns: $ => seq(
      "ns", $.name, "{",
      optional($._separator),
      repeat($._struct_entry),
      optional($._struct_term),
      optional($._separator),
      "}",
    ),

    _struct_term: $ => choice(
      $.assoc,
      $.name,
    ),

    _struct_entry: $ => prec.left(1, seq($._struct_term, $._separator)),

    synthetic: $ => prec.left(1, seq($.synth_root, repeat($.synth_term))),

    synth_root: $ => prec.left(1, choice($.name, $.keyword)),

    synth_term: $ => choice($.args, $.keyword),

    placeholder: $ => "_",

    _arg_term: $ => choice($.placeholder, $.expression),

    _arg_entry: $ => prec.left(1, seq($._arg_term, $._separator)),

    args: $ => prec.left(1, seq(
          "(",
          repeat($._separator),
          repeat($._arg_entry),
          optional($._arg_term),
          repeat($._separator),
          ")"
        ))
    
  }
});
