#include "push_swap.h"

static void	check_if_is_integer(char *arg, int value, t_program *p);
static void	check_if_is_duplicate(t_stack *a, t_program *p);
static void	index_values(int *indices, t_stack *a, int i);

void	fill_stack_a(t_program *p, char **argv)
{
	t_stack *a;
	int	i;

	a = &p->stack_a;
	argv++;
	i = a->size;
	while (--i >= 0)
	{
		stack_push(a, ft_atoi(argv[i]));
		check_if_is_integer(argv[i], a->values[a->top], p);
		check_if_is_duplicate(a, p);
		index_values(p->indices, a, i);
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

static void	index_values(int *indices, t_stack *a, int i)
{
	int	j;
	int	k;

	j = a->size - 1 - i;
	indices[j] = a->values[a->top];
	k = -1;
	while (++k < j)
		if (indices[k] > indices[j])
			swap_values(&indices[k], &indices[j]);
}
