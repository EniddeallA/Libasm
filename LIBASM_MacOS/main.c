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

extern size_t	ft_strlen(char *str);
extern char		*ft_strcpy(char *dest, const char *src);
extern int		ft_strcmp(const char *s1, const char *s2);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern ssize_t	ft_read(int fd, void *buf, size_t count);
extern char		*ft_strdup(const char *s);
extern int		ft_atoi_base(char *str, char *base);
extern void		ft_list_push_front(t_list **begin_list, void *data);
extern int		ft_list_size(t_list *begin_list);
extern void		ft_list_sort(t_list **begin_list, int (*cmp)());
extern void		ft_list_remove_if(t_list **begin_list, void *data_ref, 
						int (*cmp)(), void (*free_fct)(void *));


// void		ft_list_push_front(t_list **begin_list, void *data)
// {
// 	t_list *new = (t_list*)malloc(sizeof(t_list));
// 	new->data = data;
// 	new->next = *begin_list;
// 	*begin_list = new;
// }

// int ft_list_size(t_list *begin_list)
// {
// 	int i = 0;

// 	while (begin_list)
// 	{
// 		i++;
// 		begin_list = begin_list->next;
// 	}
// 	return (i);
// }

// void ft_list_sort(t_list **begin_list, int (*cmp)())
// {
// 	t_list *temp1 = *begin_list;
// 	t_list *temp2 = NULL;
// 	while (temp1)
// 	{
// 		temp2 = temp1->next;
// 		while (temp2)
// 		{
// 			if ((*cmp)(temp1->data, temp2->data) == 1)
// 			{
// 				void *a;
// 				a = temp1->data;
// 				temp1->data = temp2->data;
// 				temp2->data = a;
// 			}
// 			temp2 = temp2->next;
// 		}
// 		temp1 = temp1->next;
// 	}
// }

// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
// {
// 	t_list *temp = *begin_list;
// 	t_list *prev = NULL;
// 	if (temp && !(*cmp)(temp->data, data_ref))
// 	{
// 		*begin_list = temp->next;
// 		free_fct(temp->data);
// 		free(temp);
// 	}
// 	while (temp)
// 	{
// 		if (!(*cmp)(temp->data, data_ref))
// 		{
// 			prev = temp->next;
// 			free_fct(temp->data);
// 			free(temp);
// 		}
// 		temp = temp->next;
// 	}	
// }


int main()
{
	// if ((ft_read(-1, line, 9) == -1))
	// 	printf("\033[1;31mERROR: %s\033[0m\n", strerror(errno));
	t_list *t = (t_list*)malloc(sizeof(t_list));
	t->data = strdup("test");
	t->next = NULL;
	ft_list_push_front(&t, strdup(", wtsp!"));
	ft_list_push_front(&t, strdup(", world"));
	ft_list_push_front(&t, strdup("hello"));
	printf("List size : %d\n", ft_list_size(t));
	
	ft_list_sort(&t, &strcmp);
	// // // printf("After sort:\n");
	// // ft_list_remove_if(&t, "hello", &strcmp, &free);
	while (t)
	{
		printf("%s\n", (char *)t->data);
		t = t->next;
	}

	//gcc -fno-asynchronous-unwind-tables -O2 -s -c -o main.o main.c
	//./objconv -fnasm main.o

	return (0);
}