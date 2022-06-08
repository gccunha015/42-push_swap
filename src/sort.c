/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:22:51 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/06/08 15:44:32 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s);

void	sort(t_program *p)
{
	if (is_sorted(&p->a))
		return ;
	if (p->a.size < 6)
		return (sort_up_to_5(p));
	radix_sort(p);
}

int	is_sorted(t_stack *s)
{
	int	is_b;
	int	i;
	int	j;
	int	value[2];

	is_b = s->name == 'b';
	i = -1;
	while (++i < s->top)
	{
		value[0] = s->nodes[i].value;
		j = i;
		while (++j <= s->top)
		{
			value[1] = s->nodes[j].value;
			if ((!is_b && value[0] < value[1])
				|| (is_b && value[0] > value[1]))
				return (0);
		}
	}
	return (1);
}
