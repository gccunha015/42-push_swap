#include "push_swap.h"

static int	p_(t_stack *target, t_stack *source);

int	push(char *operation, t_program *p)
{
	int	pushed;

	if (!ft_strncmp(operation, PA, ft_strlen(operation)))
		pushed = p_(&p->stack_a, &p->stack_b);
	else if (!ft_strncmp(operation, PB, ft_strlen(operation)))
		pushed = p_(&p->stack_b, &p->stack_a);
	else
		pushed = 0;
	return (pushed);
}

static int	p_(t_stack *target, t_stack *source)
{
	t_node	*top;

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
