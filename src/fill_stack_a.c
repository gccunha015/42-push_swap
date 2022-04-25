#include "push_swap.h"

static void	check_if_is_integer(char *arg, int value, t_program *p);
static void	check_if_is_duplicate(t_stack *a, t_program *p);
static void	index_values(t_stack *a);

void	fill_stack_a(t_program *p, char **argv)
{
	t_stack *a;
	int	i;

	argv++;
	a = &p->stack_a;
	i = a->size;
	while (--i >= 0)
	{
		stack_push(a, (t_node){ft_atoi(argv[i]), a->size - 1});
		check_if_is_integer(argv[i], a->nodes[a->top].value, p);
		check_if_is_duplicate(a, p);
	}
	index_values(a);
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
		if (a->nodes[i].value == a->nodes[a->top].value)
			exit_program(p, EXIT_FAILURE);
}

static void	index_values(t_stack *a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < a->size)
	{
		j = -1;
		while (++j < a->size)
			if (a->nodes[i].value < a->nodes[j].value)
				a->nodes[i].index--;
	}
}
