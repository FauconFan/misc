#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# define TEST_PASSED 42
# define TEST_FAILED 0

void	test_partie1(void);
void	test_partie2(void);

// PARTIE 1

void 	test_mem(void);
void 	test_str(void);
void 	test_is_to(void);

// PARTIE 2

void 	test_mem2(void);
void 	test_str2(void);
void 	test_put(void);

void	do_test(void (*f1)(void), void (*f2)(void), void (*f3)(void));
void	test_passed(char *function_name);
void	test_failed(char *function_name);
void	test_notimplemented(char *function_name);

#endif