#include "push_swap.h"

static void	print_operation(char *operation, t_program p);

void	operate(char *operation, t_program *p)
{
	int	operated;

	if (ft_strnstr(SWAP, operation, ft_strlen(SWAP)))
		operated = swap(operation, p);
	else if (ft_strnstr(PUSH, operation, ft_strlen(PUSH)))
		operated = push(operation, p);
	else if (ft_strnstr(ROTATE, operation, ft_strlen(ROTATE)))
		operated = rotate(operation, p);
	else if (ft_strnstr(REVERSE_ROTATE, operation,
		ft_strlen(REVERSE_ROTATE)))
		operated = reverse_rotate(operation, p);
	else
		operated = 0;
	if (operated)
		print_operation(operation, *p);
}

static void	print_operation(char *operation, t_program p)
{
	write(STDOUT_FILENO, operation, ft_strlen(operation));
	write(STDOUT_FILENO, "\n", 1);
	print_stacks(p);
}
