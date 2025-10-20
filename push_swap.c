/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:31:00 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/19 21:25:26 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void turk_sort(t_stack **stack)
{
    t_stack *stack_b = NULL;

    first_two_push(stack, &stack_b);
    cost_accounting(stack);
    cost_accounting(&stack_b);
    find_target(stack, &stack_b);
    while (lstsize(*stack) > 3)
    {
        get_location(stack, &stack_b);
        cost_accounting(stack);
        cost_accounting(&stack_b);
        find_target(stack, &stack_b);
    }
	if (lstsize(*stack) == 3)
        sort_three(stack);
	else if (lstsize(*stack) == 2)
	{
		if ((*stack)->data > (*stack)->next->data)
			sa(stack,0);
	}
	if (stack_b)
	{
		t_stack *max_b = find_biggest(stack_b);
		bring_node_to_top_b(&stack_b,max_b);
		push_back_to_a(stack, &stack_b);
	}
	
	bring_min_to_top(stack);
	lstclear(stack);	
}




int main(int ac, char **argv)
{
	int *arr;
	t_stack *stack;

	stack = NULL;
	if(ac > 1)
	{
		arr = checker(argv);
		if (arr == NULL)
			return 0;
		
		stack =  parser(arr);
		turk_sort(&stack);
	

	}
	else
		return (0);
}


//a nın ve b nin maliyetini ayrı ayrı hesaplayıp topla
