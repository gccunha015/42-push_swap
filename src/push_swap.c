#include "push_swap.h"

void	print_stacks(t_program p);

int	main(int argc, char **argv)
{
	t_program	program;

	initialize_program(&program, argc);
	fill_stack_a(&program, argv);
	sort(&program);
	exit_program(&program, EXIT_SUCCESS);
}

void	print_stacks(t_program p)
{
	t_node	*a, *b;
	char	*separator = "-------------------";

	ft_printf("|%s|%s|\n", separator, separator);
	for (int i = p.stack_a.size - 1; i > -1; i--)
	{
		a = NULL;
		b = NULL;
		if (p.stack_a.top == i)
			a = stack_pop(&p.stack_a);
		if (p.stack_b.top == i)
			b = stack_pop(&p.stack_b);
		if (a && b)
		{
			ft_printf("| [%3i] %11i ", a->index, a->value);
			ft_printf("| [%3i] %11i ", b->index, b->value);
		}
		else if (a)
		{
			ft_printf("| [%3i] %11i ", a->index, a->value);
			ft_printf("| %17c ", ' ');
		}
		else if (b)
		{
			ft_printf("| %17c ", ' ');
			ft_printf("| [%3i] %11i ", b->index, b->value);
		}
		if (a || b)
			ft_printf("|\n");
	}
	ft_printf("|%s|%s|\n", separator, separator);
	ft_printf("| %17c | %17c |\n", 'a', 'b');
	ft_printf("|%s|%s|\n", separator, separator);
}
