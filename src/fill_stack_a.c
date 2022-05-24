#include "push_swap.h"

static void	check_if_is_integer(char *arg, int value, t_program *p);
static void	check_if_is_duplicate(t_program *p);
static void	index_values(t_stack *a);

void	fill_stack_a(t_program *p, char **argv)
{
	int	i;

	i = p->a.size;
	while (--i > -1)
	{
		push(&p->a, (t_node){ft_atoi(argv[i]), 0});
		check_if_is_integer(argv[i], p->a.nodes[p->a.top].value, p);
		check_if_is_duplicate(p);
	}
	index_values(&p->a);
}

static void	check_if_is_integer(char *arg, int value, t_program *p)
{
	size_t	arg_len;

	arg_len = ft_strlen(arg);
	if ((!value && ft_strncmp(arg, "0", arg_len))
		|| (value == -1 && ft_strncmp(arg, "-1", arg_len)))
		exit_program(p, EXIT_FAILURE);
}

static void	check_if_is_duplicate(t_program *p)
{
	int	i;

	i = -1;
	while (++i < p->a.top)
		if (p->a.nodes[i].value == p->a.nodes[p->a.top].value)
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
				a->nodes[i].index++;
	}
}
