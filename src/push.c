#include "push_swap.h"

static int	_push(t_stack *source, t_stack *target)
{
	if (is_empty(source) || is_full(target))
		return (0);
	push(target, *pop(source));
	return (1);
}

int	pa(t_program *p)
{
	return (_push(&p->b, &p->a));
}

int	pb(t_program *p)
{
	return (_push(&p->a, &p->b));
}
