/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:52:16 by kkaman            #+#    #+#             */
/*   Updated: 2026/01/28 21:25:08 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/* ************************************************************************** */
/* TEST MAIN for Push_Swap Operations                                       */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // Required for printf

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	// 1. CRITICAL: Initialize b to NULL to avoid segfaults on the first pb
	b = NULL;

	// 2. Parse args (Run with: ./push_swap 5 1 4 2 8)
	if (argc < 2)
		return (0);
	a = parse_arg(argc, argv);
	
	printf("\n=== INITIAL STATE ===");
	print_stacks(a, b);

	// --- SWAP TESTS ---
	printf("\n=== TEST: SA (Swap A) ===\n");
	sa(&a, 1);
	print_stacks(a, b);

	printf("\n=== TEST: PB (Push to B x3) ===\n");
	pb(&a, &b, 1);
	pb(&a, &b, 1);
	pb(&a, &b, 1); // Pushing 3 nodes to B so we can test B operations
	print_stacks(a, b);

	printf("\n=== TEST: SB (Swap B) ===\n");
	sb(&b, 1);
	print_stacks(a, b);

	printf("\n=== TEST: SS (Swap Both) ===\n");
	ss(&a, &b, 1);
	print_stacks(a, b);

	// --- ROTATE TESTS ---
	printf("\n=== TEST: RA (Rotate A) ===\n");
	ra(&a, 1);
	print_stacks(a, b);

	printf("\n=== TEST: RB (Rotate B) ===\n");
	rb(&b, 1);
	print_stacks(a, b);

	printf("\n=== TEST: RR (Rotate Both) ===\n");
	rr(&a, &b, 1);
	print_stacks(a, b);

	// --- REVERSE ROTATE TESTS ---
	printf("\n=== TEST: RRA (Reverse Rotate A) ===\n");
	rra(&a, 1);
	print_stacks(a, b);

	printf("\n=== TEST: RRB (Reverse Rotate B) ===\n");
	rrb(&b, 1);
	print_stacks(a, b);

	printf("\n=== TEST: RRR (Reverse Rotate Both) ===\n");
	rrr(&a, &b, 1);
	print_stacks(a, b);

	// --- PUSH BACK TESTS ---
	printf("\n=== TEST: PA (Push back to A) ===\n");
	while (b)
	{
		pa(&a, &b, 1);
		print_stacks(a, b);
	}

	// --- CLEANUP ---
	printf("\n=== CLEANUP ===\n");
	free_stack(&a);
	free_stack(&b); // Safe to call even if b is NULL (assuming your free handles it)

	return (0);
}
