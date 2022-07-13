#ifndef LEXER_H
#define LEXER_H

#define N_KEYWORDS 15
#define KEYWORD_TABLE_SIZE (N_KEYWORDS* 2)
#define IS_NUMERIC(c) ('0' <= c && c <= '9')
#define IS_ALPHA(c) (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_')


enum token_type
{

    // BINARY 

    ARROW, DOT, LEFT_BRACK,  // 110

    STAR, SLASH, MODULUS,    // 100

    PLUS, MINUS,             // 90

    BIT_SHIFTR, BIT_SHIFTL,  // 80

    GT, LT, GTEQ, LTEQ,      // 70

    EQUAL, NOT_EQUAL,        // 60

    BIT_AND,                 // 50

    BIT_OR,                  // 40

    BIT_XOR,                 // 30

    LOG_AND,                 // 20

    LOG_OR,                  // 10


    // UNARY (ADDRESS_OF, VALUE_AT_ADDRESS)
    BIT_NOT,
    LOG_NOT,

    // SYMBOLS
    LEFT_PAREN, RIGHT_PAREN, RIGHT_BRACK,
    COMMA, LEFT_BRACE, RIGHT_BRACE, SEMI_COLON, 

    // LITERALS
    CHARACTER, INTEGER, LONG, FLOAT, DOUBLE, IDENTIFIER,
    STRING_LITERAL, NONE,

    // TYPES
    C8, I32, I64, F32, F64, STRING, VOID,

    // STATEMENTS
    FUNCTION, STRUCT, ASSIGN,
    IF, ELIF, ELSE, WHILE, RETURN,

    EOFF
};



struct token
{
    enum token_type type;
    int line;
    int start_idx;
    int end_idx;
    int lbp;
};


struct tokens
{
    struct token** tokens;
    int n_tokens;
    int capacity;

	int idx;
};

struct keyword_entry
{
    int occupied;
    enum token_type type;
    char* keyword;
};


void construct_keyword_table(struct keyword_entry* keyword_table);
struct tokens* lexical_analysis(char* src, long len);
int compute_hash(char* s_idx, int len);
void add_token(struct tokens* tokens, enum token_type type, int s_idx, int e_idx, int line, int lbp);
void read_token(struct tokens* tokens, struct keyword_entry* keyword_table, char* src, int* s_idx, int* e_idx, int* line);





#endif



