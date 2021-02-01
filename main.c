#include <stdio.h>
#include <string.h>

void *
ft_memcpy (void *dest, const void *src, size_t len)
{
  char *d = dest;
  const char *s = src;
  while (len--)
    *d++ = *s++;
  return dest;
}


extern size_t ft_strlen(char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);

int main()
{
    printf("%d\n", strcmp("hello", "hello"));
    printf("%d", ft_strcmp("hello", "hello"));
}