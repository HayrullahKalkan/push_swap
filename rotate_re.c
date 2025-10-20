/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_re.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:09:35 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/17 19:48:51 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack **lst, int flag)
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
	if(flag == 0)
    {
        write(1,"rra\n",4);
    }
}

void rrb(t_stack **lst,int flag)
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
	if(flag == 0)
    {
        write(1,"rrb\n",4);
    }
}

void rrr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	rra(stack_a,1);
	rrb(stack_b,1);
	if(flag == 1)
    {
        write(1,"rrr\n",4);
    }
}