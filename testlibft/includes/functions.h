#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "s_answer.h"

# define TEST_PASSED 42
# define TEST_FAILED 0

void				test_partie1(void);
void				test_partie2(void);

// PARTIE 1

void 				test_mem(void);
void 				test_str(void);
void 				test_is_to(void);

void				test_ft_strlen(void);
void				test_ft_isalpha(void);
void				test_ft_isdigit(void);
void				test_ft_isalnum(void);
void				test_ft_isascii(void);
void				test_ft_isprint(void);
void				test_ft_toupper(void);
void				test_ft_tolower(void);

void				do_testchr1(t_answer *ans,
						int (*function_test)(int),
						int (*function_real)(int),
						void (*test)(t_answer *, int (*)(int), int (*)(int), int c));

// PARTIE 2

void 				test_mem2(void);
void 				test_str2(void);
void 				test_put(void);

void				do_test(void (*f1)(void), void (*f2)(void), void (*f3)(void));
void				test_passed(char *function_name);
void				test_failed(char *function_name);
void				test_notimplemented(char *function_name);

#endif