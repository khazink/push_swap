/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_alignment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:53:52 by kkaman            #+#    #+#             */
/*   Updated: 2026/02/21 14:53:54 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static t_stack	*get_min_node(t_stack *stack)
{
	long	min;
	t_stack	*min_node;

	min = LONG_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void	final_alignment(t_stack **a)
{
	t_stack	*min_node;

	min_node = get_min_node(*a);
	move_a_to_top(a, min_node);
}
