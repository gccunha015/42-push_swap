#include "push_swap.h"

static int	r(t_stack *s);
static void	print_operation(int o);

void	rotate(int operation, t_program *p)
{
	int	rotated;

	if (operation == RA)
		rotated = r(&p->stack_a);
	else if (operation == RB)
		rotated = r(&p->stack_b);
	else if (operation == RR)
	{
		rotated = r(&p->stack_a);
		if (r(&p->stack_b))
			operation = RB;
		if (rotated && operation == RB)
			operation = RR;
		else if (rotated)
			operation = RA;
		else if (operation == RB)
			rotated = 1;
	}
	else
		rotated = 0;
	if (rotated)
		print_operation(operation);
}

static int	r(t_stack *s)
{
	int	i;

	if (!stack_has_at_least_2_elements(s))
		return (0);
	i = 0;
	while (++i <= s->top)
		swap_values(&s->values[0], &s->values[i]);
	return (1);
}

static void	print_operation(int o)
{
	char	*operation;

	if (o == RA)
		operation = "ra";
	else if (o == RB)
		operation = "rb";
	else
		operation = "rr";
	ft_printf("%s\n", operation);
}