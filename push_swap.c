/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:31:00 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/21 21:35:47 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_sort(t_stack **a)
{
	int	size;

	size = lstsize(*a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(a, 1);
	}
	else if (size == 3)
		sort_three(a);
}

static void	first_push_ops(t_stack **a, t_stack **b)
{
	first_two_push(a, b);
	if (*a)
		cost_accounting(a);
	if (*b)
		cost_accounting(b);
	find_target(a, b);
}

static void	loop_sort(t_stack **a, t_stack **b)
{
	while (lstsize(*a) > 3)
	{
		get_location(a, b);
		if (*a)
			cost_accounting(a);
		if (*b)
			cost_accounting(b);
		find_target(a, b);
	}
}

static void	final_sort(t_stack **a, t_stack **b)
{
	t_stack	*max_b;

	small_sort(a);
	if (*b)
	{
		max_b = find_biggest(*b);
		bring_node_to_top_b(b, max_b);
		push_back_to_a(a, b);
	}
	bring_min_to_top(a);
}

void	turk_sort(t_stack **a)
{
	t_stack	*b;
	int		size;

	if (!a || !*a)
		return ;
	b = NULL;
	size = lstsize(*a);
	if (size <= 3)
		return (small_sort(a));
	first_push_ops(a, &b);
	loop_sort(a, &b);
	final_sort(a, &b);
	lstclear(a);
}

int	main(int ac, char **argv)
{
	int		*arr;
	t_stack	*stack;
	int		i;

	stack = NULL;
	if (ac > 1)
	{
		arr = checker(argv, &i);
		if (arr == NULL)
			return (0);
		stack = parser(arr, i);
		turk_sort(&stack);
	}
	else
		return (0);
}
