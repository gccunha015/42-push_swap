#include "push_swap.h"

void	swap(t_stack *x, t_stack *y)
{
	int	aux;

	if (y)
	{
		swap(x, NULL);
		swap(y, NULL);
		return ;
	}
	if (x->length < 2)
		return ;
	aux = x->values[1];
	x->values
}
