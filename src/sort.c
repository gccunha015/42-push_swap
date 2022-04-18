#include "push_swap.h"

int	stack_is_sorted(t_stack *s);

void	sort(t_program *p)
{
	t_stack	*a;
	t_stack	*b;

	a = &p->stack_a;
	b = &p->stack_b;
	while (!stack_is_sorted(a) || !stack_is_empty(b))
	{
		if (!stack_is_sorted(a) && stack_is_empty(b))
		{
			if (a->size == 2)
				swap(SA, p);
			if (a->size == 3)
			{
				if (a->values[a->top] > a->values[0])
					rotate(RA, p);
				else if (a->values[a->top] < a->values[0])
					rotate(RRA, p);
				else
					return ;
			}
		}
	}
}

int	stack_is_sorted(t_stack *s)
{
	int	i;
	int	j;

	i = s->size;
	while (--i > 0)
	{
		j = i;
		while (--j > -1)
			if (s->values[i] > s->values[j])
				return (0);
	}
	return (1);
}
