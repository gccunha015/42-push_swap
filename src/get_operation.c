#include "push_swap.h"

int	get_min(t_stack *s)
{
	int	min;
	int	i;

	if (is_empty(s))
		return (-1);
	min = 0;
	i = 0;
	while (++i <= s->top)
		if (s->nodes[i].value < s->nodes[min].value)
			min = i;
	return (min);
}

int	get_max(t_stack *s)
{
	int	max;
	int	i;

	if (is_empty(s))
		return (-1);
	max = 0;
	i = 0;
	while (++i <= s->top)
		if (s->nodes[i].value > s->nodes[max].value)
			max = i;
	return (max);
}

static int	is_out_of_order(t_stack *s, int is_b, int i, int j);
static int	get_element_out_of_order(t_stack *s, int is_b);

int	get_operation(t_stack *s)
{
	int	is_b;
	int	element;
	int	operation;

	if (!has_at_least_2_elements(s))
		return (0);
	is_b = s->name == 'b';
	element = get_element_out_of_order(s, is_b);
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

static int	get_element_out_of_order(t_stack *s, int is_b)
{
	int	i;
	int	j;

	i = s->top + 1;
	while (--i > s->top / 2)
	{
		if (is_out_of_order(s, is_b, i, i - 1))
			return (i);
		j = s->top - i;
		if (is_out_of_order(s, is_b, j + 1, j))
			return (j);
	}
	if (is_out_of_order(s, is_b, s->top, 0))
		return (0);
	return (-1);
}

static int	is_out_of_order(t_stack *s, int is_b, int i, int j)
{
	int	idx[2];
	int	min;
	int	max;

	idx[0] = s->nodes[i].index;
	idx[1] = s->nodes[j].index;
	min = get_min(s);
	max = get_max(s);
	if (is_b)
	{
		if (i == min && j == max)
			return (0);
		return (idx[0] > idx[1]);
	}
	if (i == max && j == min)
		return (0);
	return (idx[0] < idx[1]);
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
