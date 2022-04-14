#include "push_swap.h"

static void	swap_elements(t_stack *s);

void	swap(t_stack *a, t_stack *b)
{
	char	*operation;

	if (a)
	{
		swap_elements(a);
		operation = "sa";
	}
	if (b)
	{
		swap_elements(b);
		operation = "sb";
	}
	if (a && b)
		operation = "ss";
	ft_printf("%s\n", operation);
}

static void	swap_elements(t_stack *s)
{
	int	aux;

	aux = s->values[s->top];
	s->values[s->top] = s->values[s->top - 1];
	s->values[s->top - 1] = aux;
}
