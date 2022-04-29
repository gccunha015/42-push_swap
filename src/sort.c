#include "push_swap.h"

int	stack_is_sorted(t_stack *s, int last, int order);
int	get_element_to_push_to_b(t_stack *a);
int	get_min(t_stack *s);
int	get_max(t_stack *s);

void	sort(t_stack *a, t_stack *b)
{
	t_node	*n[2];
	int	min[2];
	int	max[2];
	int	element;

	if (stack_is_sorted(a, 0, ASCENDING))
		return ;
	n[0] = a->nodes;
	n[1] = b->nodes;
	if (a->size < 4)
	{
		if (get_min(a) == a->top)
			operate(RA, a, b);
		if (get_max(a) == a->top)
			operate(SA, a, b);
		if (get_min(a) == 0)
			operate(RRA, a, b);
		if (get_min(a) != a->top && get_max(a) == 0)
			operate(SA, a, b);
	}
	else
	{
	/*
		Find half of the elements wich are the smaller ones
			and push it to b, order them there
		The half with the bigger elements, order in a
	*/
		//while (a->top > b->top + 1)
		while (a->top > 2)
		{
			element = get_element_to_push_to_b(a);
			if (a->top != element && element >= a->top / 2)
				operate(RA, a, b);
			else if (a->top != element && element < a->top / 2)
				operate(RRA, a, b);
			else
				operate(PB, a, b);
		}
		while (!stack_is_sorted(a, 0, ASCENDING)
			|| !stack_is_sorted(b, 0, DESCENDING))
		{
			if (!stack_is_sorted(a, 0, ASCENDING)
				&& !stack_is_sorted(b, 0, DESCENDING))
			{
				min[A] = get_min(a);
				max[A] = get_max(a);
				min[B] = get_min(b);
				max[B] = get_max(b);
				if (min[A] == a->top && max[B] == b->top)
					operate(RR, a, b);
				else if (max[A] == a->top && min[B] == b->top)
					operate(SS, a, b);
				else if (min[A] == 0 && max[B] == 0)
					operate(RRR, a, b);
				else if (min[A] != a->top && max[A] == 0
					&& max[B] != b->top && min[B] == 0)
					operate(SS, a, b);
			}
			if (!stack_is_sorted(a, 0, ASCENDING))
			{
				min[A] = get_min(a);
				max[A] = get_max(a);
				if (min[A] == a->top)
					operate(RA, a, b);
				else if (max[A] == a->top)
					operate(SA, a, b);
				else if (min[A] == 0)
					operate(RRA, a, b);
				else if (min[A] != a->top && max[A] == 0)
					operate(SA, a, b);
			}
			if (!stack_is_sorted(b, 0, DESCENDING))
			{
				min[B] = get_min(b);
				max[B] = get_max(b);
				if (max[B] == b->top)
					operate(RB, a, b);
				else if (min[B] == b->top)
					operate(SB, a, b);
				else if (max[B] == 0)
					operate(RRB, a, b);
				else if (max[B] != b->top && min[B] == 0)
					operate(SB, a, b);
			}	
			if (stack_is_sorted(a, 0, ASCENDING)
				&& !stack_is_empty(b))
				operate(PA, a, b);
		}
		while (!stack_is_empty(b))
			operate(PA, a, b);
	}
	(void) n;
}

int	get_element_to_push_to_b(t_stack *a)
{
	int	i;
	int	j;

	i = a->top + 1;
	while (--i >= a->top / 2)
	{
		if (a->nodes[i].index < a->size / 2)
			return (i);
		j = a->top - i;
		if (a->nodes[j].index < a->size / 2)
			return (j);
	}
	return (a->top);
}

int	get_min(t_stack *s)
{
	int	min;
	int	i;

	if (!stack_has_at_least_2_elements(s))
		return (-1);
	min = 0;
	i = 0;
	while (++i <= s->top)
		if (s->nodes[i].index < s->nodes[min].index)
			min = i;
	return (min);
}

int	get_max(t_stack *s)
{
	int	max;
	int	i;

	if (!stack_has_at_least_2_elements(s))
		return (-1);
	max = 0;
	i = 0;
	while (++i <= s->top)
		if (s->nodes[i].index > s->nodes[max].index)
			max = i;
	return (max);
}

int	stack_is_sorted(t_stack *s, int last, int order)
{
	t_node	*n;
	int	i;
	int	j;

	if (!stack_has_at_least_2_elements(s))
		return (1);
	n = s->nodes;
	i = s->top + 1;
	while (--i > last)
	{
		j = i;
		while (--j > last - 1)
			if ((order == ASCENDING && n[i].value > n[j].value)
				|| (order == DESCENDING
				&& n[i].value < n[j].value))
				return (0);
	}
	return (1);
}
