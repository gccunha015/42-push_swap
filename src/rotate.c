/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:22:50 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/06/08 15:22:50 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_rotate(t_stack *s)
{
	int	i;

	if (!has_at_least_2_elements(s))
		return (0);
	i = 0;
	while (++i <= s->top)
		swap(&s->nodes[0], &s->nodes[i]);
	return (1);
}

int	ra(t_program *p)
{
	return (_rotate(&p->a));
}

int	rb(t_program *p)
{
	return (_rotate(&p->b));
}

int	rr(t_program *p)
{
	if (!has_at_least_2_elements(&p->a) || !has_at_least_2_elements(&p->b))
		return (0);
	return (ra(p) && rb(p));
}
