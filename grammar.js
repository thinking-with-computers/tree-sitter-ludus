module.exports = grammar({
  name: 'Ludus',
  
  word: $ => $.name,
  
  rules: {
    source_file: $ => seq(
      optional($._terminator),
      repeat1($._line),
      optional($._expression)
    ),

    _line: $ => seq($._expression, $._terminator),
 
    _terminator: $ => repeat1(choice(
      $.newline,
      $.semicolon,
    )),

    newline: $ => "\n",

    semicolon: $ => ";",

    _expression: $ => choice(
      $._literal,
      $.name,
    ),

    name: $ => /[a-z][\w\-\!\?]*/,

    literal: $ => choice(
      $._atom,
      $.number,
      $.symbol,
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

    symbol: $ => seq(":", $.name),
    
  }
});