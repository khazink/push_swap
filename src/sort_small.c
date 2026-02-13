/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:06:27 by kkaman            #+#    #+#             */
/*   Updated: 2026/02/13 19:15:50 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	find_min_position(t_stack *stack)
{
	t_stack	*tmp;
	int		min_index;
	int		min_pos;
	int		current_pos;

	if (!stack)
		return (-1);
	tmp = stack;
	min_index = tmp->index;
	min_pos = 0;
	current_pos = 0;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = current_pos;
		}
		tmp = tmp->next;
		current_pos++;
	}
	return (min_pos);
}

static void	move_to_top(t_stack **a, int min_pos)
{
	int	size;

	size = ft_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a, 1);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a, 1);
			min_pos++;
		}
	}
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, 1);
	else if (first > second && second > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(a, 1);
}

static void	sort_five(t_stack **a, t_stack **b)
{
	int	min_pos;

	while (ft_size(*a) > 3)
	{
		min_pos = find_min_position(*a);
		move_to_top(a, min_pos);
		pb(a, b, 1);
	}
	sort_three(a);
	while (*b)
		pa(a, b, 1);
}

void	sort_small(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, 1);
	}
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
}
