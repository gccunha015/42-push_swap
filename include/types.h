/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:22:51 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/06/08 15:51:25 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_node
{
	int	value;
	int	index;
}	t_node;

typedef struct s_stack
{
	t_node	*nodes;
	char	name;
	int		size;
	int		top;
}	t_stack;

typedef struct s_program
{
	t_stack	a;
	t_stack	b;
}	t_program;

#endif
