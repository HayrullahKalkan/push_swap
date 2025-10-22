/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:35:08 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/21 19:35:08 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	res;
	int		sign;
	int		i;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}
void	small_sort(t_stack **a)
{
	int	size;

	size = lstsize(*a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(a, 1);
	}
	else if (size == 3)
		sort_three(a);
}
