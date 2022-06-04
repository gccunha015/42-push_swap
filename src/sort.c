#include "push_swap.h"

static int	is_sorted(t_stack *s);

void	sort(t_program *p)
{
	int	operation[3];
	int	count = -1;

	if (is_sorted(&p->a))
		return ;
	divide(p, 1);
	while (!is_empty(&p->b))
		execute(PA, p);	
	divide(p, 0);
	/*
	while (++count < 10)
	{
		operation[A] = get_operation(&p->a);
		operation[B] = get_operation(&p->b);
		get_double_operation(operation);
		if (operation[2])
			execute(operation[2], p);
		else if (operation[A] && operation[B])
		{
			execute(operation[A], p);
			execute(operation[B], p);
		}
		else if (operation[A])
			execute(operation[A], p);
		else if (operation[B])
			execute(operation[B], p);
		else
			break ;
	}
	*/
	/*
	while (!is_empty(&p->b))
		execute(PA, p);
	*/
	//print_stacks(&p->a, &p->b);
	(void) count;
	(void) operation;
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
