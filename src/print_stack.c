/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:15:51 by kkaman            #+#    #+#             */
/*   Updated: 2026/01/28 21:15:54 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stacks(t_stack *a, t_stack *b)
{
	printf("\n------- Debug -------\n");
	printf("  Stack A	Stack B \n");
	printf("-------------------------\n");
	while (a != NULL || b != NULL)
	{
		if (a)
		{
			printf("    %d", a->value);
			a = a->next;
		}
		else
			printf("    ");
		if (b)
		{
			printf("    %d", b->value);
			b = b->next;
		}
		printf("\n");
	}
	printf("----------------------\n\n");
}
