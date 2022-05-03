#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

# include <stdio.h>

enum	e_operations
{
	SA,
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

enum	e_which_stack
{
	A,
	B
};

enum	e_sort_order
{
	ASCENDING,
	DESCENDING
};

typedef struct s_node
{
	int	value;
	int	index;
}	t_node;

typedef struct s_stack
{
	t_node	*nodes;
	int	size;
	int	top;
}	t_stack;

typedef struct s_program
{
	t_stack	a;
	t_stack	b;
}	t_program;

void	print_stacks(t_stack *oa, t_stack *ob);

void	initialize_program(t_program *p, int argc);
void	exit_program(t_program *p, int exit_code);

void	stack_create(t_stack *s, int size, t_program *p);
void	stack_delete(t_stack *s);
int	stack_is_empty(t_stack *s);
int	stack_has_at_least_2_elements(t_stack *s);
int	stack_is_full(t_stack *s);
void	stack_push(t_stack *s, t_node node);
t_node	*stack_pop(t_stack *s);

void	fill_stack_a(t_program *p, char **argv);

void	swap(int operation, t_stack *a, t_stack *b);
void	swap_nodes(t_node *x, t_node *y);
void	push(int operation, t_stack *a, t_stack *b);
void	rotate(int operation, t_stack *a, t_stack *b);
void	reverse_rotate(int operation, t_stack *a, t_stack *b);

void	execute(int operation, t_stack *a, t_stack *b);

int	is_sorted(t_stack *s, int order);
void	sort(t_stack *a, t_stack *b);

#endif
