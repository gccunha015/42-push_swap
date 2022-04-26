#include "push_swap.h"

void	print_stacks(t_stack a, t_stack b);

int	main(int argc, char **argv)
{
	t_program	program;

	initialize_program(&program, argc);
	fill_stack_a(&program, argv);
	sort(&program.a, &program.b);
	exit_program(&program, EXIT_SUCCESS);
}

void	print_stacks(t_stack a, t_stack b)
{
	t_node	*na, *nb;
	char	*separator = "-------------------";

	ft_printf("|%s|%s|\n", separator, separator);
	for (int i = a.size - 1; i > -1; i--)
	{
		na = NULL;
		nb = NULL;
		if (a.top == i)
			na = stack_pop(&a);
		if (b.top == i)
			nb = stack_pop(&b);
		if (na && nb)
		{
			ft_printf("| [%3i] %11i ", na->index, na->value);
			ft_printf("| [%3i] %11i ", nb->index, nb->value);
		}
		else if (na)
		{
			ft_printf("| [%3i] %11i ", na->index, na->value);
			ft_printf("| %17c ", ' ');
		}
		else if (nb)
		{
			ft_printf("| %17c ", ' ');
			ft_printf("| [%3i] %11i ", nb->index, nb->value);
		}
		if (na || nb)
			ft_printf("|\n");
	}
	ft_printf("|%s|%s|\n", separator, separator);
	ft_printf("| %17c | %17c |\n", 'a', 'b');
	ft_printf("|%s|%s|\n", separator, separator);
}
