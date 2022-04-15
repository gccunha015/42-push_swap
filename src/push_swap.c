#include "push_swap.h"

static void	print_stack(t_stack s, char name);

int	main(int argc, char **argv)
{
	t_program	program;

	initialize_program(&program, argc);
	fill_stack_a(&program.stack_a, argv, &program);
	print_stack(program.stack_a, 'a');
	print_stack(program.stack_b, 'b');
	swap(SA, &program);
	print_stack(program.stack_a, 'a');
	print_stack(program.stack_b, 'b');
	push(PA, &program);
	print_stack(program.stack_a, 'a');
	print_stack(program.stack_b, 'b');
	push(PB, &program);
	print_stack(program.stack_a, 'a');
	print_stack(program.stack_b, 'b');
	exit_program(&program, NULL);
}

static void	print_stack(t_stack s, char name)
{
	ft_printf("%c : [ ", name);
	for (size_t i = 0; i <= s.top; i++)
	{
		ft_printf("%4i", s.values[i]);
		if (i < s.top)
			ft_printf(" | ");
	}
	ft_printf(" ]\n");
}
