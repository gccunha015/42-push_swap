#include "push_swap.h"

static void	_swap(t_stack *s);

void	swap(int operation, t_stack *a, t_stack *b)
{
	if (operation == SA)
		_swap(a);
	else if (operation == SB)
		_swap(b);
	else if (operation == SS)
	{
		_swap(a);
		_swap(b);
	}
}

static void	_swap(t_stack *s)
{
	swap_nodes(&s->nodes[s->top], &s->nodes[s->top - 1]);
}

void	swap_nodes(t_node *x, t_node *y)
{
	t_node aux;

	aux = *x;
	*x = *y;
	*y = aux;
}
