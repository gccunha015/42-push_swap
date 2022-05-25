#include "push_swap.h"

static int	is_sorted(t_stack *s);

void	sort(t_program *p)
{
	if (is_sorted(&p->a))
		return ;
	divide(p);
	/*
	while (!is_empty(&p->b))
		execute(PA, p);
	*/
}

static int	is_sorted(t_stack *s)
{
	int	is_b;
	int	i;
	int	j;
	int	v[2];

	is_b = s->name == 'b';
	i = s->top + 1;
	while (--i > 0)
	{
		v[0] = s->nodes[i].value;
		j = i;
		while (--j > -1)
		{
			v[1] = s->nodes[j].value;
			if ((!is_b && v[0] > v[1]) || (is_b && v[0] < v[1]))
				return (0);
		}
	}
	return (1);
}
