#include "push_swap.h"

static void	_reverse_rotate(t_stack *s);

void	reverse_rotate(int operation, t_stack *a, t_stack *b)
{
	if (operation == RRA)
		_reverse_rotate(a);
	else if (operation == RRB)
		_reverse_rotate(b);
	else if (operation == RRR)
	{
		_reverse_rotate(a);
		_reverse_rotate(b);
	}
}

static void	_reverse_rotate(t_stack *s)
{
	int	i;

	i = s->top + 1;
	while (--i > -1)
		swap_nodes(&s->nodes[0], &s->nodes[i]);
}
