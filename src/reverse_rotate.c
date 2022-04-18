#include "push_swap.h"

static int	rr(t_stack *s);

void	reverse_rotate(int operation, t_program *p)
{
	int	rotated;

	if (operation == RRA)
		rotated = rr(&p->stack_a);
	else if (operation == RRB)
		rotated = rr(&p->stack_b);
	else if (operation == RRR)
	{
		rotated = rr(&p->stack_a);
		if (rr(&p->stack_b))
			operation = RRB;
		if (rotated && operation == RRB)
			operation = RRR;
		else if (rotated)
			operation = RRA;
		else if (operation == RRB)
			rotated = 1;
	}
	else
		rotated = 0;
	if (rotated)
		print_operation(operation, *p);
}

static int	rr(t_stack *s)
{
	int	i;

	if (!stack_has_at_least_2_elements(s))
		return (0);
	i = s->top + 1;
	while (--i >= 0)
		swap_values(&s->values[0], &s->values[i]);
	return (1);
}
