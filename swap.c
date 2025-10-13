/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:41:13 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/13 17:13:09 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list **lst)
{
	t_list *tmp; //a
	t_list *tmp2; //b

	tmp = *lst;
	tmp2 = (*lst) -> next;

	(*lst) = tmp -> next;
	(*lst) -> next = tmp;
	tmp ->next = tmp2->next;

}

void sb(t_list **lst)
{
	t_list *tmp; //a
	t_list *tmp2; //b

	tmp = *lst;
	tmp2 = (*lst) -> next;

	(*lst) = tmp -> next;
	(*lst) -> next = tmp;
	tmp ->next = tmp2->next;

}
void ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}