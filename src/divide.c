#include "push_swap.h"

static int	get_element_to_sort_in_b(t_stack *a, int second);

static int	_get_max(t_stack *s)
{
	int	max;
	int	i;

	max = 0;
	i = -1;
	while (++i <= s->top)
		if (s->nodes[i].value > s->nodes[max].value)
			max = i;
	return (max);
}

void	divide(t_program *p, int second)
{
	int	element;

	if (p->a.size < 4)
		return ;
	while (1)
	{
		element = get_element_to_sort_in_b(&p->a, second);

		if (element != -1 && has_at_least_2_elements(&p->b))
		{
			int	ie = p->a.nodes[element].index;
			int	i = p->b.top;
			int	j = 0;
			int	ii;
			int	ij;
			while (i > j)
			{
				ii = p->b.nodes[i].index;
				ij = p->b.nodes[j].index;
				if (ii < ie)
					i--;
				if (ij > ie)
					j++;
				if (p->b.nodes[i].index == ii
					&& p->b.nodes[j].index == ij)
					break ;
			}
			if (p->b.top - i >= j)
				while (++i <= p->b.top)
					execute(RB, p);
			else
				while (--j > -1)
					execute(RRB, p);
		}

		if (element == p->a.top)
			execute(PB, p);
		else if (element >= p->a.top / 2)
			execute(RA, p);
		else if (element != -1)
			execute(RRA, p);
		else
			break ;
	}
	int	max = _get_max(&p->b);
	while (max < p->b.top && max >= p->b.top / 2)
	{
		execute(RB, p);
		max = _get_max(&p->b);
	}
	while (max < p->b.top / 2)
	{
		execute(RRB, p);
		max = _get_max(&p->b);
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
