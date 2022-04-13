#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# define ERROR_ARGUMENT_QUANTITY "The number of arguments is wrong.\n\t"\
					"Valid example : ./push_swap 2 1 0 -1 -2"
# define ERROR_ARGUMENT_NOT_A_NUMBER "At least one argument is not an integer."
# define ERROR_ARGUMENT_DUPLICATED "At least one argument is duplicated."
# define ERROR_MALLOC "It was not possible to allocate memory."

typedef struct s_stack
{
	int	*values;
	int	length;
}	t_stack;

typedef struct s_program_args
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*error_message;
}	t_program_args;

#endif
