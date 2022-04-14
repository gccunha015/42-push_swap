#include "push_swap.h"

static void	print_stack(t_stack s, char name, t_program p);

int	main(int argc, char **argv)
{
	t_program	program;

	initialize_program(&program, argc);
	fill_stack_a(&program.stacks[0], argv, &program);
	print_stack(program.stacks[0], 'a', program);
	swap(&program.stacks[0], NULL);
	print_stack(program.stacks[0], 'a', program);
	exit_program(&program, NULL);
}

static void	print_stack(t_stack s, char name, t_program p)
{
	ft_printf("%c : [ ", name);
	for (size_t i = 0; i < p.n_elements; i++)
	{
		ft_printf("%4i", s.values[i]);
		if (i != p.n_elements - 1)
			ft_printf(" | ");
	}
	ft_printf(" ]\n");
}
