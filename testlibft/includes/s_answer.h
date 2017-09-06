#ifndef S_ANSWER
# define S_ANSWER

typedef	struct 		s_answer
{
	char			*function_name;
	int				nb_test;
	int				is_test_passed;
}					t_answer;

t_answer	*init_answer(char *function_name);
void		ans_success(t_answer *ans);
void		ans_failed(t_answer *ans);
void		print_n_free_result(t_answer *ans);

#endif