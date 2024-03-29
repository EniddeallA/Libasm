# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 14:11:37 by akhalid           #+#    #+#              #
#    Updated: 2021/06/16 14:42:24 by akhalid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRC		=	ft_strlen.s \
				ft_strcmp.s \
				ft_strcpy.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s

SDIR = ./mandatory/

SRCS =	$(addprefix $(SDIR), $(SRC))

OBJS		=	$(SRCS:.s=.o)

BONUS_SRC	=	ft_atoi_base_bonus.s \
				ft_list_size_bonus.s \
				ft_list_push_front_bonus.s \
				ft_list_remove_if_bonus.s \
				ft_list_sort_bonus.s

BDIR = ./bonus/

BONUS_SRCS	=	$(addprefix $(BDIR), $(BONUS_SRC))

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

bonus:			$(BONUS_OBJS)
				ar rcs $(NAME) $(BONUS_OBJS)

.PHONY:			clean fclean re bonus