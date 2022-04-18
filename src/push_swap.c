#include "push_swap.h"

static void	print_stacks(t_program p, char *state);

int	main(int argc, char **argv)
{
	t_program	program;

	initialize_program(&program, argc);
	fill_stack_a(&program.stack_a, argv, &program);
	print_stacks(program, "Original");
	/*
	sort(&program);
	print_stacks(program, "Sorted");
	*/
	exit_program(&program, EXIT_SUCCESS);
}

static void	print_stacks(t_program p, char *state)
{
	int	*a, *b;
	char	*separator = "-----------";

	ft_printf("%s :\n", state);
	ft_printf("| %s | %s |\n", separator, separator);
	for (int i = 0; i < p.stack_a.size; i++)
	{
		a = stack_pop(&p.stack_a);
		b = stack_pop(&p.stack_b);
		if (a && b)
			ft_printf("| %11i | %11i ", *a, *b);
		else if (a)
			ft_printf("| %11i | %11c ", *a, ' ');
		else if (b)
			ft_printf("| %11c | %11i ", ' ', *b);
		if (a || b)
			ft_printf("|\n");
	}
	ft_printf("| %s | %s |\n", separator, separator);
	ft_printf("| %11c | %11c |\n", 'a', 'b');
	ft_printf("| %s | %s |\n", separator, separator);
}
