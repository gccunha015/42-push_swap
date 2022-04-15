#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# define ERROR_ARGUMENT_QUANTITY "The number of arguments is wrong.\n\t"\
					"Valid example : ./push_swap 2 1 0 -1 -2"
# define ERROR_ARGUMENT_NOT_A_NUMBER "At least one argument is not an integer."
# define ERROR_ARGUMENT_DUPLICATED "At least one argument is duplicated."
# define ERROR_MALLOC "It was not possible to allocate memory."

enum	e_operations
{
	SA = 1,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef struct s_stack
{
	int	*values;
	int	size;
	int	top;
}	t_stack;

typedef struct s_program
{
	t_stack	stack_a;
	t_stack	stack_b;
}	t_program;

void	initialize_program(t_program *p, int argc);
void	exit_program(t_program *p, char *error_message);

void	stack_create(t_stack *s, int size, t_program *p);
void	stack_delete(t_stack *s);
int	stack_is_empty(t_stack *s);
int	stack_has_at_least_2_elements(t_stack *s);
int	stack_push(t_stack *s, int value);
int	*stack_pop(t_stack *s);

void	fill_stack_a(t_stack *a, char **argv, t_program *p);

void	swap(int operation, t_program *p);
void	swap_values(int *x, int *y);
void	push(int operation, t_program *pr);
void	rotate(int operation, t_program *p);

#endif
