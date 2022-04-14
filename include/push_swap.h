#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# define ERROR_ARGUMENT_QUANTITY "The number of arguments is wrong.\n\t"\
					"Valid example : ./push_swap 2 1 0 -1 -2"
# define ERROR_ARGUMENT_NOT_A_NUMBER "At least one argument is not an integer."
# define ERROR_ARGUMENT_DUPLICATED "At least one argument is duplicated."
# define ERROR_MALLOC "It was not possible to allocate memory."
# define N_STACKS 2

typedef struct s_stack
{
	int	*values;
	size_t	top;
}	t_stack;

typedef struct s_program
{
	t_stack	stacks[N_STACKS];
	size_t	n_elements;
}	t_program;

void	initialize_program(t_program *p, int argc);
void	exit_program(t_program *p, char *error_message);

void	t_stack_create(t_stack *s, t_program *p);
void	t_stack_delete(t_stack *s);

void	fill_stack_a(t_stack *a, char **argv, t_program *p);

void	swap(t_stack *a, t_stack *b);

#endif
