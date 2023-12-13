NAME = push_swap
LIBS = ./libftprintf/libftprintf.a  ./libftprintf/libft/libft.a
SRC_FILES =	main.c \
			utils.c 

SRC_DIR = srcs/
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = ${SRCS:.c=.o}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -Iincludes -I. -Ilibftprintf
RM = rm -rf

all:	$(NAME)

$(NAME) : $(OBJS)
		@make -C libftprintf
		@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) ${INCLUDE}
		@printf "\033[0;32mpush_swap succesfully compiled!\n\e[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ ${INCLUDE}

clean :
		@make clean -C libftprintf
		@${RM} ${OBJS}

fclean : clean
		@make fclean -C libftprintf
		@${RM} $(NAME)
		@printf "\033[0;31m Succesfully cleaned the project!\n\e[0m"

re : fclean all

.PHONY:		all bonus clean fclean re