#include "push_swap.h"

static int	s(t_stack *s);
void	swap_values(int *x, int *y);
static void	print_operation(int o);

void	swap(int operation, t_program *p)
{
	int	swapped;

	if (operation == SA)
		swapped = s(&p->stack_a);
	else if (operation == SB)
		swapped = s(&p->stack_b);
	else if (operation == SS)
	{
		swapped = s(&p->stack_a);
		if (s(&p->stack_b))
			operation = SB;
		if (swapped && operation == SB)
			operation = SS;
		else if (swapped)
			operation = SA;
		else if (operation == SB)
			swapped = 1;
	}
	else
		swapped = 0;
	if (swapped)
		print_operation(operation);
}

static int	s(t_stack *s)
{
	if (!stack_has_at_least_2_elements(s))
		return (0);
	swap_values(&s->values[s->top], &s->values[s->top - 1]);
	return (1);
}

void	swap_values(int *x, int *y)
{
	int	aux;

	aux = *x;
	*x = *y;
	*y = aux;
}

static void	print_operation(int o)
{
	char	*operation;

	if (o == SA)
		operation = "sa";
	else if (o == SB)
		operation = "sb";
	else
		operation = "ss";
	ft_printf("%s\n", operation);
}
