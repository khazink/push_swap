#include "libft.h"
#include "push_swap.h"

static t_stack *get_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static void	rotate(t_stack **stack)
{
	t_stack	*old_head;
	t_stack *new_head;
	t_stack *tail;

	if (!*stack || !(*stack)->next)
		return ;
	old_head = *stack;
	new_head = old_head->next;
	tail = get_last_node(*stack);
	*stack = new_head;
	new_head->prev = NULL;
	old_head->prev = NULL;
	tail->next = old_head;
	old_head->prev = tail;
	old_head->next = NULL;
}

void	ra(t_stack **a, int to_print)
{
	rotate(a);
	if (to_print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int to_print)
{
	rotate(b);
	if (to_print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int to_print)
{
	rotate(a);
	rotate(b);
	if (to_print)
		write(1, "rr\n", 3);
}
