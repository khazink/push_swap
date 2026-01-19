#include "push_swap.h"
#include <stdio.h>

void	print_stacks(t_stack *a, t_stack *b)
{
	printf("\n------- Debug -------\n");
	printf("  Stack A	Stack B ");
	printf("-------------------------");
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
