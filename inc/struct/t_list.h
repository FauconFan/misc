#ifndef T_LIST_H
#define T_LIST_H

#include "irc_udp.h"

/**
 *  t_list is a simple linked list that contains abstract data (void *)
 *  there are a lot of functions related to it to provide a high api.
 */

/**
 *  Internal structure that represents a simple node in the list.
 */
typedef struct  s_list_node {
    void                *data; // The given data
    struct s_list_node  *next; // Pointer to next element.
}               t_list_node;

/**
 *  The main structure.
 *  The freef function is the function to free resources allocated for data in node.
 */
typedef struct  s_list {
    size_t      len; // Len of the list
    t_list_node *head; // Head of the list
    void        (*freefptr)(void *); // Free function to elements
    void        (*printfptr)(void *, int); // Print function to elements
}               t_list;

/**
 *  We define 4 typedef that represent respectivelly:
 *  - a predicate t_predf that takes just the data.
 *  - a predicate t_predpf that takes a data plus an extra parameter.
 *  - a function t_iterf that takes a data.
 *  - a function t_iterpf that takes a data plus an extra parameter.
 *
 *  the iterf function receive the real data (not a copy).
 *  so you can modify the data in the function given.
 */
typedef t_bool  (*t_predf)(void *);
typedef t_bool  (*t_predpf)(void *, void *);
typedef void    (*t_iterf)(void *);
typedef void    (*t_iterpf)(void *, void *);

// Return a new structure
// The free function of the given elements must be given in the alloc function
// The free function can be null, and none of the elements are freed at the end.
t_list  *lst_alloc(void (*freefptr)(void *), void (*printfptr)(void *, int));

// Free a list and all elements in the list using the freef function.
void    lst_free(t_list * lst);

// Transform a list into array of the data in it.
// The array returned is (lst->len + 1) length.
// The last element is set to NULL
// The data in the array itself is not copied
// so you have to free the allocated array,
// without freeing its elements.
void    **lst_toarray(t_list * lst);

// Return the size of the list.
size_t  lst_size(t_list * lst);

// Return if the list is empty.
t_bool  lst_isempty(t_list * lst);

// Print the list
void    lst_print(t_list * lst, int fd);

// Return a pointer to the first element in the list.
void    *lst_top(t_list * lst);

// Adding an element on top of the list.
t_bool  lst_add(t_list * lst, void * data);

// Pop the first element
t_bool  lst_pop(t_list * lst);

// Remove the first element that satisfy the predicate
// the last p stands for an extra parameter
t_bool  lst_remove_if(t_list * lst, t_predf predf);
t_bool  lst_remove_ifp(t_list * lst, t_predpf predpf, void * p);

// Remove all elements that satisfy the predicate
// the last p stands for an extra parameter
t_bool  lst_removeall_if(t_list * lst, t_predf predf);
t_bool  lst_removeall_ifp(t_list * lst, t_predpf predpf, void * p);

// Return the first element that satisfy the predicate
// the last p stands for an extra parameter
void    *lst_find(t_list * lst, t_predf predf);
void    *lst_findp(t_list * lst, t_predpf predpf, void * p);

// Return an allocated array of all elements that satisfy the predicate
// The array returned is the same kind of array of lst_toarray
// the last p stands for an extra parameter
void    **lst_allfind(t_list * lst, t_predf predf);
void    **lst_allfindp(t_list * lst, t_predpf predpf, void * p);

// Loop over all elements and executing the iterf function
// the last p stands for an extra parameter
void    lst_iter(t_list * lst, t_iterf iterf);
void    lst_iterp(t_list * lst, t_iterpf iterpf, void * p);

#endif
