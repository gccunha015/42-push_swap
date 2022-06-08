/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:22:50 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/06/08 15:41:41 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bucket_sort(int bit, t_program *p);

void	radix_sort(t_program *p)
{
	int	bit_count;
	int	bit;

	bit_count = 0;
	while (p->a.top >> bit_count)
		bit_count++;
	bit = -1;
	while (++bit < bit_count)
		bucket_sort(bit, p);
}

void	bucket_sort(int bit, t_program *p)
{
	int	i;
	int	should_push;	

	i = -1;
	while (++i < p->a.size)
	{
		should_push = (p->a.nodes[p->a.top].index >> bit) & 1;
		if (should_push)
			execute(PB, p);
		else
			execute(RA, p);
	}
	while (!is_empty(&p->b))
		execute(PA, p);
}
