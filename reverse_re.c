/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_re.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:09:35 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/14 13:07:41 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack **lst)
{
	t_stack *new_head;
	t_stack *new_end;
	
	
	new_head = (*lst);
	while (new_head->next)
	{
		new_end = new_head;
		new_head = new_head->next;
	}
	
	new_head ->next = (*lst);
	*lst = new_head;
	new_end->next = NULL;
}

void rrb(t_stack **lst)
{
	t_stack *new_head;
	t_stack *new_end;
	
	
	new_head = (*lst);
	while (new_head->next)
	{
		new_end = new_head;
		new_head = new_head->next;
	}
	
	new_head ->next = (*lst);
	*lst = new_head;
	new_end->next = NULL;
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);   
}