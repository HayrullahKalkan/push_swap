/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:25:31 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/13 17:12:25 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_list **lst)
{
	t_list *head;
	t_list *end;

	head = *lst;
	end = ft_lstlast(*lst);
	*lst = (*lst)->next;
	end->next= head;
	head->next = NULL;
}

void rb(t_list **lst)
{
	t_list *head;
	t_list *end;

	head = *lst;
	end = ft_lstlast(*lst);
	*lst = (*lst)->next;
	end->next= head;
	head->next = NULL;
}
void rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);   
}
