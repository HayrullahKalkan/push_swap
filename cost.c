/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:45:45 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/21 21:45:45 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_accounting(t_stack **stack_a)
{
	t_stack	*tmp;
	int		size;
	int		i;

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

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	cost_total(t_stack *stack_a, t_stack *stack_b)
{
	int	a_abs;
	int	b_abs;

	if (!stack_a)
		return ;
	if (!stack_b)
	{
		stack_a->tot_cos = ft_abs(stack_a->cost);
		return ;
	}
	a_abs = ft_abs(stack_a->cost);
	b_abs = ft_abs(stack_b->cost);
	if ((stack_a->cost >= 0 && stack_b->cost >= 0)
		|| (stack_a->cost <= 0 && stack_b->cost <= 0))
	{
		if (a_abs > b_abs)
			stack_a->tot_cos = a_abs;
		else
			stack_a->tot_cos = b_abs;
	}
	else
		stack_a->tot_cos = a_abs + b_abs;
}


t_stack	*find_biggest(t_stack *stack_b)
{
	t_stack	*tmp_b;
	t_stack	*best;
	int		biggest;

	tmp_b = stack_b;
	best = NULL;
	biggest = -2147483648;
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

t_stack	*min_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp_b;
	t_stack	*best;
	int		max;

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

t_stack	*target_push(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*target;
	int		min;

	tmp = (*stack_a);
	min = 2147483647;
	while (tmp)
	{
		if (tmp->tot_cos < min)
		{
			min = tmp->tot_cos;
			target = tmp;
		}
		tmp = tmp->next;
	}
	return (target);
}
