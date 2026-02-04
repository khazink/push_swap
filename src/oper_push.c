/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:40:29 by kkaman            #+#    #+#             */
/*   Updated: 2026/02/05 00:40:30 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*push_node;

	if (!src || !*src || !dest)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

//take first element in b and put it on top of a. Do nothing if empty
void	pa(t_stack **a, t_stack **b, int to_print)
{
	if (!b || !*b)
		return ;
	push(a, b);
	if (to_print)
		write(1, "pa\n", 3);
}

//take first element of a and put it on top of b. Do nothing if empty
//move first a element to on top of b. if b have something
void	pb(t_stack **a, t_stack **b, int to_print)
{
	if (!a || !*a)
		return ;
	push(b, a);
	if (to_print)
		write(1, "pb\n", 3);
}
