# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 18:24:18 by juhallyn          #+#    #+#              #
#    Updated: 2017/10/05 14:19:58 by juhallyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_Colors_#

GREEN	=	echo "\x1b[32m $1 \x1b[0m $2"

PURPLE	=	echo "\x1b[35m $1 \x1b[0m $2"

#_Files_#

NAME	=	minishell

SRC 	=	env.c			\
			error.c			\
			exec.c			\
			main.c			\
			process.c		\
			tools.c			\
			tools2.c		\
			builtins.c		\
			cd.c			\
			echo.c			\
			setenv.c		\
			unsetenv.c		\

OBJS		=	$(SRC:.c=.o)

LIB			=	libft/
INC			=	Includes/
OBJS_DIR	=	objs/
SRCS_DIR	=	srcs/
SRCS_LIST	=	$(addprefix $(SRCS_DIR), $(SRC))
OBJS_LIST	=	$(addprefix $(OBJS_DIR), $(OBJS))

#_Compilation_#

FLAG 	=	-Wall -Wextra -Werror

all: $(NAME)

norm:
	@clear
	@norminette $(SRC)

#_Compilation_#

$(NAME):
	make -C $(LIB)
	gcc $(FLAG) -c $(SRCS_LIST) -I $(INC)
	mkdir -p $(OBJS_DIR)
	mv $(OBJS) $(OBJS_DIR)
	gcc $(FLAG) $(OBJS_LIST) -I $(INC) $(LIB)libft.a -o $(NAME)

clean:
	rm -f $(OBJS_LIST)
	@(cd $(LIB) && $(MAKE) $@)

fclean: clean
	make fclean -C $(LIB)
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: fclean all
