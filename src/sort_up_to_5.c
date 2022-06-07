#include "push_swap.h"

static void	fill_b(t_program *p);
static void	sort_up_to_3(t_program *p);
static void	return_to_a(t_program *p);
static void	resort_a(t_program *p);

void	sort_up_to_5(t_program *p)
{
	fill_b(p);
	sort_up_to_3(p);
	return_to_a(p);
	resort_a(p);
}

static void	fill_b(t_program *p)
{
	while (p->a.top > 2)
		execute(PB, p);
}

static void	sort_up_to_3(t_program *p)
{
	int	operation;

	while (!is_sorted(&p->a))
	{
		if (get_max(&p->a, 0, 0) == p->a.top)
			operation = RA;
		else if (get_min(&p->a, 0, 0) == 0)
			operation = RRA;
		else
			operation = SA;
		execute(operation, p);
	}
}

static void	return_to_a(t_program *p)
{
	int	pos;

	while (!is_empty(&p->b))
	{
		pos = get_position(p->b.nodes[p->b.top].value, &p->a);
		if (pos == p->a.top)
			execute(PA, p);
		else if (pos >= p->a.top / 2)
			execute(RA, p);
		else
			execute(RRA, p);
	}
}

static void	resort_a(t_program *p)
{
	while (!is_sorted(&p->a))
	{
		if (get_min(&p->a, 0, 0) >= p->a.top / 2)
			execute(RA, p);
		else
			execute(RRA, p);
	}
}
