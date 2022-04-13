#include "push_swap.h"

void	exit_program(t_program_args *pa);
void	mark_x_when_not_a_number(unsigned int iteration, char *c);

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	quantity;
	int	idx;
	int	idx2;

	if (argc < 2)
		exit_program(&((t_program_args){NULL, NULL, ERROR_ARGUMENT_QUANTITY}));
	argv++;

	quantity = argc - 1;
	stack_a = malloc(quantity * sizeof(*stack_a));
	if (!stack_a)
		exit_program(&((t_program_args){NULL, NULL, ERROR_MALLOC}));
	idx = -1;
	while (++idx < quantity)
	{
		ft_striteri(argv[idx], mark_x_when_not_a_number);
		if (ft_strchr(argv[idx], 'x'))
			exit_program(&((t_program_args){stack_a, NULL, ERROR_ARGUMENT_NOT_A_NUMBER}));
		stack_a[quantity - 1 - idx] = ft_atoi(argv[idx]);

		idx2 = -1;
		while (++idx2 < idx)
			if (stack_a[quantity - 1 - idx2] == stack_a[quantity - 1 - idx])
				exit_program(&((t_program_args){stack_a, NULL, ERROR_ARGUMENT_DUPLICATED}));
	}

	stack_b = malloc(quantity * sizeof(*stack_b));
	if (!stack_b)
		exit_program(&((t_program_args){stack_a, NULL, ERROR_MALLOC}));
	
	exit_program(&((t_program_args){stack_a, stack_b, NULL}));
}

void	exit_program(t_program_args *pa)
{
	if (pa->stack_a)
		free(pa->stack_a);
	if (pa->stack_b)
		free(pa->stack_b);
	if (pa->error_message)
	{
		ft_printf("Error:\n\t%s\n", pa->error_message);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void	mark_x_when_not_a_number(unsigned int iteration, char *c)
{
	(void) iteration;
	if (!*c || ft_isdigit(*c) || (ft_strchr("-+", *c) && ft_isdigit(*(c + 1))))
		return ;
	*c = 'x';
}
