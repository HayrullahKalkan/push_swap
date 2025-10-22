/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:49:28 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/19 19:44:48 by hakalkan         ###   ########.fr       */
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

int     *checker(char **argv, int *len);
t_stack *parser(int *ar, int len);
t_stack *lstnew(int content);
void    lstadd_back(t_stack **lst, t_stack *new);
t_stack *lstlast(t_stack *lst);
int     lstsize(t_stack *lst);
void    lstclear(t_stack **lst);
void    sa(t_stack **a, int print);
void    sb(t_stack **b, int print);
void    ss(t_stack **a, t_stack **b, int print);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **a, int print);
void    rb(t_stack **b, int print);
void    rr(t_stack **a, t_stack **b, int print);
void    rra(t_stack **a, int print);
void    rrb(t_stack **b, int print);
void    rrr(t_stack **a, t_stack **b, int print);
long ft_atol(char *str);
void    sort_three(t_stack **stack);
void    sort_three_max(t_stack **stack);
void    first_two_push(t_stack **a, t_stack **b);
void    push_back_to_a(t_stack **a, t_stack **b);
void    bring_node_to_top(t_stack **stack, t_stack *node);
void    bring_node_to_top_b(t_stack **stack_b, t_stack *node);
void    bring_min_to_top(t_stack **stack);
void    cost_accounting(t_stack **stack_a);
void    cost_total(t_stack *stack_a, t_stack *stack_b);
t_stack *find_biggest(t_stack *stack_b);
t_stack *min_stack_b(t_stack *stack_a, t_stack *stack_b);
t_stack *target_push(t_stack **stack_a);
void    get_location(t_stack **stack_a, t_stack **stack_b);
void    find_target(t_stack **stack_a, t_stack **stack_b);
t_stack *find_target_in_a(t_stack *stack_a, int value);
t_stack *find_min_node(t_stack *stack_a);
int	*max_min(char **argv, int len);
int	check_dup(int *arr, int len);
int	checker_digits(char **argv);
int	arg_len(char **argv);
void	arg_split(char **argv, char **digits, int *k);
int	checker_utils(char **digits, int *ar, int k);
void	small_sort(t_stack **a);



#endif
