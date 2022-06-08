/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:22:51 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/06/08 15:32:45 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_min(t_stack *s, int ignore, int v_to_ignore);
int			get_max(t_stack *s, int ignore, int v_to_ignore);
static int	get_next_min_position(t_stack *s, int min);
static int	get_next_max_position(t_stack *s, int max);

int	get_position(int element, t_stack *s)
{
	int	min;
	int	max;

	if (!has_at_least_2_elements(s))
		return (-1);
	min = get_min(s, 0, 0);
	max = get_max(s, 0, 0);
	while (min != -1 || max != -1)
	{
		if (element < s->nodes[min].value)
			return (get_next_min_position(s, min));
		if (element > s->nodes[max].value)
			return (get_next_max_position(s, max));
		min = get_min(s, 1, s->nodes[min].value);
		max = get_max(s, 1, s->nodes[max].value);
	}
	return (-1);
}

int	get_min(t_stack *s, int ignore, int v_to_ignore)
{
	int	min;
	int	i;

	min = -1;
	i = -1;
	while (++i <= s->top)
	{
		if (ignore && s->nodes[i].value <= v_to_ignore)
			continue ;
		if (min == -1 || s->nodes[i].value < s->nodes[min].value)
			min = i;
	}
	return (min);
}

int	get_max(t_stack *s, int ignore, int v_to_ignore)
{
	int	max;
	int	i;

	max = -1;
	i = -1;
	while (++i <= s->top)
	{
		if (ignore && s->nodes[i].value >= v_to_ignore)
			continue ;
		if (max == -1 || s->nodes[i].value > s->nodes[max].value)
			max = i;
	}
	return (max);
}

static int	get_next_min_position(t_stack *s, int min)
{
	if (s->name == 'b')
	{
		if (min == 0)
			min = s->top;
		else if (min == s->top)
			min = s->top - 1;
	}
	return (min);
}

static int	get_next_max_position(t_stack *s, int max)
{
	if (s->name == 'a')
	{
		if (max == 0)
			max = s->top;
		else if (max == s->top)
			max = s->top - 1;
	}
	return (max);
}
