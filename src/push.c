#include "push_swap.h"

static void	_push(t_stack *source, t_stack *target);

void	push(char *operation, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(operation, PA, ft_strlen(operation)))
		_push(b, a);
	else if (!ft_strncmp(operation, PB, ft_strlen(operation)))
		_push(a, b);
}

static void	_push(t_stack *source, t_stack *target)
{
	stack_push(target, *stack_pop(source));
}
