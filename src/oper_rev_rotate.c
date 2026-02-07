/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:00:59 by kkaman            #+#    #+#             */
/*   Updated: 2026/02/07 14:45:13 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*old_head;
	t_stack	*new_head;
	t_stack	*new_tail;

	if (!*stack || !(*stack)->next)
		return ;
	old_head = *stack;
	new_head = get_last_node(*stack);
	new_tail = new_head->prev;
	*stack = new_head;
	new_head->prev = NULL;
	new_head->next = old_head;
	old_head->prev = new_head;
	new_tail->next = NULL;
}

void	rra(t_stack **a, int to_print)
{
	reverse_rotate(a);
	if (to_print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int to_print)
{
	reverse_rotate(b);
	if (to_print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int to_print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (to_print)
		write(1, "rrr\n", 4);
}
