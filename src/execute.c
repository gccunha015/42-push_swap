#include "push_swap.h"

static void	print_operation(int operation);
static char	*get_string(int operation);

void	execute(int operation, t_stack *a, t_stack *b)
{
	if (operation >= SA && operation < PA)
		swap(operation, a, b);
	else if (operation < RA)
		push(operation, a, b);
	else if (operation < RRA)
		rotate(operation, a, b);
	else if (operation <= RRR)
		reverse_rotate(operation, a, b);
	else
		return ;
	print_operation(operation);
	print_stacks(a, b);
}

static void	print_operation(int o)
{
	char	*operation;

	operation = get_string(o);
	write(STDOUT_FILENO, operation, ft_strlen(operation));
	write(STDOUT_FILENO, "\n", 1);
}

static char	*get_string(int operation)
{
	static char	operations[11][4] = {
		"sa\0", "sb\0", "ss\0",
		"pa\0", "pb\0",
		"ra\0", "rb\0", "rr\0",
		"rra\0", "rrb\0", "rrr\0"
	};

	return (operations[operation]);
}
