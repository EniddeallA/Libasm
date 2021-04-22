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

// void		ft_list_sort(t_list **begin_list, int (*cmp)())
// {
// 	t_list *list;
// 	t_list *next;
// 	char *a;

// 	list = *begin_list;
// 	while (list->next)
// 	{
// 		next = list->next;
// 		while (next->next)
// 		{
// 			if (cmp(list->data, next->data) == 0)
// 			{
// 				a = list->data;
// 				list->data = next->data;
// 				next->data = a;
// 			}
// 			next = next->next;
// 		}
// 		list = list->next;
// 	}
// }

int main()
{
	// printf("\033[0;34m");
	// printf("-------------------------------------");
	// printf("\n");
	// printf("-------------------------------------");
	// printf("\n");

	// printf("\033[0;35m");
	// printf("FT_ATOI_BASE : \n");
	// printf("\033[0m");

 	printf("[_FT: %d]\n", ft_atoi_base("--2147483648", "0123456789"));
	printf("[_FT: %d]\n", ft_atoi_base("0", "0123456789"));
	printf("[_FT: %d]\n", ft_atoi_base("1", "0123456789"));
	printf("[_FT: %d]\n", ft_atoi_base("-42", "0123456789"));
	printf("[_FT: %d]\n", ft_atoi_base("2147483648", "0123456789"));
	printf("[_FT: %d]\n", ft_atoi_base("-2147483648", "0123456789"));
	printf("[_FT: %d]\n", ft_atoi_base("poney", "poney"));

	// t_list *t = NULL;
	// printf("\033[0;34m");
	// printf("-------------------------------------");
	// printf("\n");
	// printf("-------------------------------------");
	// printf("\n");

	// printf("\033[0;35m");
	// printf("FT_LIST_PUSH_FRONT : \n");
	// printf("\033[0m");
	// ft_list_push_front(&t, strdup("milk"));
	// ft_list_push_front(&t, strdup("bread"));
	// ft_list_push_front(&t, strdup("milk"));
	// ft_list_push_front(&t, strdup("apple"));
	// ft_list_push_front(&t, strdup("ZEBRA"));
	// ft_list_push_front(&t, strdup("tomato"));
	// ft_list_push_front(&t, strdup("milk"));


	// printf("\033[0;34m");
	// printf("-------------------------------------");
	// printf("\n");
	// printf("-------------------------------------");
	// printf("\n");

	// printf("\033[0;35m");
	// printf("FT_LIST_SIZE : \n");
	// printf("\033[0m");
	// printf("List size : %d\n", ft_list_size(t));

	// printf("\033[0;34m");
	// printf("-------------------------------------");
	// printf("\n");
	// printf("-------------------------------------");
	// printf("\n");

	// printf("\033[0;34m");
	// printf("\nBefore sort:\n");
	// printf("\033[0m");
	// t_list *t2 = t;
	// while (t2)
	// {
	// 	printf("%s\n", (char *)t2->data);
	// 	t2 = t2->next;
	// }

	// printf("\n");
	
	// printf("\033[0;34m");
	// printf("--- EXPECTED RESULT ---");
	// printf("\n");
	// printf("\033[0m");
	// printf("ZEBRA\n");
	// printf("apple\n");
	// printf("bread\n");
	// printf("milk\n");
	// printf("milk\n");
	// printf("milk\n");
	// printf("tomato\n");
	// printf("\n");

	// printf("\033[0;35m");
	// printf("FT_LIST_SORT : \n");
	// printf("\033[0m");
	// ft_list_sort(&t, &strcmp);
	// printf("\033[0;34m");
	// printf("\nAfter sort:\n");
	// printf("\033[0m");
	// t_list *t1 = t;
	// while (t)
	// {
	// 	printf("%s\n", (char *)t->data);
	// 	t = t->next;
	// }
	// printf("\033[0;34m");
	// printf("-------------------------------------");
	// printf("\n");
	// printf("-------------------------------------");
	// printf("\n");

	// printf("\033[0;35m");
	// printf("FT_LIST_REMOVE_IF : \n");
	// printf("\033[0m");
	// ft_list_remove_if(&t1, "test", &strcmp, &free);
	// printf("\033[0;34m");
	// printf("\nremoved node containing : 'test':\n");
	// printf("\033[0m");
	// while (t1)
	// {
	// 	printf("%s\n", (char *)t1->data);
	// 	t1 = t1->next;
	// }
    
	return (0);
}