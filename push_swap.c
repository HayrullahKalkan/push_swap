/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:31:00 by hakalkan          #+#    #+#             */
/*   Updated: 2025/09/26 16:33:14 by hakalkan         ###   ########.fr       */
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

t_list *pop(t_list **lst)
{
	t_list *head;

	head = *lst;
	*lst = (*lst)->next;
	head->next = NULL;
	return (head);
}

void pa(t_list **stack_a, t_list **stack_b)
{
	t_list *head_b;
	
	head_b = pop(stack_b);
	head_b->next = (*stack_a); 
	*stack_a = head_b;
}

void pb(t_list **stack_a, t_list **stack_b)
{
	t_list *head_b;
	
	head_b = pop(stack_b);
	head_b->next = (*stack_a); 
	*stack_a = head_b;
}

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
void rra(t_list **lst)
{
	t_list *new_head;
	t_list *new_end;
	
	
	new_head = (*lst);
	while (new_head->next)
	{
		new_end = new_head;
		new_head = new_head->next;
	}
	
	new_head ->next = (*lst);
	*lst = new_head;
	new_end->next = NULL;
}

void rrb(t_list **lst)
{
	t_list *new_head;
	t_list *new_end;
	
	
	new_head = (*lst);
	while (new_head->next)
	{
		new_end = new_head;
		new_head = new_head->next;
	}
	
	new_head ->next = (*lst);
	*lst = new_head;
	new_end->next = NULL;
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);   
}

long ft_atol(char *str)
{
	long res = 0;
	int sign = 1;
	int i;

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
int *max_min(char **argv, int len)
{
	int i;
	int *a;
	long digit;
	
	i = 0;
	a = malloc(sizeof(int) * (len + 1));
	if (!a)
    	return (NULL);

	while (i < len)
	{
		digit = ft_atol(argv[i]);
		if(digit < -2147483648 || digit > 2147483647)
		{
			write(1,"Error\n",6);
			free(a);
			return (NULL);
		}
		a[i] = digit;
		i++;
	}
	return a;
}

int check_dup(int *arr, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (i != j && arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int checker_digits(char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		j = 0;
		if ((argv[i][j] == '-' || argv[i][j] == '+') && j == 0)
			j++;
		if (!argv[i][j])
			return (0);
		while (argv[i][j])
		{
			if(!ft_isdigit(argv[i][j]))
				return (0);
			j++;    
		}
		i++;            
	}
	return (1);
}
int *checker(char **argv)
{
	char **digits;
	char **tmp;
	int i;
	int j;
	int *ar;
	int k;
	
	k = 0;
	j = 0;
	i = 1;
	digits = NULL;
	while (argv[i++])
		j += count_word(argv[i],' ');
	digits = malloc(sizeof(char *) * (j + 1));
	if(!digits)
		return NULL;
	i = 1;
	while (argv[i])
	{
		tmp = ft_split(argv[i],' ');
		j = 0;
		while (tmp[j])
		{
			digits[k++] = ft_strdup(tmp[j]);
			j++;
		}
		i++;
	}
	digits[k] = NULL;

	if (checker_digits(digits) == 1)
	{
		ar = max_min(digits,k);
		if(check_dup(ar, i))
			write(1,"Error\n",6);
		return ar;
	}
	else
		write(1,"Error\n",6);

	return 0;	
}
// size_t **parser(int *ar)
// {
// 	int i;
// 	size_t	**stack;
// 	size_t *node;
// 	i = 0;
// 	while (ar[i])
// 	{
// 		node = ft_lstnew(ar[i]);
// 		ft_lstadd_back(*stack,node);
// 	}
	
// }
#include <stdio.h>

int main(int ac, char **argv)
{
	int i;
	int *arr;
	printf("a");
	i = 0;
	if(ac > 1)
	{
		arr = checker(argv);
	}
	else
		return (0);
	   
}



// int main(int ac, char **argv)
// {
// 	int *arr;
// 	int len;

// 	if (ac < 2)
// 		return (0);

// 	if (!checker(argv))
// 		return (1);

// 	len = ac - 1;
// 	arr = max_min(argv, ac);
// 	if (!arr)
// 		return (1);

// 	if (check_dup(arr, len))
// 	{
// 		free(arr);
// 		return (1);
// 	}
// }