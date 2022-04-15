#include "push_swap.h"

static int	p(t_stack *a, t_stack *b);
static void	print_operation(int o);

void	push(int operation, t_program *p)
{
	int	pushed;

	if (operation == PA)
		pushed = p(&p->stack_a, &p->stack_b);
	else if (operation == PB)
		pushed = p(&p->stack_b, &p->stack_a);
	if (pushed)
		print_operation(operation);
}

static int	p(t_stack *a, t_stack *b)
{
	if (stack_is_empty(b))
		return (0);
	stack_push(a, stack_pop(b));
	return (1);
}

static void	print_operation(int o)
{
	char	*operation;

	if (o == PA)
		operation = "pa";
	else
		operation = "pb";
	ft_printf("%s\n", operation);
}
