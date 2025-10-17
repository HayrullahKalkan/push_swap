/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:41:13 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/17 19:36:50 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **lst,int flag)
{
    t_stack *first;
    t_stack *second;

    if (!lst || !*lst || !(*lst)->next)
        return;

    first = *lst;
    second = (*lst)->next;

    first->next = second->next;
    second->next = first;
    *lst = second;
    if(flag == 0)
    {
        write(1,"sa\n",3);
    }
}


void sb(t_stack **lst, int flag)
{
	t_stack *tmp; //a
	t_stack *tmp2; //b

	tmp = *lst;
	tmp2 = (*lst) -> next;

	(*lst) = tmp -> next;
	(*lst) -> next = tmp;
	tmp ->next = tmp2->next;
    if(flag == 0)
    {
        write(1,"sb\n",3);
    }

}
void ss(t_stack **stack_a, t_stack **stack_b, int flag)
{
	sa(stack_a,1);
	sb(stack_b,1);
    if(flag == 1)
    {
        write(1,"ss\n",3);
    }
}