NAME			= push_swap
SRC			= push_swap.c \
			  program.c \
			  stack.c \
			  fill_stack_a.c \
			  swap.c \
			  push.c \
			  rotate.c \
			  reverse_rotate.c \
			  print_operation.c \
			  sort.c
OBJECTS			= $(SRC:%.c=obj/%.o)
INCLUDES		= -Iinclude -Ilibft/include
MAKE_IN_PATH		= $(MAKE) -sC
MAKE_LIBFT		= $(MAKE_IN_PATH) libft
LIBFT			= libft/libft.a
LIBRARIES		= -Llibft -lft
CC			= cc
CC_FLAGS		= -Wall -Wextra -Werror -g
MKDIR			= mkdir -p
RM			= rm -fr
VALGRIND		= valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes
VPATH			= . src obj

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJECTS)
			$(CC) $(CC_FLAGS) -o $(NAME) $(OBJECTS) $(LIBRARIES)

clean:
			$(MAKE_LIBFT) clean
			$(RM) obj

fclean:			clean
			$(RM) $(LIBFT) $(NAME)

re:			fclean all

obj/%.o:		%.c | obj
			$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

obj:
			$(MKDIR) obj

run:			$(NAME)
			$(VALGRIND) ./$(NAME) $(STACK)

$(LIBFT):
			$(MAKE_LIBFT) printf

.PHONY:	all clean fclean re bonus
