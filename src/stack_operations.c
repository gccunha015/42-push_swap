/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:22:50 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/06/08 15:22:50 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *s)
{
	return (s->top == -1);
}

int	has_at_least_2_elements(t_stack *s)
{
	return (s->top > 0);
}

int	is_full(t_stack *s)
{
	return (s->top == s->size - 1);
}

void	push(t_stack *s, t_node n)
{
	if (is_full(s))
		return ;
	s->nodes[++s->top] = n;
}

t_node	*pop(t_stack *s)
{
	if (is_empty(s))
		return (NULL);
	return (&s->nodes[s->top--]);
}
