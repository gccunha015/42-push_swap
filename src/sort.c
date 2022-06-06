#include "push_swap.h"

int	is_sorted(t_stack *s);
void	sort_up_to_3(t_program *p);
void	sort_more_than_3(t_program *p);

void	sort(t_program *p)
{
	if (is_sorted(&p->a))
		return ;
	if (p->a.size < 4)
		return (sort_up_to_3(p));
	return (sort_more_than_3(p));
}

int	get_min(t_stack *s, int ignore, int v_to_ignore)
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

int	get_max(t_stack *s, int ignore, int v_to_ignore)
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

void	sort_up_to_3(t_program *p)
{
	int	operation;

	while (!is_sorted(&p->a))
	{
		if (get_max(&p->a, 0, 0) == p->a.top)
			operation = RA;
		else if (get_min(&p->a, 0, 0) == 0)
			operation = RRA;
		else
			operation = SA;
		execute(operation, p);
	}
}

void	sort_more_than_3(t_program *p)
{
	(void) p;
}

int	is_sorted(t_stack *s)
{
	int	is_b;
	int	i;
	int	j;
	int	v[2];

	is_b = s->name == 'b';
	i = -1;
	while (++i < s->top)
	{
		v[0] = s->nodes[i].value;
		j = i;
		while (++j <= s->top)
		{
			v[1] = s->nodes[j].value;
			if ((!is_b && v[0] < v[1])
				|| (is_b && v[0] > v[1]))
				return (0);
		}
	}
	return (1);
}
