/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:22:50 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/06/08 15:22:50 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_reverse_rotate(t_stack *s)
{
	int	i;

	if (!has_at_least_2_elements(s))
		return (0);
	i = s->top + 1;
	while (--i > -1)
		swap(&s->nodes[0], &s->nodes[i]);
	return (1);
}

int	rra(t_program *p)
{
	return (_reverse_rotate(&p->a));
}

int	rrb(t_program *p)
{
	return (_reverse_rotate(&p->b));
}

int	rrr(t_program *p)
{
	if (!has_at_least_2_elements(&p->a) || !has_at_least_2_elements(&p->b))
		return (0);
	return (rra(p) && rrb(p));
}
