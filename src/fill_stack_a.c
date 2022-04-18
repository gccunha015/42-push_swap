#include "push_swap.h"

static void	check_if_is_integer(char *arg, int value, t_program *p);
static void	check_if_is_duplicate(t_stack *a, t_program *p);

void	fill_stack_a(t_stack *a, char **argv, t_program *p)
{
	int	i;

	argv++;
	i = a->size;
	while (--i >= 0)
	{
		stack_push(a, ft_atoi(argv[i]));
		check_if_is_integer(argv[i], a->values[a->top], p);
		check_if_is_duplicate(a, p);
	}
}

static void	check_if_is_integer(char *arg, int value, t_program *p)
{
	if ((!value && ft_strncmp(arg, "0", ft_strlen(arg)))
		|| (value == -1 && ft_strncmp(arg, "-1", ft_strlen(arg))))
		exit_program(p, EXIT_FAILURE);
}

static void	check_if_is_duplicate(t_stack *a, t_program *p)
{
	int	i;

	i = -1;
	while (++i < a->top)
		if (a->values[i] == a->values[a->top])
			exit_program(p, EXIT_FAILURE);
}
