#include "push_swap.h"

static int	_swap(t_stack *s)
{
	if (!has_at_least_2_elements(s))
		return (0);
	swap(&s->nodes[s->top], &s->nodes[s->top - 1]);
	return (1);
}

int	sa(t_program *p)
{
	return (_swap(&p->a));
}

int	sb(t_program *p)
{
	return (_swap(&p->b));
}

int	ss(t_program *p)
{
	if (!has_at_least_2_elements(&p->a) || !has_at_least_2_elements(&p->b))
		return (0);
	return (sa(p) && sb(p));
}

void	swap(t_node *x, t_node *y)
{
	t_node	aux;

	aux = *x;
	*x = *y;
	*y = aux;
}
