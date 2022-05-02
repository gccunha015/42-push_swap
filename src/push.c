#include "push_swap.h"

static void	_push(t_stack *source, t_stack *target);

void	push(int operation, t_stack *a, t_stack *b)
{
	if (operation == PA)
		_push(b, a);
	else if (operation == PB)
		_push(a, b);
}

static void	_push(t_stack *source, t_stack *target)
{
	stack_push(target, *stack_pop(source));
}
