#include "push_swap.h"

static void	_rotate(t_stack *s);

void	rotate(int operation, t_stack *a, t_stack *b)
{
	if (operation == RA)
		_rotate(a);
	else if (operation == RB)
		_rotate(b);
	else if (operation == RR)
	{
		_rotate(a);
		_rotate(b);
	}
}

static void	_rotate(t_stack *s)
{
	int	i;

	i = 0;
	while (++i <= s->top)
		swap_nodes(&s->nodes[0], &s->nodes[i]);
}
