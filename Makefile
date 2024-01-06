M_NAME = push_swap
B_NAME = checker
LIBS = ./libft/libft.a
M_SRC_FILES =	main.c \
			actions.c \
			free_init.c \
			insertion_sort.c \
			radix_sort.c  \
			utils.c \

B_SRCS_FILES = 	main_bonus.c \
				actions_bonus.c \
				error_free_init_bonus.c \
				utils_bonus.c \

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
# For test:
OS = $(shell uname)
size ?= 10
ifeq ($(OS),Linux)
CHECKER = valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)
else
CHECKER = ./push_swap $(ARG) | ./checker_Mac $(ARG)
endif

all:	$(M_NAME)
	@echo "\033[0;32m🤟 Push Swap successfully compiled! 🤟\e[0m"
	@echo "\033[0;35mTo test the program, run 'make test size=n' (n is amount of test nums)\e[0m"


$(M_NAME) : $(M_OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(M_OBJS) $(LIBS) -o $(M_NAME) ${INCLUDE}

bonus : $(B_NAME)

$(B_NAME) : $(B_OBJS)
	@make -C libft -s
	@$(CC) $(CFLAGS) $(B_OBJS) $(LIBS) -o $(B_NAME) ${INCLUDE}
	@printf "\033[0;32m 🤟 Checker succesfully compiled! 🤟\n\e[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ ${INCLUDE}

test:
	@$(eval ARG = $(shell seq -1000 1000 | shuf -n $(size)))
	@echo "\033[35mChecker result:\033[0m"
	$(CHECKER)
	@echo "\033[35mInstructions count:\033[0m"
	@./push_swap $(ARG) | wc -l

clean :
		@make clean -C libft -s
		@${RM} ${M_OBJS}
		@${RM} ${B_OBJS}

fclean : clean
		@make fclean -C libft -s
		@${RM} ${M_NAME} ${B_NAME} 
		@printf "\033[0;31m Succesfully cleaned the push_swap project!\n\e[0m"

re : fclean all

.PHONY:		all bonus clean fclean re
