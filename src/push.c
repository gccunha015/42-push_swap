/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:22:51 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/06/08 15:22:51 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_push(t_stack *source, t_stack *target)
{
	if (is_empty(source) || is_full(target))
		return (0);
	push(target, *pop(source));
	return (1);
}

int	pa(t_program *p)
{
	return (_push(&p->b, &p->a));
}

int	pb(t_program *p)
{
	return (_push(&p->a, &p->b));
}
