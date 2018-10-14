# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opletsan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 21:05:25 by opletsan          #+#    #+#              #
#    Updated: 2017/11/15 21:10:52 by opletsan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libft.a

SRC_DIR		=	./src/
OBJ_DIR		=	./obj/
INC_DIR		=	./inc/

HEADER		=	$(INC_DIR)libft.h

SRC 		=	ft_itoa.c \
				ft_memcpy.c \
				ft_putstr.c \
				ft_striter.c \
				ft_strnstr.c \
				ft_lstadd.c \
				ft_memdel.c \
				ft_putstr_fd.c \
				ft_striteri.c \
				ft_strrchr.c \
				ft_lstdel.c \
				ft_memmove.c \
				ft_range.c \
				ft_strjoin.c \
				ft_strrev.c \
				ft_abs.c \
				ft_lstdelone.c \
				ft_memset.c \
				ft_sqrt.c \
				ft_strlcat.c \
				ft_strsplit.c \
				ft_atoi.c \
				ft_lstfree.c \
				ft_numlen.c	\
				ft_strcat.c \
				ft_strlen.c \
				ft_strstr.c \
				ft_bzero.c \
				ft_lstiter.c \
				ft_power.c \
				ft_strchr.c \
				ft_strmap.c \
				ft_strsub.c \
				ft_isalnum.c \
				ft_lstmap.c \
				ft_putchar.c \
				ft_strclr.c \
				ft_strmapi.c \
				ft_strtrim.c \
				ft_isalpha.c \
				ft_lstnew.c \
				ft_putchar_fd.c \
				ft_strcmp.c \
				ft_strncat.c \
				ft_tolower.c \
				ft_isascii.c \
				ft_memalloc.c \
				ft_putendl.c \
				ft_strcpy.c \
				ft_strncmp.c \
				ft_toupper.c \
				ft_isdigit.c \
				ft_memccpy.c \
				ft_putendl_fd.c \
				ft_strdel.c \
				ft_strncpy.c \
				ft_isprime.c \
				ft_memchr.c \
				ft_putnbr.c \
				ft_strdup.c \
				ft_strnequ.c \
				ft_isprint.c \
				ft_memcmp.c \
				ft_putnbr_fd.c \
				ft_strequ.c \
				ft_free.c \
				ft_strnew.c \
				ft_itoa_base.c \
				ft_powerf.c \
				ft_sqrtf.c \
				ft_puthex.c \
				get_next_line.c

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

FLAGS		=	-Wall -Werror -Wextra
HEAD_FLAGS	=	-I $(INC_DIR)

TG			=	"\033[32m"
TR			=	"\033[31m"
TU			=	"\033[4m"
EOC			=	"\033[0m"

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $(OBJ)
	@ranlib $@
	@echo ${TG}"[✓] "${TU}"$@"${EOC}

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $@

$(OBJ_DIR)%.o: %.c $(HEADER)
	@gcc $(FLAGS) $(HEAD_FLAGS) -c $< -o $@
	@echo ${TG}"[✓] $<"${EOC}

clean:
	@rm -f $(OBJ)
	@echo ${TR}"[✗] $(OBJ)"${EOC}

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo ${TR}"[✗] "${TU}"$(NAME)"${EOC}

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all fclean clean re
