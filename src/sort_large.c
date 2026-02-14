/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:54:05 by kkaman            #+#    #+#             */
/*   Updated: 2026/02/13 22:58:35 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack	*get_min_node(t_stack *stack)
{
	long	min_val;
	t_stack	*min_node;

	min_val = LONG_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->index < min_val)
		{
			min_val = stack->index;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
t_stack	*get_target(t_stack *a, int b_index)
{
	t_stack	*target_node;
	t_stack *current_a;
	long	best_match_index;

	current_a = a;
	target_node = NULL;
	best_match_index = LONG_MAX;
	while (current_a)
	{
		if (current_a->index > b_index && current_a->index < best_match_index)
		{
			best_match_index = current_a->index;
			target_node = current_a;
		}
		current_a = current_a->next;
	}

	if (best_match_index == LONG_MAX)
		return (get_min_node(a));
	return (target_node);
}

static t_stack	*get_cheapest_node(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack *cheapest_node;
	t_stack *target;
	int	min_cost;
	int	cost;

	current_b = b;
	cheapest_node = NULL;
	min_cost = INT_MAX;
	while (current_b)
	{
		//1. find where number belong A
		target = get_target(a, current_b->index);
		//2. Calculate the move to get both to the top
		cost = calculate_cost(a, b, target, current_b);
		//3. Compare if this is the cheapest
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest_node = current_b;
		}
		//4. Move current_b to current_b next
		current_b = current_b->next;
	}
	return (cheapest_node);
}

void	sort_large(t_stack **a, t_stack **b)
{
	t_stack	*cheap_node;

	while (ft_size(*a) > 3)
		pb(a, b, 1);
	sort_three(a);
	cheap_node = get_cheapest_node(*a, *b);
}
