#include "push_swap.h"

static int	r(t_stack *s);

void	rotate(int operation, t_program *p)
{
	int	rotated;

	if (operation == RA)
		rotated = r(&p->stack_a);
	else if (operation == RB)
		rotated = r(&p->stack_b);
	else if (operation == RR)
	{
		rotated = r(&p->stack_a);
		if (r(&p->stack_b))
			operation = RB;
		if (rotated && operation == RB)
			operation = RR;
		else if (rotated)
			operation = RA;
		else if (operation == RB)
			rotated = 1;
	}
	else
		rotated = 0;
	if (rotated)
		print_operation(operation, *p);
}

static int	r(t_stack *s)
{
	int	i;

	if (!stack_has_at_least_2_elements(s))
		return (0);
	i = 0;
	while (++i <= s->top)
		swap_nodes(&s->nodes[0], &s->nodes[i]);
	return (1);
}
