#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 19
#define LARGE_STATE_COUNT 9
#define SYMBOL_COUNT 17
#define ALIAS_COUNT 0
#define TOKEN_COUNT 9
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum {
  sym_newline = 1,
  sym_semicolon = 2,
  sym_name = 3,
  sym_true = 4,
  sym_false = 5,
  sym_nil = 6,
  sym_number = 7,
  anon_sym_COLON = 8,
  sym_source_file = 9,
  sym__line = 10,
  aux_sym__terminator = 11,
  sym__expression = 12,
  sym__literal = 13,
  sym_atom = 14,
  sym_symbol = 15,
  aux_sym_source_file_repeat1 = 16,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_newline] = "newline",
  [sym_semicolon] = "semicolon",
  [sym_name] = "name",
  [sym_true] = "true",
  [sym_false] = "false",
  [sym_nil] = "nil",
  [sym_number] = "number",
  [anon_sym_COLON] = ":",
  [sym_source_file] = "source_file",
  [sym__line] = "_line",
  [aux_sym__terminator] = "_terminator",
  [sym__expression] = "_expression",
  [sym__literal] = "_literal",
  [sym_atom] = "atom",
  [sym_symbol] = "symbol",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_newline] = sym_newline,
  [sym_semicolon] = sym_semicolon,
  [sym_name] = sym_name,
  [sym_true] = sym_true,
  [sym_false] = sym_false,
  [sym_nil] = sym_nil,
  [sym_number] = sym_number,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_source_file] = sym_source_file,
  [sym__line] = sym__line,
  [aux_sym__terminator] = aux_sym__terminator,
  [sym__expression] = sym__expression,
  [sym__literal] = sym__literal,
  [sym_atom] = sym_atom,
  [sym_symbol] = sym_symbol,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_newline] = {
    .visible = true,
    .named = true,
  },
  [sym_semicolon] = {
    .visible = true,
    .named = true,
  },
  [sym_name] = {
    .visible = true,
    .named = true,
  },
  [sym_true] = {
    .visible = true,
    .named = true,
  },
  [sym_false] = {
    .visible = true,
    .named = true,
  },
  [sym_nil] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__line] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__terminator] = {
    .visible = false,
    .named = false,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym__literal] = {
    .visible = false,
    .named = true,
  },
  [sym_atom] = {
    .visible = true,
    .named = true,
  },
  [sym_symbol] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 7,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 12,
  [15] = 13,
  [16] = 16,
  [17] = 17,
  [18] = 16,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(5);
      if (lookahead == '\n') ADVANCE(6);
      if (lookahead == '-') ADVANCE(1);
      if (lookahead == '0') ADVANCE(21);
      if (lookahead == ':') ADVANCE(24);
      if (lookahead == ';') ADVANCE(7);
      if (lookahead == 'f') ADVANCE(8);
      if (lookahead == 'n') ADVANCE(11);
      if (lookahead == 't') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(22);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 1:
      if (lookahead == '0') ADVANCE(21);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(22);
      END_STATE();
    case 2:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 3:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      END_STATE();
    case 4:
      if (eof) ADVANCE(5);
      if (lookahead == '-') ADVANCE(1);
      if (lookahead == '0') ADVANCE(21);
      if (lookahead == ':') ADVANCE(24);
      if (lookahead == 'f') ADVANCE(8);
      if (lookahead == 'n') ADVANCE(11);
      if (lookahead == 't') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(22);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(sym_newline);
      if (lookahead == '\n') ADVANCE(6);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_semicolon);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'a') ADVANCE(12);
      if (lookahead == '!' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '?' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'e') ADVANCE(18);
      if (lookahead == '!' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '?' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'e') ADVANCE(19);
      if (lookahead == '!' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '?' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'i') ADVANCE(13);
      if (lookahead == '!' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '?' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'l') ADVANCE(15);
      if (lookahead == '!' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '?' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'l') ADVANCE(20);
      if (lookahead == '!' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '?' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'r') ADVANCE(16);
      if (lookahead == '!' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '?' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 's') ADVANCE(10);
      if (lookahead == '!' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '?' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(9);
      if (lookahead == '!' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '?' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == '!' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '?' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_true);
      if (lookahead == '!' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '?' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_false);
      if (lookahead == '!' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '?' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_nil);
      if (lookahead == '!' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '?' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(3);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(22);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 4},
  [4] = {.lex_state = 4},
  [5] = {.lex_state = 4},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 2},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_newline] = ACTIONS(1),
    [sym_semicolon] = ACTIONS(1),
    [sym_name] = ACTIONS(1),
    [sym_true] = ACTIONS(1),
    [sym_false] = ACTIONS(1),
    [sym_nil] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(17),
    [sym__line] = STATE(3),
    [aux_sym__terminator] = STATE(2),
    [sym__expression] = STATE(11),
    [sym__literal] = STATE(11),
    [sym_atom] = STATE(11),
    [sym_symbol] = STATE(11),
    [aux_sym_source_file_repeat1] = STATE(3),
    [sym_newline] = ACTIONS(3),
    [sym_semicolon] = ACTIONS(5),
    [sym_name] = ACTIONS(7),
    [sym_true] = ACTIONS(9),
    [sym_false] = ACTIONS(9),
    [sym_nil] = ACTIONS(9),
    [sym_number] = ACTIONS(7),
    [anon_sym_COLON] = ACTIONS(11),
  },
  [2] = {
    [sym__line] = STATE(4),
    [aux_sym__terminator] = STATE(8),
    [sym__expression] = STATE(11),
    [sym__literal] = STATE(11),
    [sym_atom] = STATE(11),
    [sym_symbol] = STATE(11),
    [aux_sym_source_file_repeat1] = STATE(4),
    [sym_newline] = ACTIONS(13),
    [sym_semicolon] = ACTIONS(15),
    [sym_name] = ACTIONS(7),
    [sym_true] = ACTIONS(9),
    [sym_false] = ACTIONS(9),
    [sym_nil] = ACTIONS(9),
    [sym_number] = ACTIONS(7),
    [anon_sym_COLON] = ACTIONS(11),
  },
  [3] = {
    [sym__line] = STATE(5),
    [sym__expression] = STATE(9),
    [sym__literal] = STATE(9),
    [sym_atom] = STATE(9),
    [sym_symbol] = STATE(9),
    [aux_sym_source_file_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(17),
    [sym_name] = ACTIONS(19),
    [sym_true] = ACTIONS(21),
    [sym_false] = ACTIONS(21),
    [sym_nil] = ACTIONS(21),
    [sym_number] = ACTIONS(23),
    [anon_sym_COLON] = ACTIONS(25),
  },
  [4] = {
    [sym__line] = STATE(5),
    [sym__expression] = STATE(10),
    [sym__literal] = STATE(10),
    [sym_atom] = STATE(10),
    [sym_symbol] = STATE(10),
    [aux_sym_source_file_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(27),
    [sym_name] = ACTIONS(29),
    [sym_true] = ACTIONS(21),
    [sym_false] = ACTIONS(21),
    [sym_nil] = ACTIONS(21),
    [sym_number] = ACTIONS(31),
    [anon_sym_COLON] = ACTIONS(25),
  },
  [5] = {
    [sym__line] = STATE(5),
    [sym__expression] = STATE(11),
    [sym__literal] = STATE(11),
    [sym_atom] = STATE(11),
    [sym_symbol] = STATE(11),
    [aux_sym_source_file_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(33),
    [sym_name] = ACTIONS(35),
    [sym_true] = ACTIONS(38),
    [sym_false] = ACTIONS(38),
    [sym_nil] = ACTIONS(38),
    [sym_number] = ACTIONS(41),
    [anon_sym_COLON] = ACTIONS(44),
  },
  [6] = {
    [aux_sym__terminator] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(47),
    [sym_newline] = ACTIONS(49),
    [sym_semicolon] = ACTIONS(51),
    [sym_name] = ACTIONS(53),
    [sym_true] = ACTIONS(53),
    [sym_false] = ACTIONS(53),
    [sym_nil] = ACTIONS(53),
    [sym_number] = ACTIONS(53),
    [anon_sym_COLON] = ACTIONS(53),
  },
  [7] = {
    [aux_sym__terminator] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(55),
    [sym_newline] = ACTIONS(57),
    [sym_semicolon] = ACTIONS(60),
    [sym_name] = ACTIONS(63),
    [sym_true] = ACTIONS(63),
    [sym_false] = ACTIONS(63),
    [sym_nil] = ACTIONS(63),
    [sym_number] = ACTIONS(63),
    [anon_sym_COLON] = ACTIONS(63),
  },
  [8] = {
    [aux_sym__terminator] = STATE(8),
    [sym_newline] = ACTIONS(65),
    [sym_semicolon] = ACTIONS(68),
    [sym_name] = ACTIONS(63),
    [sym_true] = ACTIONS(63),
    [sym_false] = ACTIONS(63),
    [sym_nil] = ACTIONS(63),
    [sym_number] = ACTIONS(63),
    [anon_sym_COLON] = ACTIONS(63),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    ACTIONS(71), 1,
      sym_newline,
    ACTIONS(73), 1,
      sym_semicolon,
    STATE(6), 1,
      aux_sym__terminator,
  [13] = 4,
    ACTIONS(71), 1,
      sym_newline,
    ACTIONS(73), 1,
      sym_semicolon,
    ACTIONS(75), 1,
      ts_builtin_sym_end,
    STATE(6), 1,
      aux_sym__terminator,
  [26] = 3,
    ACTIONS(71), 1,
      sym_newline,
    ACTIONS(73), 1,
      sym_semicolon,
    STATE(6), 1,
      aux_sym__terminator,
  [36] = 2,
    ACTIONS(79), 1,
      sym_semicolon,
    ACTIONS(77), 2,
      ts_builtin_sym_end,
      sym_newline,
  [44] = 2,
    ACTIONS(83), 1,
      sym_semicolon,
    ACTIONS(81), 2,
      ts_builtin_sym_end,
      sym_newline,
  [52] = 2,
    ACTIONS(77), 1,
      sym_newline,
    ACTIONS(79), 1,
      sym_semicolon,
  [59] = 2,
    ACTIONS(81), 1,
      sym_newline,
    ACTIONS(83), 1,
      sym_semicolon,
  [66] = 1,
    ACTIONS(85), 1,
      sym_name,
  [70] = 1,
    ACTIONS(87), 1,
      ts_builtin_sym_end,
  [74] = 1,
    ACTIONS(89), 1,
      sym_name,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(9)] = 0,
  [SMALL_STATE(10)] = 13,
  [SMALL_STATE(11)] = 26,
  [SMALL_STATE(12)] = 36,
  [SMALL_STATE(13)] = 44,
  [SMALL_STATE(14)] = 52,
  [SMALL_STATE(15)] = 59,
  [SMALL_STATE(16)] = 66,
  [SMALL_STATE(17)] = 70,
  [SMALL_STATE(18)] = 74,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(11),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(14),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(11),
  [44] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(16),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__line, 2),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__line, 2),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__terminator, 2),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__terminator, 2), SHIFT_REPEAT(7),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__terminator, 2), SHIFT_REPEAT(7),
  [63] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__terminator, 2),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__terminator, 2), SHIFT_REPEAT(8),
  [68] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__terminator, 2), SHIFT_REPEAT(8),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 3),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atom, 1),
  [79] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_atom, 1),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_symbol, 2),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_symbol, 2),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [87] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_Ludus(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
