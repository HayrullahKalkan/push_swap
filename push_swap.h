/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:49:28 by hakalkan          #+#    #+#             */
/*   Updated: 2025/09/26 15:01:46 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <stdio.h>

typedef struct s_stack
{
	int				data;
	struct s_list	*next;

	
}	t_stack;

void sa(t_list **lst);
void sb(t_list **lst);
void ss(t_list **stack_a, t_list **stack_b);
t_list *pop(t_list **lst);
void pa(t_list **stack_a, t_list **stack_b);




#endif
