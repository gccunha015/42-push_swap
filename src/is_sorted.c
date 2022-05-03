#include "push_swap.h"

int	is_sorted(t_stack *s, int order)
{
	int	i;
	int	j;
	int	v[2];

	if (stack_is_empty(s))
		return (1);
	i = -1;
	while (++i < s->top)
	{
		v[0] = s->nodes[i].value;
		j = i;
		while (++j <= s->top)
		{
			v[1] = s->nodes[j].value;
			if ((order == ASCENDING && v[0] < v[1])
				|| (order == DESCENDING && v[0] > v[1]))
				return (0);
		}
	}
	return (1);
}
