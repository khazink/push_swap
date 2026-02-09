#include "libft.h"
#include "push_swap.h"

static void    sort_two(t_stack *a)
{
    if (a->value > a->next->value)
        sa(a);
}

static void    sort_three(t_stack *a)
{
    int first = a->value;
    int second = a->next->value;
    int third = a->next->next->value;

    if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first > third)
        ra(a);
    else if (first < second && second > third && first < third)
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && first > third)
        rra(a);
}

static void    sort_four(t_stack *a, t_stack *b)
{
    while (ft_lstsize(a) > 3)
    {
        int min_pos = find_min_position(a);
        move_to_top(a, min_pos);
        pb(&a, &b);
    }
    sort_three(a);
    pa(&a, &b);
}

void    sort_small(t_stack *a, t_stack *b)
{
    int size;

    size = ft_lstsize(a);
    if (size == 2)
        sort_two(a);
    else if (size == 3)
        sort_three(a);
    else if (size == 4)
        sort_four(a, b);
    else if (size == 5)
        sort_five(a, b);
}
