NAME	= philo
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
SRCS	= src/main.c $(wildcard src/*/*.c)
OBJS	= $(SRCS:.c=.o)

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

MALLOC_DIR = lib/malloc_lib
MALLOC_LIB = lib/malloc_lib/malloc_lib.a

all: $(NAME)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf $(UP)$(CUT)

lib:
	@echo $(B)
	make -C $(MALLOC_DIR) all

$(NAME): $(OBJS)
	@echo $(B)
	make -C $(MALLOC_DIR) all
	@echo $(Y)Compiling [$(CFILES)]...$(X)
	@echo $(G)Finished [$(CFILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(MALLOC_LIB) $^ -o $@
	@echo $(G)Finished [$(NAME)]$(X)

clean:
	@make -C $(MALLOC_DIR) clean
	@rm -f $(OBJS)
	@echo $(R)Removed [$(OBJECTS)]$(X)

fclean: clean
	@make -C $(MALLOC_DIR) fclean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all

.PHONY: all clean fclean re
