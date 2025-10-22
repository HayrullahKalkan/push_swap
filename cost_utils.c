#include "push_swap.h"

void	find_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_a)
	{
		cost_total(tmp_a, min_stack_b(tmp_a, tmp_b));
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
