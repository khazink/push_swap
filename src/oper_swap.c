/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:38:29 by kkaman            #+#    #+#             */
/*   Updated: 2026/02/05 00:31:06 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	swap(t_stack *stack)
{
	int	tmp_val;
	int	tmp_idx;

	if (!stack || !stack->next)
		return (0);
	tmp_val = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp_val;
	tmp_idx = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp_indx;
	return (1);
}

void	sa(t_stack **a, int to_print)
{
	if (swap(*a) && to_print)
		write (1, "sa\n", 3);
}

void	sb(t_stack **b, int to_print)
{
	if (swap(*b) && to_print)
		write (1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int to_print)
{
	int	a_swap;
	int	b_swap;

	if (*a && (*a)->next)
		a_swap = 1;
	else
		a_swap = 0;
	if (*b && (*b)->next)
		b_swap = 1;
	else
		b_swap = 0;
	if (!a_swap && !b_swap)
		return ;
	sa(a, 0);
	sb(b, 0);
	if (to_print)
		write(1, "ss\n", 3);
}
