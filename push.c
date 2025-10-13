/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:39:50 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/13 17:12:12 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *pop(t_list **lst)
{
	t_list *head;
	
	head = *lst;
	*lst = (*lst)->next;
	head->next = NULL;
	return (head);
}

void pa(t_list **stack_a, t_list **stack_b)
{
	t_list *head_b;
	
	head_b = pop(stack_b);
	head_b->next = (*stack_a); 
	*stack_a = head_b;
}

void pb(t_list **stack_a, t_list **stack_b)
{
	t_list *head_a;
	if (!stack_a || !*stack_a || !stack_b)
    	return;

	head_a = pop(stack_a);
	head_a->next = (*stack_b); 
	*stack_b = head_a;
}