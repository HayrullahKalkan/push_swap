#include "push_swap.h"

void cost_accounting(t_stack **stack_a)
{
	t_stack *tmp;
	int size;
	int i;

	tmp = *stack_a;
	size = lstsize(tmp);
	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		if (i <= size / 2)
			tmp->cost = i;
		else
			tmp->cost = i - size;
		i++;
		tmp = tmp->next;
	}
}

void cost_total(t_stack *stack_a, t_stack *stack_b)
{
    int a_abs;
    int b_abs;

    if (!stack_a)
        return;
    if (!stack_b)
    {
        stack_a->tot_cos = (stack_a->cost < 0) ? -stack_a->cost : stack_a->cost;
        return;
    }
    a_abs = (stack_a->cost < 0) ? -stack_a->cost : stack_a->cost;
    b_abs = (stack_b->cost < 0) ? -stack_b->cost : stack_b->cost;
    if ((stack_a->cost >= 0 && stack_b->cost >= 0) ||
        (stack_a->cost <= 0 && stack_b->cost <= 0))
        stack_a->tot_cos = (a_abs > b_abs) ? a_abs : b_abs;
    else
        stack_a->tot_cos = a_abs + b_abs;
}

t_stack *find_biggest(t_stack *stack_b)
{
    t_stack *tmp_b = stack_b;
    t_stack *best = NULL;
    int biggest = -2147483648;

    while (tmp_b)
    {
        if (tmp_b->data > biggest)
        {
            biggest = tmp_b->data;
            best = tmp_b;
        }
        tmp_b = tmp_b->next;
    }
    return (best);
}

t_stack *min_stack_b(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp_b;
    t_stack *best;
    int max;

	tmp_b = stack_b;
	best = NULL;
	max = -2147483648;
    while (tmp_b)
    {
        if (tmp_b->data < stack_a->data && tmp_b->data > max)
        {
            max = tmp_b->data;
            best = tmp_b;
        }
        tmp_b = tmp_b->next;
    }
    if (best == NULL)
        best = find_biggest(stack_b);
    return (best);
}
t_stack *target_push(t_stack **stack_a)
{
	t_stack *tmp;
	t_stack *target;
	int min;

	tmp = (*stack_a);
	min = 2147483647;
	while (tmp)
	{
		if(tmp->tot_cos < min)
		{
			min = tmp->tot_cos;
			target = tmp;
		}
		tmp = tmp->next;
	}
	return target;
}

static void	rotate_both(t_stack **a, t_stack **b, int *x, int *y)
{
	if (*x > 0 && *y > 0)
		(rr(a, b, 1), (*x)--, (*y)--);
	else if (*x < 0 && *y < 0)
		(rrr(a, b, 1), (*x)++, (*y)++);
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
			break;
	}
}

void	get_location(t_stack **a, t_stack **b)
{
	t_stack	*t_a;
	t_stack	*t_b;
	int		x;
	int		y;

	t_a = target_push(a);
	t_b = min_stack_b(t_a, *b);
	x = t_a->cost;
	y = t_b->cost;
	while (*a != t_a || *b != t_b)
		get_location_utils(a, b, &x, &y);
	pb(a, b);
}

void find_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;
	
	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_a)
	{
		cost_total(tmp_a, min_stack_b(tmp_a,tmp_b));
		tmp_a = tmp_a->next;
	}
}

static t_stack	*find_max_node(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*max_node;
	int		max;

	tmp = a;
	max = -2147483648;
	max_node = a;
	while (tmp)
	{
		if (tmp->data > max)
		{
			max = tmp->data;
			max_node = tmp;
		}
		tmp = tmp->next;
	}
	return (max_node);
}

t_stack	*find_target_in_a(t_stack *a, int val)
{
	t_stack	*tmp;
	t_stack	*target;
	int		min_diff;

	tmp = a;
	target = NULL;
	min_diff = 2147483647;
	while (tmp)
	{
		if (tmp->data > val && (tmp->data - val) < min_diff)
		{
			min_diff = tmp->data - val;
			target = tmp;
		}
		tmp = tmp->next;
	}
	if (!target)
		target = find_max_node(a);
	return (target);
}



