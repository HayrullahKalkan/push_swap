/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:39:50 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/14 15:15:55 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *pop(t_stack **lst)
{
	t_stack *head;
	
	head = *lst;
	*lst = (*lst)->next;
	head->next = NULL;
	return (head);
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *head_b;
	
	head_b = pop(stack_b);
	head_b->next = (*stack_a); 
	*stack_a = head_b;
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *head_a;

    if (!stack_a || !*stack_a)
        return;
    head_a = pop(stack_a);
    if (!head_a)
        return;
    head_a->next = (*stack_b); 
    *stack_b = head_a;
}
