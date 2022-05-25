#include "push_swap.h"

static int	_get_operation_in_a(t_stack *a);
static int	_get_operation_in_b(t_stack *b);

int	get_operation(t_stack *s)
{
	static int	(*operation[2])(t_stack *s) = {
		_get_operation_in_a,
		_get_operation_in_b
	};

	return ((*operation[s->name == 'b'])(s));
}

void	get_double_operation(int *operation)
{
	if (operation[A] == SA && operation[B] == SB)
		operation[2] = SS;
	else if (operation[A] == RA && operation[B] == RB)
		operation[2] = RR;
	else if (operation[A] == RRA && operation[B] == RRB)
		operation[2] = RRR;
	else
		operation[2] = 0;
}

static int	_get_operation_in_a(t_stack *a)
{
	int	top[2];

	top[0] = a->nodes[a->top].value;
	top[1] = a->nodes[a->top - 1].value;
	if (top[0] > top[1])
		return (SA);
	return (0);
}

static int	_get_operation_in_b(t_stack *b)
{
	int	top[2];

	top[0] = b->nodes[b->top].value;
	top[1] = b->nodes[b->top - 1].value;
	return (0 + top[0] + top[1]);
}
