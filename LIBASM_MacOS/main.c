#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdlib.h"

extern size_t ft_strlen(char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);

int main()
{
	char line[8];
	char line1[8];
	int fd = open("Makefile", O_RDONLY);
	printf(" %ld - %s\n", read(fd,line, 8), line);
	printf(" %ld - %s\n", ft_read(fd,line, 8), line1);

	return (0);
}