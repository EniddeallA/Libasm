#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

extern void		ft_list_push_front(t_list **begin_list, void *data);
extern void		ft_list_sort(t_list **begin_list, int (*cmp)());
extern void		ft_list_remove_if(t_list **begin_list, void *data_ref, 
						int (*cmp)(), void (*free_fct)(void *));

int main()
{
    t_list *t = NULL;

    ft_list_push_front(&t, strdup("1"));
    ft_list_push_front(&t, strdup(""));
    ft_list_push_front(&t, strdup("4"));
    ft_list_push_front(&t, strdup("5"));

    ft_list_remove_if(&t, 0, &strcmp, &free);
    // ft_list_sort(&t, &strcmp);
    while (t)
    {
        printf("%s\n", t->data);
        t = t->next;
    }
    return (0);
}