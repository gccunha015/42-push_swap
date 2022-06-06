#include "push_swap.h"

static int	get_element_to_sort_in_b(t_stack *a, int second);

static int	_get_min(t_stack *s, int ignore, int v_to_ignore)
{
	int	min;
	int	i;

	min = -1;
	i = -1;
	while (++i <= s->top)
	{
		if (ignore && s->nodes[i].value <= v_to_ignore)
			continue ;
		if (min == -1 || s->nodes[i].value < s->nodes[min].value)
			min = i;
	}
	return (min);
}

static int	_get_max(t_stack *s, int ignore, int v_to_ignore)
{
	int	max;
	int	i;

	max = -1;
	i = -1;
	while (++i <= s->top)
	{
		if (ignore && s->nodes[i].value >= v_to_ignore)
			continue ;
		if (max == -1 || s->nodes[i].value > s->nodes[max].value)
			max = i;
	}
	return (max);
}

static int	get_element_position_in_b(int element, t_stack *b)
{
	int	min;
	int	max;

	if (!has_at_least_2_elements(b))
		return (-1);
	min = _get_min(b, 0, 0);
	max = _get_max(b, 0, 0);
	while (min != -1 || max != -1)
	{
		if (element < b->nodes[min].value)
		{
			if (min == 0)
				return (b->top);
			else if (min == b->top)
				return (b->top - 1);
			return (min);
		}
		if (element > b->nodes[max].value)
			return (max);
		min = _get_min(b, 1, b->nodes[min].value);
		max = _get_max(b, 1, b->nodes[max].value);
	}
	return (-1);
}

void	divide(t_program *p, int second)
{
	int	element;
	int	pos;
	int	count = 0;

	(void) count;
	if (p->a.size < 4)
		return ;
	while (1)
	{
		element = get_element_to_sort_in_b(&p->a, second);
		if (element == -1)
			break ;
		pos = get_element_position_in_b(p->a.nodes[element].value, &p->b);
		if (element == p->a.top)
		{
			if (pos == -1 || pos == p->b.top)
				execute(PB, p);
			else if (pos >= p->b.top / 2)
				execute(RB, p);
			else
				execute(RRB, p);
		}
		else if (pos != p->b.top && pos != -1)
		{
			if (element >= p->a.top / 2
				&& pos >= p->b.top / 2)
				execute(RR, p);
			else if (element <= p->a.top / 2
				&& pos <= p->b.top / 2)
				execute(RRR, p);
			else if (element >= p->a.top / 2
				&& pos <= p->b.top / 2)
			{
				execute(RA, p);
				execute(RRB, p);
			}
			else
			{
				execute(RRA, p);
				execute(RB, p);
			}
		}
		else
		{
			if (element >= p->a.top / 2)
				execute(RA, p);
			else
				execute(RRA, p);
		}
	}
}

static int	get_element_to_sort_in_b(t_stack *a, int second)
{
	int	i;
	int	j;

	i = a->top + 1;
	while (--i >= a->top / 2)
	{
		if ((!second && a->nodes[i].index >= a->size / 2)
			|| (second && a->nodes[i].index < a->size / 2))
			return (i);
		j = a->top - i;
		if ((!second && a->nodes[j].index >= a->size / 2)
			|| (second && a->nodes[j].index < a->size / 2))
			return (j);
	}
	return (-1);
}
