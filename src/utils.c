/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:23:13 by kkaman            #+#    #+#             */
/*   Updated: 2026/02/20 17:00:16 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	ft_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	get_position(t_stack *stack, t_stack *node)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack == node)
			return (i);
		stack = stack->next;
		i++;
	}
	return (0);
}
