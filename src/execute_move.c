/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:14:03 by kkaman            #+#    #+#             */
/*   Updated: 2026/02/21 17:32:59 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	move_a_to_top(t_stack **a, t_stack *target_node)
{
	int	size;
	int	index;

	size = ft_size(*a);
	index = get_position(*a, target_node);
	if (index == 0)
		return ;
	if (index <= size / 2)
	{
		while (index > 0)
		{
			ra(a, 1);
			index--;
		}
	}
	else
	{
		while (index < size)
		{
			rra(a, 1);
			index++;
		}
	}
}

static void	move_b_to_top(t_stack **b, t_stack *cheap_node)
{
	int	size;
	int	index;

	size = ft_size(*b);
	index = get_position(*b, cheap_node);
	if (index == 0)
		return ;
	if (index <= size / 2)
	{
		while (index > 0)
		{
			rb(b, 1);
			index--;
		}
	}
	else
	{
		while (index < size)
		{
			rrb(b, 1);
			index++;
		}
	}
}

static void	do_rotate_both(t_stack **a, t_stack **b,
		t_stack *targ, t_stack *cur)
{
	while (*a != targ && *b != cur)
		rr(a, b, 1);
	move_a_to_top(a, targ);
	move_b_to_top(b, cur);
}

static void	do_rev_rotate_both(t_stack **a, t_stack **b,
			t_stack *targ, t_stack *cur)
{
	while (*a != targ && *b != cur)
		rrr(a, b, 1);
	move_a_to_top(a, targ);
	move_b_to_top(b, cur);
}

void	execute_move(t_stack **a, t_stack **b, t_stack *cheap_node)
{
	t_stack	*target;
	int		a_idx;
	int		b_idx;
	int		len_a;
	int		len_b;

	target = get_target(*a, cheap_node->index);
	len_a = ft_size(*a);
	len_b = ft_size(*b);
	a_idx = get_position(*a, target);
	b_idx = get_position(*b, cheap_node);
	if (max_val(a_idx, b_idx) == calculate_cost(*a, *b, target, cheap_node))
		do_rotate_both(a, b, target, cheap_node);
	else if (max_val((len_a - a_idx) % len_a, (len_b - b_idx) % len_b)
		== calculate_cost(*a, *b, target, cheap_node))
		do_rev_rotate_both(a, b, target, cheap_node);
	else
	{
		move_a_to_top(a, target);
		move_b_to_top(b, cheap_node);
	}
	pa(a, b, 1);
}
