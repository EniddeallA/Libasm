# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 14:11:37 by akhalid           #+#    #+#              #
#    Updated: 2021/04/22 08:17:50 by akhalid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_strlen.s \
				ft_strcmp.s \
				ft_strcpy.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s

OBJS		=	$(SRCS:.s=.o)

BONUS_SRCS	=	ft_atoi_base_bonus.s \
				ft_list_size_bonus.s \
				ft_list_push_front_bonus.s \
				ft_list_remove_if_bonus.s \
				ft_list_sort_bonus.s
				
BONUS_OBJS	=	$(BONUS_SRCS:.s=.o)

NASM			=	nasm
NASM_FLAGS	=	-f macho64
FLAGS 		=	-Wall -Werror -Wextra
NAME		=	libasm.a
TEST		=	test
TEST_BONUS	=	test_bonus

%.o:			%.s
				$(NASM) $(NASM_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				rm -rf $(OBJS) $(BONUS_OBJS)

fclean:			clean
				rm -rf $(NAME) $(BONUS) $(TEST) $(TEST_BONUS)

re:				fclean $(NAME)

test:			$(NAME)
				gcc $(FLAGS) -o $(TEST) main.c
				./$(TEST) < Makefile

bonus:			$(BONUS_OBJS)
				ar rcs $(NAME) $(BONUS_OBJS)

test_bonus:		bonus
				gcc $(FLAGS) -o $(TEST_BONUS) main_bonus.c
				./$(TEST_BONUS)

.PHONY:			clean fclean re test bonus test_bonus