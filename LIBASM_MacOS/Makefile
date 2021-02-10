CC = gcc

NASM = nasm -f macho64

RM = rm -rf

LIB = libasm.a

SRCS =	main.c

MAIN = main.o

OBJS = -Wall -Wextra -Werror

all: $(LIB)

$(LIB): $(SRCS)
	$(NASM) ft_strlen.s
	$(NASM) ft_strcpy.s
	$(NASM) ft_strcmp.s
	$(NASM) ft_write.s
	$(NASM) ft_read.s
	$(NASM) ft_strdup.s
	$(NASM) ft_atoi_base_bonus.s
	$(CC) $(OBJS) -c $(SRCS) -o $(MAIN)
	ar rc $(LIB) *.o
	ranlib $(LIB)
	$(CC) $(OBJS) $(MAIN) $(LIB)

clean: 
		$(RM) *.o

fclean: clean
		$(RM) a.out
		$(RM) $(LIB)

re: fclean all

.PHONY: all clean fclean re