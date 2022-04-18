#include "push_swap.h"

static int	p(t_stack *target, t_stack *source);

void	push(int operation, t_program *pr)
{
	int	pushed;

	if (operation == PA)
		pushed = p(&pr->stack_a, &pr->stack_b);
	else if (operation == PB)
		pushed = p(&pr->stack_b, &pr->stack_a);
	else
		pushed = 0;
	if (pushed)
		print_operation(operation, *pr);
}

static int	p(t_stack *target, t_stack *source)
{
	int	*top;

	top = stack_pop(source);
	if (!top)
		return (0);
	if (!stack_push(target, *top))
	{
		stack_push(source, *top);
		return (0);
	}
	return (1);
}
