M_NAME = push_swap
B_NAME = checker
LIBS = ./libft/libft.a
M_SRC_FILES =	main.c \
			actions.c \
			error_free_init.c \
			sort_stack.c \
			utils.c \

B_SRCS_FILES = 	main.c \
				actions.c \
				error_free_init.c \
				utils.c \

SRC_DIR = srcs/push_swap/
BONUS_DIR = srcs/checker_bonus/
M_SRCS = $(addprefix $(SRC_DIR), $(M_SRC_FILES))
B_SRCS = $(addprefix $(BONUS_DIR), $(B_SRCS_FILES))
M_OBJS = ${M_SRCS:.c=.o}
B_OBJS = ${B_SRCS:.c=.o}
CC			= cc
CFLAGS		= -g -Wall -Werror -Wextra
INCLUDE = -I./includes -I. -Ilibft 
RM = rm -rf

all:	$(M_NAME)

$(M_NAME) : $(M_OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(M_OBJS) $(LIBS) -o $(M_NAME) ${INCLUDE}
	@printf "\033[0;32mpush_swap succesfully compiled!\n\e[0m"

bonus : $(B_NAME)

$(B_NAME) : $(B_OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(B_OBJS) $(LIBS) -o $(B_NAME) ${INCLUDE}
	@printf "\033[0;32m Checker succesfully compiled!\n\e[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ ${INCLUDE}

clean :
		@make clean -C libft
		@${RM} ${M_OBJS}
		@${RM} ${B_OBJS}

fclean : clean
		@make fclean -C libft
		@${RM} ${M_NAME} ${B_NAME} 
		@printf "\033[0;31m Succesfully cleaned the project!\n\e[0m"

re : fclean all

.PHONY:		all bonus clean fclean re
