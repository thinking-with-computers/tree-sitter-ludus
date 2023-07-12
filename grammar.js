module.exports = grammar({
  name: 'Ludus',
  
  word: $ => $.name,
  
  rules: {
    source_file: $ => seq(
      optional($._terminator),
      repeat($._line),
      $.expression,
      optional($._terminator),
    ),

    _line: $ => seq($.expression, $._terminator),
 
    _terminator: $ => repeat1(choice(
      "\n",
      ";",
    )),

    expression: $ => choice(
      $.literal,
      $.name,
      $.if,
      $._collection,
    ),

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
    
    name: $ => /[a-z][\w\-\!\?]*/,

    literal: $ => choice(
      $._atom,
      $.number,
      $.symbol,
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
      $.nil
    ),

    true: $ => "true",

    false: $ => "false",

    nil: $ => "nil",

    number: $ => /\-?(([1-9]\d*)|0)(\.\d+)?/,

    symbol: $ => /:[a-z][\w\-\!\?]*/,

    _collection: $ => choice(
      $.tuple,
      $.dict,
      $.struct,
      $.list,
      $.set,
    ),

    tuple: $ => seq(
      "(",
      $._linear_collection,
      ")",
    ),

    _tuple_term: $ => choice($.expression, $.splat),

    splat: $ => seq("...", $.name),

    _tuple_entry: $ => seq($._tuple_term, $._separator),

    _separator: $ => repeat1(choice(",", "\n")),

    _linear_collection: $ => seq( 
      optional($._separator),
      repeat($._tuple_entry),
      $._tuple_term,
      optional($._separator),
    ),

    list: $ => seq(
      "[",
      $._linear_collection,
      "]",
    ),

    set: $ => seq(
      "${",
      $._linear_collection,
      "}",
    ),

    dict: $ => seq(
      "#{",
      optional($._separator),
      repeat($._dict_entry),
      $._dict_term,
      optional($._separator),
      "}",
    ),

    _dict_term: $ => choice(
      $.assoc,
      $.name,
      $.splat
    ),

    _dict_entry: $ => seq($._dict_term, $._separator),

    assoc: $ => seq($.symbol, $.expression),

    struct: $ => seq(
      "@{",
      optional($._separator),
      repeat($._struct_entry),
      $._struct_term,
      optional($._separator),
      "}",
    ),

    _struct_term: $ => choice(
      $.assoc,
      $.name,
    ),

    _struct_entry: $ => seq($._struct_term, $._separator),
    
    
  }
});