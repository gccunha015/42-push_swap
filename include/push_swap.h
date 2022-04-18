#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"

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
void	exit_program(t_program *p, int exit_code);

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
void	reverse_rotate(int operation, t_program *p);

void	sort(t_program *p);

#endif
