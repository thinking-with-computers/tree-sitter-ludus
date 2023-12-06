; Keywords

[
	"as"
	"do"
	"else"
	"fn"
	"if"
	"import"
	"is"
	"let"
	"loop"
	"match"
	;"receive"
	"recur"
	"ref"
	;"repeat"
	;"spawn"
	"then"
	;"use"
	"when"
	"with"
] @keyword

; Literals

(string) @string

(keyword) @string.special.symbol ; is this right?

(number) @number

; Names

[
	(identifier)
	(name)
] @variable

; Constants

[
	(true)
	(false)
	(nil)
] @constant.builtin

(comment) @comment

; Punctuation

[
	"="
	"->"
] @operator

[
	","
	";"
] @punctuation.delimiter

[
	"#{"
	"@{"
	"${"
	"}"
	"("
	")"
	"["
	"]"
] @punctuation.bracket
