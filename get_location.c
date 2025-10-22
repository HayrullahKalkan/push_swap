#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, int *x, int *y)
{
	if (*x > 0 && *y > 0)
	{
		rr(a, b, 1);
		(*x)--;
		(*y)--;
	}
	else if (*x < 0 && *y < 0)
	{
		rrr(a, b, 1);
		(*x)++;
		(*y)++;
	}
}

static void	rotate_single(t_stack **stack, int *n, int type)
{
	if (*n > 0)
	{
		if (type == 0)
			ra(stack, 0);
		else
			rb(stack, 0);
		(*n)--;
	}
	else
	{
		if (type == 0)
			rra(stack, 0);
		else
			rrb(stack, 0);
		(*n)++;
	}
}

static void	get_location_utils(t_stack **a, t_stack **b, int *x, int *y)
{
	while (*x != 0 || *y != 0)
	{
		if ((*x > 0 && *y > 0) || (*x < 0 && *y < 0))
			rotate_both(a, b, x, y);
		else if (*x != 0)
			rotate_single(a, x, 0);
		else if (*y != 0)
			rotate_single(b, y, 1);
		else
			break ;
	}
}

void	get_location(t_stack **stack_a, t_stack **stackb)
{
	t_stack	*t_a;
	t_stack	*t_b;
	int		x;
	int		y;

	t_a = target_push(stack_a);
	t_b = min_stack_b(t_a, *stackb);
	x = t_a->cost;
	y = t_b->cost;
	while (*stack_a != t_a || *stackb != t_b)
		get_location_utils(stack_a, stackb, &x, &y);
	pb(stack_a, stackb);
}
