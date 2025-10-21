/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:01:33 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/21 20:05:31 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_node_to_top(t_stack **stack, t_stack *node)
{
	int		pos;
	int		size;
	t_stack	*tmp;

	pos = 0;
	tmp = *stack;
	if (!stack || !*stack || !node)
		return ;
	while (tmp && tmp != node)
	{
		tmp = tmp->next;
		pos++;
	}
	size = lstsize(*stack);
	if (pos <= size / 2)
	{
		while (*stack != node)
			ra(stack, 0);
	}
	else
	{
		while (*stack != node)
			rra(stack, 0);
	}
}

static t_stack	*find_min_node_pos(t_stack *stack, int *min_pos)
{
	t_stack	*tmp;
	t_stack	*min_node;
	int		pos;

	tmp = stack;
	min_node = stack;
	pos = 0;
	*min_pos = 0;
	while (tmp)
	{
		if (tmp->data < min_node->data)
		{
			min_node = tmp;
			*min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_node);
}

void	bring_min_to_top(t_stack **stack_a)
{
	t_stack	*min_node;
	int		size;
	int		min_pos;

	if (!stack_a || !*stack_a)
		return ;
	min_node = find_min_node_pos(*stack_a, &min_pos);
	size = lstsize(*stack_a);
	if (min_pos <= size / 2)
		while (*stack_a != min_node)
			ra(stack_a, 0);
	else
		while (*stack_a != min_node)
			rra(stack_a, 0);
}
