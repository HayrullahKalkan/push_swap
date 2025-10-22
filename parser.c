/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:36:04 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/21 21:36:04 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker_utils(char **digits, int *ar, int k)
{
	int	idx;

	if (ar == NULL)
	{
		idx = 0;
		while (digits[idx])
			free(digits[idx++]);
		free(digits);
		return (0);
	}
	if (check_dup(ar, k))
	{
		write(1, "Error1\n", 6);
		free(ar);
		idx = 0;
		while (digits[idx])
			free(digits[idx++]);
		free(digits);
		return (0);
	}
	idx = 0;
	while (digits[idx])
		free(digits[idx++]);
	free(digits);
	return (1);
}

int	*checker(char **argv, int *len)
{
	char	**digits;
	int		*ar;
	int		k;
	int		idx;

	k = 0;
	digits = malloc(sizeof(char *) * (arg_len(argv) + 1));
	if (!digits)
		return (NULL);
	arg_split(argv, digits, &k);
	digits[k] = NULL;
	*len = k;
	if (checker_digits(digits))
	{
		ar = max_min(digits, k);
		if (!checker_utils(digits, ar, k))
			return (NULL);
		return (ar);
	}
	idx = 0;
	while (digits && digits[idx])
		free(digits[idx++]);
	free(digits);
	write(1, "Error2\n", 6);
	return (NULL);
}

t_stack	*parser(int *ar, int len)
{
	int		i;
	t_stack	*stack;
	t_stack	*node;
	int		content;

	i = 0;
	stack = NULL;
	while (i < len)
	{
		content = ar[i];
		node = lstnew(content);
		if (!node)
		{
			lstclear(&stack);
			free(ar);
			return (NULL);
		}
		lstadd_back(&stack, node);
		i++;
	}
	free(ar);
	return (stack);
}
