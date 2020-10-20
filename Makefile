# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbroccol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 13:22:23 by gbroccol          #+#    #+#              #
#    Updated: 2020/10/15 13:22:25 by gbroccol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS			= $(shell uname)

NAME		= libasm.a

ASM			= nasm

ifeq ($(OS), Linux)
			FLAGS = -f elf64
else
			FLAGS = -f macho64
endif

ARRC		= ar -rcs

GCC			= clang
GCCFLAGS	= -Wall -Wextra -Werror

SRC = \
			ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s

OBJ			= $(SRC:.s=.o)

%.o : %.s
	@$(ASM) $(FLAGS) -s $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(ARRC) $(NAME) $(OBJ)
	ranlib libasm.a

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out

re: fclean all

test: re
	$(GCC) $(GCCFLAGS) main.c -L. -lasm
	./a.out

.PHONY: all clean fclean re

