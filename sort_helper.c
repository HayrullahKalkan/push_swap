/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:40:48 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/21 19:40:48 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int		a;
	int		b;
	int		c;

	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (a > b && b < c && a < c)
		sa(stack, 0);
	else if (a > b && b > c)
	{
		sa(stack, 0);
		rra(stack, 0);
	}
	else if (a > b && b < c && a > c)
		ra(stack, 0);
	else if (a < b && b > c && a < c)
	{
		rra(stack, 0);
		sa(stack, 0);
	}
	else if (a < b && b > c && a > c)
		rra(stack, 0);
}

t_stack	*find_min_node(t_stack *stack)
{
	t_stack		*tmp;
	t_stack		*min;

	tmp = stack;
	min = stack;
	if (!stack)
		return (NULL);
	while (tmp)
	{
		if (tmp->data < min->data)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	first_two_push(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*min;
	int		size;

	if (!stack_a || !*stack_a)
		return ;
	i = 0;
	size = lstsize(*stack_a);
	if (size > 5)
	{
		pb(stack_a, stack_b);
		if (*stack_a)
			pb(stack_a, stack_b);
		return ;
	}
	while (i < 2 && *stack_a)
	{
		min = find_min_node(*stack_a);
		bring_node_to_top(stack_a, min);
		pb(stack_a, stack_b);
		i++;
	}
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*target_a;
	int			i;

	while (*stack_b)
	{
		i = 0;
		target_a = lstlast(*stack_a);
		while (i < 3)
		{
			target_a = lstlast(*stack_a);
			if (target_a->data > (*stack_b)->data
				&& target_a->data < (*stack_a)->data)
				rra(stack_a, 0);
			else if (lstsize(*stack_a) == 3
				&& target_a->data > (*stack_b)->data)
				rra(stack_a, 0);
			i++;
		}
		pa(stack_a, stack_b);
	}
}

void	bring_node_to_top_b(t_stack **stack_b, t_stack *node)
{
	int		pos;
	int		size;
	t_stack	*tmp;

	pos = 0;
	tmp = *stack_b;
	if (!stack_b || !*stack_b || !node)
		return ;
	while (tmp && tmp != node)
	{
		tmp = tmp->next;
		pos++;
	}
	size = lstsize(*stack_b);
	if (pos <= size / 2)
	{
		while (*stack_b != node)
			rb(stack_b, 0);
	}
	else
	{
		while (*stack_b != node)
			rrb(stack_b, 0);
	}
}

