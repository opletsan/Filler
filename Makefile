# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opletsan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/17 21:36:02 by opletsan          #+#    #+#              #
#    Updated: 2018/09/10 17:20:56 by opletsan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	opletsan.filler
VNAME		=	visualize

SRC_DIR		=	./src/
OBJ_DIR		=	./obj/
INC_DIR		=	./inc/ ./printf/inc ./libft/inc
LIB_DIR		=	./libft/ ./printf/
VIS_DIR		=	./visualization/

LFT			=	./libft/libft.a
LPRINTF		=	./printf/libftprintf.a
HEADER		=	./inc/filler.h
SRC 		=   main.c \
				init_map.c \
				init_piece.c \
				algorithm.c
OBJ			=	$(addprefix $(OBJ_DIR),$(SRC:.c=.o))
VSRC		=	$(VIS_DIR)visualization.c
VOBJ		=	$(VIS_DIR)visualization.o

LIB			=	$(addprefix -L,$(LIB_DIR))
INC			=	$(addprefix -I,$(INC_DIR))
MK_LFT		=	-C ./libft/
MK_LPRINTF	=	-C ./printf/

CFLAGS		=	-Wall -Werror -Wextra
LFLAGS		=	-lft -lftprintf

TG			=	"\033[32m"
TR			=	"\033[31m"
TU			=	"\033[4m"
EOC			=	"\033[0m"

all: $(NAME) $(VNAME)

$(NAME): $(LFT) $(LPRINTF) $(OBJ)
	@gcc $(LFLAGS) $(LIB) $(OBJ) -o $@
	@echo ${TG}"[✓] "${TU}"$@"${EOC}

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $@

$(OBJ_DIR)%.o: %.c $(HEADER)
	@gcc $(CFLAGS) $(INC) -c $< -o $@
	@echo ${TG}"[✓] $<"${EOC}

$(LFT):
	@make $(MK_LFT)

$(LPRINTF):
	@make $(MK_LPRINTF)

$(VNAME): $(VOBJ)
	@gcc $(LFLAGS) $(LIB) $(VOBJ) -o $@
	@echo ${TG}"[✓] "${TU}"$@"${EOC}

$(VOBJ):$(VSRC)
	@gcc $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make clean $(MK_LFT)
	@make clean $(MK_LPRINTF)
	@rm -f $(OBJ)
	@echo ${TR}"[✗] $(OBJ)"${EOC}
	@rm -f $(VOBJ)
	@echo ${TR}"[✗] $(VOBJ)"${EOC}

fclean: clean
	@make fclean $(MK_LFT)
	@make fclean $(MK_LPRINTF)
	@rm -f $(NAME)
	@echo ${TR}"[✗] "${TU}"$(NAME)"${EOC}
	@rm -f $(VNAME)
	@echo ${TR}"[✗] "${TU}"$(VNAME)"${EOC}
	@rm -rf $(OBJ_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all fclean clean re
