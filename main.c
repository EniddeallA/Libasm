#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "errno.h"

extern size_t	ft_strlen(char *str);
extern char		*ft_strcpy(char *dest, const char *src);
extern int		ft_strcmp(const char *s1, const char *s2);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern ssize_t	ft_read(int fd, void *buf, size_t count);
extern char		*ft_strdup(const char *s);

int		main(void)
{
	printf("\033[0;34m");
	printf("-------------------------------------");
	printf("\n");
	printf("-------------------------------------");
	printf("\n");

	printf("\033[0;35m");
	printf("FT_STRLEN : \n");
	printf("\033[0m");
	printf("[SYS: %lu] \t [_FT: %lu]\n", strlen("1"), ft_strlen("1"));
	printf("[SYS: %lu] \t [_FT: %lu]\n", strlen("-1"), ft_strlen("-1"));	
	printf("[SYS: %lu] \t [_FT: %lu]\n", strlen("abcdefghijklmnopqrstuvwxyz"), ft_strlen("abcdefghijklmnopqrstuvwxyz"));	
	printf("[SYS: %lu] \t [_FT: %lu]\n", strlen("0123456789"), ft_strlen("0123456789"));	

	printf("\033[0;34m");
	printf("-------------------------------------");
	printf("\n");
	printf("-------------------------------------");
	printf("\n");

	printf("\033[0;35m");
	printf("FT_STRCPY : \n");
	printf("\033[0m");
	char dest[100];
	char *src = "This is a test!";
	printf("[SYS: %s] \t [_FT: %s]\n", strcpy(dest, ""), ft_strcpy(dest, ""));
	printf("[SYS: %s] \t [_FT: %s]\n", strcpy(dest, "(null)"), ft_strcpy(dest, "(null)"));
	printf("[SYS: %s] \t [_FT: %s]\n", strcpy(dest, "abcdefghijklmnopqrstuvwxyz"), ft_strcpy(dest, "abcdefghijklmnopqrstuvwxyz"));
	printf("[SYS: %s] \t [_FT: %s]\n", strcpy(dest, "0123456789"), ft_strcpy(dest, "0123456789"));
	printf("[SYS: %s] \t [_FT: %s]\n", strcpy(dest, src), ft_strcpy(dest, src));

	printf("\033[0;34m");
	printf("-------------------------------------");
	printf("\n");
	printf("-------------------------------------");
	printf("\n");

	printf("\033[0;35m");
	printf("FT_STRCMP : \n");
	printf("\033[0m");
	printf("[SYS: %d] \t [_FT: %d]\n", strcmp("1", "2"), ft_strcmp("1", "2"));
	printf("[SYS: %d] \t [_FT: %d]\n", strcmp("-1", "1"), ft_strcmp("-1", "1"));	
	printf("[SYS: %d] \t [_FT: %d]\n", strcmp("allaeddine", "allaeddine"), ft_strcmp("allaeddine", "allaeddine"));	
	printf("[SYS: %d] \t [_FT: %d]\n", strcmp("allae", "allaeddine"), ft_strcmp("allae", "allaeddine"));
	printf("[SYS: %d] \t [_FT: %d]\n", strcmp("allaeddine", "allae"), ft_strcmp("allaeddine", "allae"));
	printf("[SYS: %d] \t [_FT: %d]\n", strcmp("\xfe", "\xfe\xff"), ft_strcmp("\xfe", "\xfe\xff"));
	printf("[SYS: %d] \t [_FT: %d]\n", strcmp("\xf", "\xfe"), ft_strcmp("\xf", "\xfe"));
	printf("\033[0;34m");
	printf("-------------------------------------");
	printf("\n");
	printf("-------------------------------------");
	printf("\n");

	printf("\033[0;35m");
	printf("FT_WRITE : \n");
	printf("\033[0m");
	char c = 'A';
	char *s = "allaeddine";
	printf("[SYS: %lu] \t [_FT: %lu]\n", write(1, "allaeddine\n", 12), ft_write(1, "allaeddine\n", 12));
	printf("[SYS: %lu] \t [_FT: %lu]\n", write(1, "allaeddine\n", 5), ft_write(1, "allaeddine\n", 5));	
	printf("[SYS: %lu] \t [_FT: %lu]\n", write(1, "allaeddine\n", 0), ft_write(1, "allaeddine\n", 0));	
	printf("[SYS: %lu] \t [_FT: %lu]\n", write(1, "allaeddine\n", 15), ft_write(1, "allaeddine\n", 15));
	printf("[SYS: %lu] \t [_FT: %lu]\n", write(1, &c, 1), ft_write(1, &c, 1));
	printf("[SYS: %lu] \t [_FT: %lu]\n", write(1, &s[0], 1), ft_write(1, &s[0], 1));

	printf("\033[0;34m");
	printf("-------------------------------------");
	printf("\n");
	printf("-------------------------------------");
	printf("\n");

	printf("\033[0;35m");
	printf("FT_READ : \n");
	printf("\033[0m");
	char ss[100];
	int fd;
	fd = open("README.md", O_RDONLY);
	printf("[_FT: %lu | %s]\n", ft_read(fd, ss, 12), ss);
	fd = open("README.md", O_RDONLY);
	printf("[SYS: %lu | %s]\n", read(fd, ss, 12), ss);
	fd = open("README.md", O_RDONLY);
	printf("[_FT: %lu | %s]\n", ft_read(fd, ss, 5), ss);	
	fd = open("README.md", O_RDONLY);
	printf("[SYS: %lu | %s]\n", read(fd, ss, 5), ss);
	fd = open("README.md", O_RDONLY);
	printf("[_FT: %lu | %s]\n", ft_read(fd, ss, 15), ss);
	fd = open("README.md", O_RDONLY);
	printf("[SYS: %lu | %s]\n", read(fd, ss, 15), ss);
	fd = open("README.md", O_RDONLY);
	printf("[_FT: %lu | %s]\n", ft_read(fd, ss, 1), ss);
	fd = open("README.md", O_RDONLY);
	printf("[SYS: %lu | %s]\n", read(fd, ss, 1), ss);
	fd = open("README.md", O_RDONLY);
	printf("[_FT: %lu | %s]\n", ft_read(fd, ss, 0), ss);
	fd = open("README.md", O_RDONLY);
	printf("[SYS: %lu | %s]\n", read(fd, ss, 0), ss);

	printf("\033[0;34m");
	printf("-------------------------------------");
	printf("\n");
	printf("-------------------------------------");
	printf("\n");

	printf("\033[0;35m");
	printf("FT_STRDUP : \n");
	printf("\033[0m");
	printf("[SYS: %s] \t [_FT: %s]\n", strdup("1"), ft_strdup("1"));
	printf("[SYS: %s] \t [_FT: %s]\n", strdup("-1"), ft_strdup("-1"));	
	printf("[SYS: %s] \t [_FT: %s]\n", strdup("abcdefghijklmnopqrstuvwxyz"), ft_strdup("abcdefghijklmnopqrstuvwxyz"));	
	printf("[SYS: %s] \t [_FT: %s]\n", strdup("0123456789"), ft_strdup("0123456789"));
	return (0);
}