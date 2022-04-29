#include "push_swap.h"

static void	print_operation(char *operation);

void	operate(char *operation, t_stack *a, t_stack *b)
{
	if (ft_strnstr(SWAP, operation, ft_strlen(SWAP)))
		swap(operation, a, b);
	else if (ft_strnstr(PUSH, operation, ft_strlen(PUSH)))
		push(operation, a, b);
	else if (ft_strnstr(ROTATE, operation, ft_strlen(ROTATE)))
		rotate(operation, a, b);
	else if (ft_strnstr(REVERSE_ROTATE, operation,
			ft_strlen(REVERSE_ROTATE)))
		reverse_rotate(operation, a, b);
	print_operation(operation);
//	print_stacks(*a, *b);
}

static void	print_operation(char *operation)
{
	write(STDOUT_FILENO, operation, ft_strlen(operation));
	write(STDOUT_FILENO, "\n", 1);
}
