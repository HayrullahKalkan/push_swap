/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:49:28 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/14 20:12:33 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	int 			cost;
	int 			tot_cos;
	
}	t_stack;

void sa(t_stack **lst);
void sb(t_stack **lst);
void ss(t_stack **stack_a, t_stack **stack_b);
t_stack *pop(t_stack **lst);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);
void ra(t_stack **lst);
void rb(t_stack **lst);
void rr(t_stack **stack_a, t_stack **stack_b);
void rra(t_stack **lst);
void rrb(t_stack **lst);
void rrr(t_stack **stack_a, t_stack **stack_b);
t_stack	*lstnew(int content);
void	lstadd_back(t_stack **lst, t_stack *new);
int	lstsize(t_stack *lst);
t_stack	*lstlast(t_stack *lst);





#endif
