#include "irc_udp.h"

static t_list_node * _lst_alloc_single_node(void) {
	t_list_node * node;

	if ((node = (t_list_node *) malloc(sizeof(t_list_node))) == NULL)
		return (NULL);

	node->data = NULL;
	node->next = NULL;
	return (node);
}

static t_bool _lst_free_next_then_connect(
  t_list_node * node,
  void(*        free_content)(void *)) {
	t_list_node * nn; // next next

	if (node == NULL || node->next == NULL)
		return (FALSE);

	nn = node->next->next;
	if (free_content != NULL)
		free_content(node->next->data);
	free(node->next);
	node->next = nn;
	return (TRUE);
}

t_list * lst_alloc(void(* freefptr)(void *), void(* printfptr)(void *, int)) {
	t_list * res;

	if (freefptr == NULL)
		return (NULL);

	if ((res = (t_list *) malloc(sizeof(t_list))) == NULL)
		return (NULL);

	res->len       = 0;
	res->head      = NULL;
	res->freefptr  = freefptr;
	res->printfptr = printfptr;
	return (res);
}

void    lst_free(t_list * lst) {
	if (lst == NULL)
		return;

	lst_clear(lst);
	free(lst);
}

void ** lst_toarray(t_list * lst) {
	void ** res;
	t_list_node * actu;

	if (lst == NULL)
		return (NULL);

	if ((res = malloc(sizeof(void *) * (lst->len + 1))) == NULL)
		return (NULL);

	actu = lst->head;
	for (size_t i = 0; i < lst->len; ++i) {
		res[i] = actu->data;
		actu   = actu->next;
	}
	res[lst->len] = NULL;
	return (res);
}

size_t  lst_size(t_list * lst) {
	if (lst == NULL)
		return (0);

	return (lst->len);
}

t_bool  lst_isempty(t_list * lst) {
	if (lst == NULL)
		return (FALSE);

	return (lst->len == 0);
}

void    lst_clear(t_list * lst) {
	t_list_node * actu;
	t_list_node * next;

	if (lst == NULL)
		return;

	actu = lst->head;
	while (actu) {
		next = actu->next;
		if (lst->freefptr != NULL)
			(lst->freefptr)(actu->data);
		free(actu);
		actu = next;
	}
	lst->len  = 0;
	lst->head = NULL;
}

void * lst_top(t_list * lst) {
	if (lst == NULL || lst->head == NULL)
		return (NULL);

	return (lst->head->data);
}

typedef struct s_tmp_print{
	void(* printfptr)(void *, int);
	int    fd;
	size_t remain;
}              t_tmp_print;

static void pretty_print_list(void * v, void * tmpp) {
	t_tmp_print * tmp;

	void(* fptr)(void *, int);

	tmp  = (t_tmp_print *) tmpp;
	fptr = PRINT_PTR(tmp->printfptr);
	dprintf(tmp->fd, "\t");
	fptr(v, tmp->fd);
	if (tmp->remain != 1)
		dprintf(tmp->fd, ",\n");
	tmp->remain--;
}

void    lst_print(t_list * lst, int fd) {
	t_tmp_print tmp;

	if (lst == NULL || lst->printfptr == NULL)
		return;

	if (lst_isempty(lst)) {
		dprintf(fd, "[]\n");
		return;
	}
	tmp.fd        = fd;
	tmp.printfptr = lst->printfptr;
	tmp.remain    = lst_size(lst);
	dprintf(fd, "[\n");
	lst_iterp(lst, pretty_print_list, &tmp);
	dprintf(fd, "]\n");
}

t_bool  lst_add(t_list * lst, void * data) {
	t_list_node * node;

	if (lst == NULL || data == NULL)
		return (FALSE);

	node = _lst_alloc_single_node();
	if (node == NULL)
		return (FALSE);

	node->data = data;
	node->next = lst->head;
	lst->head  = node;
	lst->len   = lst->len + 1;
	return (TRUE);
}

t_bool lst_pop(t_list * lst) {
	t_list_node * tmp;

	if (lst == NULL || lst->head == NULL)
		return (FALSE);

	tmp = lst->head->next;
	if (lst->freefptr != NULL)
		(lst->freefptr)(lst->head->data);
	free(lst->head);
	lst->head = tmp;
	lst->len  = lst->len - 1;
	return (TRUE);
}

void * lst_get(t_list * lst, int index) {
	t_list_node * tmp;

	if (index < 0 || (size_t) index >= lst->len)
		return (NULL);

	tmp = lst->head;
	while (index && tmp) {
		tmp = tmp->next;
		index--;
	}
	if (tmp == NULL) // impossible
		return (NULL);

	return (tmp->data);
}

/**
 * STRANGE CODE INCOMING !!
 * sensible soul to withhold
 */

#define	COND_PREDF(elem)  predf(elem)
#define	COND_PREDPF(elem) predpf(elem, p)
#define	ITER_PREDF(elem)  iterf(elem)
#define	ITER_PREDPF(elem) iterpf(elem, p)

/**
 *  The following 4 macros defines the four main applications of our structures.
 *  Because of details of implementation between lst_find and lst_findp
 *  for example. We have abstracted all of the implementation.
 *  We then let the compiler optimize the code.
 */

#define	REMOVE_ABSTRACT_CODE(lst, all, COND) \
	{ \
		t_list_node * prev; \
        \
		if (lst->head == NULL) { \
			return (FALSE); \
		} \
		while (COND((lst)->head->data)) { \
			if (lst_pop(lst) == FALSE) { \
				return (FALSE); \
			} \
			else if (all == FALSE) { \
				return (TRUE); \
			} \
			if ((lst)->head == NULL) { \
				return (TRUE); \
			} \
		} \
		prev = (lst)->head; \
		while (prev->next) { \
			if (COND(prev->next->data)) { \
				lst->len = lst->len - 1; \
				if (_lst_free_next_then_connect(prev, (lst)->freefptr) == FALSE) { \
					return (FALSE); \
				} \
				else if (all == FALSE) { \
					return (TRUE); \
				} \
			} \
			else { \
				prev = prev->next; \
			} \
		} \
		return (FALSE); \
	}

#define	FIND_ABSTRACT_CODE(lst, COND) \
	{ \
		t_list_node * actu; \
        \
		actu = lst->head; \
		while (actu) { \
			if (COND(actu->data)) { \
				return (actu->data); \
			} \
			actu = actu->next; \
		} \
		return (NULL); \
	}

#define	FIND_ALL_ABSTRACT_CODE(lst, COND) \
	{ \
		t_list * buff; \
		t_list_node * actu; \
		void ** res; \
        \
		buff = lst_alloc(NULL, lst->printfptr); \
		actu = lst->head; \
		while (actu) { \
			if (COND(actu->data)) { \
				lst_add(buff, actu->data); \
			} \
			actu = actu->next; \
		} \
		res = lst_toarray(buff); \
		lst_free(buff); \
		return (res); \
	}

#define	ITER_ABSTRACT_CODE(lst, ITER) \
	{ \
		t_list_node * actu; \
        \
		actu = lst->head; \
		while (actu) { \
			ITER(actu->data); \
			actu = actu->next; \
		} \
	}

t_bool  lst_remove_if(t_list * lst, t_predf predf) {
	if (lst == NULL || predf == NULL)
		return (FALSE);

	REMOVE_ABSTRACT_CODE(lst, FALSE, COND_PREDF)
}

t_bool  lst_remove_ifp(t_list * lst, t_predpf predpf, void * p) {
	if (lst == NULL || predpf == NULL || p == NULL)
		return (FALSE);

	REMOVE_ABSTRACT_CODE(lst, FALSE, COND_PREDPF)
}

t_bool  lst_removeall_if(t_list * lst, t_predf predf) {
	if (lst == NULL || predf == NULL)
		return (FALSE);

	REMOVE_ABSTRACT_CODE(lst, TRUE, COND_PREDF);
}

t_bool  lst_removeall_ifp(t_list * lst, t_predpf predpf, void * p) {
	if (lst == NULL || predpf == NULL || p == NULL)
		return (FALSE);

	REMOVE_ABSTRACT_CODE(lst, TRUE, COND_PREDPF)
}

void * lst_find(t_list * lst, t_predf predf) {
	if (lst == NULL || predf == NULL)
		return (NULL);

	FIND_ABSTRACT_CODE(lst, COND_PREDF);
}

void * lst_findp(t_list * lst, t_predpf predpf, void * p) {
	if (lst == NULL || predpf == NULL || p == NULL)
		return (NULL);

	FIND_ABSTRACT_CODE(lst, COND_PREDPF);
}

void ** lst_allfind(t_list * lst, t_predf predf) {
	if (lst == NULL || predf == NULL)
		return (NULL);

	FIND_ALL_ABSTRACT_CODE(lst, COND_PREDF)
}

void ** lst_allfindp(t_list * lst, t_predpf predpf, void * p) {
	if (lst == NULL || predpf == NULL || p == NULL)
		return (NULL);

	FIND_ALL_ABSTRACT_CODE(lst, COND_PREDPF);
}

void    lst_iter(t_list * lst, t_iterf iterf) {
	if (lst == NULL || iterf == NULL)
		return;

	ITER_ABSTRACT_CODE(lst, ITER_PREDF)
}

void    lst_iterp(t_list * lst, t_iterpf iterpf, void * p) {
	if (lst == NULL || iterpf == NULL || p == NULL)
		return;

	ITER_ABSTRACT_CODE(lst, ITER_PREDPF)
}

#undef FIND_ABSTRACT_CODE
#undef FIND_ALL_ABSTRACT_CODE
#undef REMOVE_ABSTRACT_CODE
#undef ITER_ABSTRACT_CODE

#undef COND_PREDF
#undef COND_PREDPF
#undef ITER_PREDF
#undef ITER_PREDPF
