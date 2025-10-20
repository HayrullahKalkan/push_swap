/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:25:31 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/17 19:36:08 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack **lst, int flag)
{
	t_stack *head;
	t_stack *end;

	head = *lst;
	end = lstlast(*lst);
	*lst = (*lst)->next;
	end->next= head;
	head->next = NULL;
	if(flag == 0)
    {
        write(1,"ra\n",3);
    }
}

void rb(t_stack **lst, int flag)
{
	t_stack *head;
	t_stack *end;

	head = *lst;
	end = lstlast(*lst);
	*lst = (*lst)->next;
	end->next= head;
	head->next = NULL;
	if(flag == 0)
    {
        write(1,"rb\n",3);
    }
}
void rr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	ra(stack_a,1);
	rb(stack_b,1);
	if(flag == 1)
    {
        write(1,"rr\n",3);
    }
}
