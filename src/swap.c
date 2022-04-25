#include "push_swap.h"

static int	s(t_stack *s);

void	swap(int operation, t_program *p)
{
	int	swapped;

	if (operation == SA)
		swapped = s(&p->stack_a);
	else if (operation == SB)
		swapped = s(&p->stack_b);
	else if (operation == SS)
	{
		swapped = s(&p->stack_a);
		if (s(&p->stack_b))
			operation = SB;
		if (swapped && operation == SB)
			operation = SS;
		else if (swapped)
			operation = SA;
		else if (operation == SB)
			swapped = 1;
	}
	else
		swapped = 0;
	if (swapped)
		print_operation(operation, *p);
}

static int	s(t_stack *s)
{
	if (!stack_has_at_least_2_elements(s))
		return (0);
	swap_nodes(&s->nodes[s->top], &s->nodes[s->top - 1]);
	return (1);
}

void	swap_nodes(t_node *x, t_node *y)
{
	t_node aux;

	aux = *x;
	*x = *y;
	*y = aux;
}
