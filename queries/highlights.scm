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
	"receive"
	"recur"
	"ref"
	"spawn"
	"then"
	"when"
	"with"
] @keyword

; Literals

(string) @string

(keyword) @string.special.symbol ; is this right?

(number) @number

[
	(identifier)
	(name)
] @variable

[
	(true)
	(false)
	(nil)
] @builtin

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