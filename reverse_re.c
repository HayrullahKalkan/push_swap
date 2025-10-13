/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_re.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:09:35 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/13 17:12:17 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_list **lst)
{
	t_list *new_head;
	t_list *new_end;
	
	
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

void rrb(t_list **lst)
{
	t_list *new_head;
	t_list *new_end;
	
	
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

void rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);   
}