/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:31:00 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/02 04:12:29 by hakalkan         ###   ########.fr       */
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
	t_list *head_a;
	
	if(!(*stack_a))
		return;
	head_a = malloc(sizeof(t_list *));
	head_a = pop(stack_a);
	head_a->next = (*stack_b); 
	*stack_b = head_a;
	
	free(head_a);
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
			write(1,"Error3\n",6);
			free(a);
			return (NULL);
		}
		a[i] = digit;
		i++;
	}
	i = 0;
	
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

int arg_len(char **argv)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (argv[i])
	{
		j += count_word(argv[i],' ');
		i++;
	}
	
	return j;
}
void arg_split(char **argv, char **digits,int *k)
{
	int j;
	int i;
	char **tmp;

	j = 0;
	i = 1;
	while (argv[i])
	{
		tmp = ft_split(argv[i],' ');
		j = 0;
		while (tmp[j])
		{
			digits[*k] = ft_strdup(tmp[j]);
			(*k)++;
			j++;
		}
		i++;
	}
	digits[*k] = NULL;
}
int *checker(char **argv)
{
	char **digits;
	int *ar;
	int k;
	
	k = 0;
	digits = NULL;
	digits = malloc(sizeof(char *) * (arg_len(argv) + 1));
	if(!digits)
		return NULL;
	arg_split(argv,digits,&k);
	digits[k] = NULL;
	if (checker_digits(digits) == 1)
	{
		ar = max_min(digits,k);
		if (ar == NULL)
            return (free(digits),(NULL));
		if(check_dup(ar, k))
			return (write(1,"Error1\n",6), NULL);
		return ar;
	}
	else
		return (write(1,"Error2\n",6),NULL);

	return NULL;	
}

t_list **parser(int *ar)
{
	int i;
	t_list	**stack;
	t_list *node;
	int *content;
	
	stack = malloc(sizeof(t_list *));
    if (!stack)
        return NULL;
    *stack = NULL;
	i = 0;
	while (ar[i])
	{
		content = malloc(sizeof(int));
		if(!content)
			return NULL;
		*content = ar[i];
		node = ft_lstnew(content);
		ft_lstadd_back(stack,node);
		i++;
	}
	return ((t_list **)stack);
}
#include <stdio.h>

void move_count(t_list **stack)
{
	int count;

	count = ft_lstsize(*stack);

	printf("%d",count);
	
}
void first_two_push(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a,stack_b);
	pb(stack_a,stack_b);
	
}

void turk_sort(t_list **stack)
{
	t_list **stack_b;
	
	stack_b = NULL;
	first_two_push(stack,stack_b);
	
}

int main(int ac, char **argv)
{
	int i;
	int *arr;
	t_list **stack;

	stack = NULL;
	i = 0;
	if(ac > 1)
	{
		arr = checker(argv);
		if (arr == NULL)
			return 0;
		
		stack =  parser(arr);
		turk_sort(stack);
		while (*stack != NULL)
		{
			printf("%d ",*((int *)(*stack)->content));
			*stack = (*stack)->next;
		}
		move_count(stack);
	}
	else
		return (0);
	   
}



