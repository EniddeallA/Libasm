#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdlib.h"
#include "errno.h"

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

extern int		ft_atoi_base(char *str, char *base);
extern void		ft_list_push_front(t_list **begin_list, void *data);
extern int		ft_list_size(t_list *begin_list);
extern void		ft_list_sort(t_list **begin_list, int (*cmp)());
extern void		ft_list_remove_if(t_list **begin_list, void *data_ref, 
						int (*cmp)(), void (*free_fct)(void *));

int main()
{
	t_list *t = (t_list*)malloc(sizeof(t_list));
	t->data = strdup("test");
	t->next = NULL;
	ft_list_push_front(&t, strdup(", wtsp!"));
	ft_list_push_front(&t, strdup(", world"));
	ft_list_push_front(&t, strdup("hello"));
	printf("List size : %d\n", ft_list_size(t));
	printf("\nBefore sort:\n");
	t_list *t2 = t;
	while (t2)
	{
		printf("%s\n", (char *)t2->data);
		t2 = t2->next;
	}

	ft_list_sort(&t, &strcmp);
	printf("\nAfter sort:\n");
	t_list *t1 = t;
	while (t)
	{
		printf("%s\n", (char *)t->data);
		t = t->next;
	}

	ft_list_remove_if(&t1, "test", &strcmp, &free);
	printf("\nremoved node containing : 'hello':\n");
	while (t1)
	{
		printf("%s\n", (char *)t1->data);
		t1 = t1->next;
	}
    
	return (0);
}