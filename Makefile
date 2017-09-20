# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 18:24:18 by juhallyn          #+#    #+#              #
#    Updated: 2017/09/20 18:26:55 by juhallyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_Colors_#

GREEN	=	echo "\x1b[32m $1 \x1b[0m $2"

PURPLE	=	echo "\x1b[35m $1 \x1b[0m $2"

#_Files_#

NAME	=	minishell

SRC 	=	env.c					\
			error.c					\
			exec.c					\
			main.c					\
			process.c				\
			tools.c					\
			tools2.c				\
			builtins/builtins.c		\
			builtins/cd.c			\
			builtins/echo.c			\
			builtins/setenv.c		\
			builtins/unsetenv.c		\

LIB		=	libft/
INC		=	Includes/

#_Compilation_#

FLAG 	=	-Wall -Wextra #-Werror

all: $(NAME)

norm:
	@clear
	@norminette $(SRC)

#_Compilation_#

$(NAME):
	make -C $(LIB)
	@gcc $(FLAG) $(SRC) -I $(INC) $(LIB)libft.a -o $(NAME)

clean:
	@rm -f $(OBJ)
	@(cd $(LIB) && $(MAKE) $@)

fclean:
	make fclean -C $(LIB)
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: fclean all
