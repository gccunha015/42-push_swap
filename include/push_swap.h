#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "push_swap_types.h"
# include "push_swap_constants.h"
# include "stack.h"
# include "program.h"

# include <stdio.h>

void	print_stacks(t_stack *a, t_stack *b);

void	execute(int operation, t_program *p);

int	pa(t_program *p);
int	pb(t_program *p);
int	sa(t_program *p);
int	sb(t_program *p);
int	ss(t_program *p);
int	ra(t_program *p);
int	rb(t_program *p);
int	rr(t_program *p);
int	rra(t_program *p);
int	rrb(t_program *p);
int	rrr(t_program *p);

void	swap(t_node *x, t_node *y);

#endif
