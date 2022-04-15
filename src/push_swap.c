#include "push_swap.h"

static void	print_stacks(t_program p);

int	main(int argc, char **argv)
{
	t_program	program;

	initialize_program(&program, argc);
	fill_stack_a(&program.stack_a, argv, &program);
	print_stacks(program);
	push(PB, &program);
	push(PB, &program);
	push(PB, &program);
	print_stacks(program);
	rotate(RA, &program);
	rotate(RB, &program);
	print_stacks(program);
	exit_program(&program, NULL);
}

static void	print_stacks(t_program p)
{
	int	*a, *b;

	for (int i = 0; i < p.stack_a.size; i++)
	{
		a = stack_pop(&p.stack_a);
		b = stack_pop(&p.stack_b);
		if (a && b)
		{
			ft_printf("%5i | ", *a);
			ft_printf("%5i", *b);
		}
		else if (a)
			ft_printf("%5i | ", *a);
		if (a || b)
			ft_printf("\n");
	}
	ft_printf("----- | -----\n");
	ft_printf("%5c | %5c\n", 'a', 'b');
}
