#include "push_swap.h"

static int	_get_element_out_of_order(t_stack *s, int is_b);

int	get_operation(t_stack *s)
{
	int	is_b;
	int	element;
	int	operation;

	if (!has_at_least_2_elements(s))
		return (0);
	is_b = s->name == 'b';
	element = _get_element_out_of_order(s, is_b);
	if (element == s->top)
		operation = SA;
	else if (element >= s->top / 2)
		operation = RA;
	else if (element != -1)
		operation = RRA;
	else
		return (0);
	return (operation + is_b);
}

static int	_get_element_out_of_order(t_stack *s, int is_b)
{
	int	idx[2];
	int	i;
	int	j;

	i = s->top + 1;
	while (--i > s->top / 2)
	{
		idx[0] = s->nodes[i].index;
		idx[1] = s->nodes[i - 1].index;
		if ((!is_b && idx[0] < idx[1]) || (is_b && idx[0] > idx[1]))
			return (i);
		j = s->top - i;
		idx[0] = s->nodes[j + 1].index;
		idx[1] = s->nodes[j].index;
		if ((!is_b && idx[0] < idx[1]) || (is_b && idx[0] > idx[1]))
			return (j);
	}
	return (-1);
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
