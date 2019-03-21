#include "cimp.h"

static  t_token     *token_alloc(t_type_token type_token) {
    t_token     *tok;

    if ((tok = malloc(sizeof(t_token))) == NULL) {
        printf("%s\n", MALLOC_FAIL);
        return (NULL);
    }
    memset(tok, 0, sizeof(t_token));
    tok->type = type_token;
    return (tok);
}

void                print_token(t_token * tok) {
    if (tok == NULL)
        return ;
    switch (tok->type)
    {
        case NUM:
            printf("NUM(%ld)\n", tok->u.num);
            break;
        case WORD:
            printf("WORD(%s)\n", tok->u.str);
            break;
        case PATH:
            printf("PATH(%s)\n", tok->u.str);
            break;
    }
}

t_token             *token_word(const char * word) {
    t_token     *tok;

    if ((tok = token_alloc(WORD)) == NULL)
        return (NULL);
    tok->u.str = dupstr(word);
    return (tok);
}

t_token             *token_path(const char * word) {
    t_token     *tok;

    if ((tok = token_alloc(PATH)) == NULL)
        return (NULL);
    tok->u.str = dupstr(word);
    return (tok);
}

t_token             *token_num(const char * word) {
    t_token     *tok;

    if ((tok = token_alloc(NUM)) == NULL)
        return (NULL);
    errno = 0;
    tok->u.num = strtol(word, NULL, 10);
    if (errno == EINVAL || errno == ERANGE) {
        printf("No suitable conversion...\n");
        free(tok);
        return (NULL);
    }
    return (tok);
}

// t_bool              eat_word_token(char ** word) {
//     if (word == NULL || g_li_token == NULL)
//         return (FALSE);
    
// }