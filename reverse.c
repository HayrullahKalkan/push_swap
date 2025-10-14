/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:25:31 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/14 19:02:06 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack **lst)
{
	t_stack *head;
	t_stack *end;

	head = *lst;
	end = lstlast(*lst);
	*lst = (*lst)->next;
	end->next= head;
	head->next = NULL;
}

void rb(t_stack **lst)
{
	t_stack *head;
	t_stack *end;

	head = *lst;
	end = lstlast(*lst);
	*lst = (*lst)->next;
	end->next= head;
	head->next = NULL;
}
void rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);   
}
