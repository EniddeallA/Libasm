#include "stdio.h"

extern size_t ft_strlen(char *str);

int main()
{
    printf("%ld", ft_strlen("Hello world"));
    return 0;
}