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

void get_location(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *target_a;
	t_stack *target_b;
	int a;
	int b;
	
	target_a = target_push(stack_a);
	target_b = min_stack_b(target_a, *stack_b);
	a = target_a->cost;
	b = target_b->cost;
	while (*stack_a != target_a || *stack_b != target_b)
	{
		if(a > 0 && b > 0)
		{
			rr(stack_a, stack_b,1);
    		a--;
    		b--;
		}
		else if(a < 0 && b < 0)
		{
			rrr(stack_a, stack_b,1);
    		a++;
    		b++;
		}
		else if(a != 0)
		{
    		if(a > 0)
        		ra(stack_a,0), a--;
    		else
        		rra(stack_a,0), a++;
		}
		else if(b != 0)
		{
    		if(b > 0)
        		rb(stack_b,0), b--;
    		else
        		rrb(stack_b,0), b++; 
		}
		else 
			break;
	}
	pb(stack_a,stack_b);
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
t_stack *find_target_in_a(t_stack *stack_a, int value)
{
    t_stack *tmp = stack_a;
    t_stack *target = NULL;
    int min_diff = 2147483647;

    while (tmp)
    {
        if (tmp->data > value && (tmp->data - value) < min_diff)
        {
            min_diff = tmp->data - value;
            target = tmp;
        }
        tmp = tmp->next;
    }
    if (!target)
    {
        tmp = stack_a;
        int max = -2147483648;
        while (tmp)
        {
            if (tmp->data > max)
            {
                max = tmp->data;
                target = tmp;
            }
            tmp = tmp->next;
        }
    }
    return target;
}


