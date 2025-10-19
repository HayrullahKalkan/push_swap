/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:31:00 by hakalkan          #+#    #+#             */
/*   Updated: 2025/10/19 21:25:26 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	a = malloc(sizeof(int) * (len));
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
			free(tmp[j]);
			j++;
		}
		free(tmp);

		i++;
	}

	digits[*k] = NULL;
}
int *checker(char **argv)
{
	char **digits;
	int *ar;
	int k;
	int idx;
	
	k = 0;
	digits = malloc(sizeof(char *) * (arg_len(argv) + 1));
	if(!digits)
		return NULL;
	arg_split(argv,digits,&k);
	digits[k] = NULL;
	if (checker_digits(digits) == 1)
	{
		ar = max_min(digits,k);
		if (ar == NULL)
        {
            idx = 0;
            while (digits[idx])
                free(digits[idx++]);
            free(digits);
            return NULL;
        }
		  if(check_dup(ar, k))
        {
            write(1,"Error1\n",6);
            free(ar);
            idx = 0;
            while (digits[idx])
                free(digits[idx++]);
            free(digits);
            return NULL;
        }
		idx = 0;
        while (digits[idx])
            free(digits[idx++]);
		return free(digits),ar;
	}
	else
    {
        idx = 0;
        while (digits && digits[idx])
            free(digits[idx++]);
        free(digits);
        return (write(1,"Error2\n",6),NULL);
    }

	return NULL;	
}

t_stack *parser(int *ar)
{
	int i;
	t_stack	*stack;
	t_stack *node;
	int content;

    stack = NULL;
	i = 0;
	while (ar[i])
	{
		content = ar[i];
		node = lstnew(content);
		if (!node)
        {
            lstclear(&stack);
            free(ar);
            return NULL;
        }
		lstadd_back(&stack,node);
		i++;
	}
	free(ar);
	return (stack);
}
#include <stdio.h>

void sort_three_max(t_stack **stack)
{
    int a;
    int b;
    int c;
	// abc
	// acb
	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
  	if (a < b && b > c && a > c)
        sa(stack, 0); // bac → abc
    else if (a < b && b < c)
    {
        sa(stack, 0);
        rra(stack, 0); // cba
    }
    else if (a > b && b < c && a < c)
        rra(stack, 0); // bca
    else if (a < b && b > c && a < c)
        ra(stack, 0); // cab
    else if (a > b && b < c && a > c)
    {
        ra(stack, 0);
        sa(stack, 0); // acb → cba
    }
    // else: already in descending order
}


void sort_three(t_stack **stack)
{
    int a;
    int b;
    int c;
	// abc
	// acb
	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
  	if (a > b && b < c && a < c)
        sa(stack,0);  
    else if (a > b && b > c)
    {
        sa(stack,0);
        rra(stack,0);
    }
    else if (a > b && b < c && a > c)
        ra(stack,0);
    else if (a < b && b > c && a < c)
    {
        rra(stack,0);
        sa(stack,0);
    }
    else if (a < b && b > c && a > c)
        rra(stack,0);
}

void cost_accounting(t_stack **stack_a)
{
	t_stack *tmp;
	int size;
	int i;

	tmp = *stack_a;
	size = lstsize(tmp);
	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		if (i <= size / 2)
			tmp->cost = i;
		else
			tmp->cost = i - size;
		i++;
		tmp = tmp->next;
	}
}

void first_two_push(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a,stack_b);
	pb(stack_a,stack_b);
}

// ...existing code...
void cost_total(t_stack *stack_a, t_stack *stack_b)
{
    int a_abs = 0;
    int b_abs = 0;

    if (!stack_a)
        return;
    if (!stack_b)
    {
        stack_a->tot_cos = (stack_a->cost < 0) ? -stack_a->cost : stack_a->cost;
        return;
    }

    a_abs = (stack_a->cost < 0) ? -stack_a->cost : stack_a->cost;
    b_abs = (stack_b->cost < 0) ? -stack_b->cost : stack_b->cost;

    /* Aynı yöndeyse (ikisi de pozitif veya ikisi de negatif) */
    if ((stack_a->cost >= 0 && stack_b->cost >= 0) ||
        (stack_a->cost <= 0 && stack_b->cost <= 0))
    {
        stack_a->tot_cos = (a_abs > b_abs) ? a_abs : b_abs;
    }
    else
    {
        /* Farklı yönlerdeyse ayrı ayrı toplam */
        stack_a->tot_cos = a_abs + b_abs;
    }
}
// ...existing code...

t_stack *find_biggest(t_stack *stack_b)
{
    t_stack *tmp_b = stack_b;
    t_stack *best = NULL;
    int biggest = -2147483648;

    while (tmp_b)
    {
        if (tmp_b->data > biggest)
        {
            biggest = tmp_b->data;
            best = tmp_b;
        }
        tmp_b = tmp_b->next;
    }
    return (best);
}

t_stack *min_stack_b(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp_b;
    t_stack *best;
    int max;

	tmp_b = stack_b;
	best = NULL;
	max = -2147483648;
    while (tmp_b)
    {
        if (tmp_b->data < stack_a->data && tmp_b->data > max)
        {
            max = tmp_b->data;
            best = tmp_b;
        }
        tmp_b = tmp_b->next;
    }
    if (best == NULL)
        best = find_biggest(stack_b);
    return (best);
}
t_stack *target_push(t_stack **stack_a)
{
	t_stack *tmp;
	t_stack *target;
	int min;

	tmp = (*stack_a);
	min = 2147483647;
	while (tmp)
	{
		if(tmp->tot_cos < min)
		{
			min = tmp->tot_cos;
			target = tmp;
		}
		tmp = tmp->next;
	}
	return target;
}

void get_location(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *target_a;
	t_stack *target_b;
	int a;
	int b;
	
	target_a = target_push(stack_a);
	target_b = min_stack_b(target_a, *stack_b);
	a = target_a->cost;
	b = target_b->cost;
	while (*stack_a != target_a || *stack_b != target_b)
	{
		if(a > 0 && b > 0)
		{
			rr(stack_a, stack_b,1);
    		a--;
    		b--;
		}
		else if(a < 0 && b < 0)
		{
			rrr(stack_a, stack_b,1);
    		a++;
    		b++;
		}
		else if(a != 0)
		{
    		if(a > 0)
        		ra(stack_a,0), a--;
    		else
        		rra(stack_a,0), a++;
		}
		else if(b != 0)
		{
    		if(b > 0)
        		rb(stack_b,0), b--;
    		else
        		rrb(stack_b,0), b++; 
		}
		else 
			break;
	}
	pb(stack_a,stack_b);
}
void find_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;
	
	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_a)
	{
		cost_total(tmp_a, min_stack_b(tmp_a,tmp_b));
		tmp_a = tmp_a->next;
	}
}
t_stack *find_target_in_a(t_stack *stack_a, int value)
{
    t_stack *tmp = stack_a;
    t_stack *target = NULL;
    int min_diff = 2147483647;

    while (tmp)
    {
        if (tmp->data > value && (tmp->data - value) < min_diff)
        {
            min_diff = tmp->data - value;
            target = tmp;
        }
        tmp = tmp->next;
    }
    if (!target)
    {
        tmp = stack_a;
        int max = -2147483648;
        while (tmp)
        {
            if (tmp->data > max)
            {
                max = tmp->data;
                target = tmp;
            }
            tmp = tmp->next;
        }
    }
    return target;
}
void bring_min_to_top(t_stack **stack_a)
{
    if (!stack_a || !*stack_a)
        return;

    t_stack *tmp = *stack_a;
    t_stack *min_node = *stack_a;
    int pos = 0;
    int min_pos = 0;

    while (tmp)
    {
        if (tmp->data < min_node->data)
        {
            min_node = tmp;
            min_pos = pos;
        }
        tmp = tmp->next;
        pos++;
    }
    int size = lstsize(*stack_a);
    if (min_pos <= size / 2)
    {
        while (*stack_a != min_node)
            ra(stack_a,0);
    }
    else
    {
        while (*stack_a != min_node)
            rra(stack_a,0);
    }
}

void push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_b)
    {
        t_stack *max_b;
        t_stack *target_a;
		int i;
		
		i = 0;
        max_b = find_biggest(*stack_b);
        target_a = lstlast(*stack_a);
        while (*stack_b != max_b)
        {
            if (max_b->cost > 0)
                rb(stack_b,0);
            else
                rrb(stack_b,0);
        }
		while (i < 3)
		{
        	target_a = lstlast(*stack_a);

			if(target_a->data > max_b->data && target_a->data < (*stack_a)->data)
			{
				rra(stack_a,0);
			}
			i++;
		}
        pa(stack_a, stack_b);
    }
}

void turk_sort(t_stack **stack)
{
    t_stack *stack_b = NULL;

    first_two_push(stack, &stack_b);

    cost_accounting(stack);
    cost_accounting(&stack_b);
    find_target(stack, &stack_b);

    while (lstsize(*stack) > 3)
    {
        get_location(stack, &stack_b);
        cost_accounting(stack);
        cost_accounting(&stack_b);
        find_target(stack, &stack_b);
    }
	if(lstsize(stack_b) < 3)
	{
		sort_three_max(stack);	
	}
	else
	    sort_three(stack);
    // t_stack *tmp_b = stack_b;
    // while (tmp_b)
    // {
    //     printf("b%d\n", tmp_b->data);
    //     tmp_b = tmp_b->next;
    // }
	push_back_to_a(stack, &stack_b);
	bring_min_to_top(stack);

	// t_stack *tmp_a = *stack;
    // while (tmp_a)
    // {
    //     printf("a%d\n", tmp_a->data);
    //     tmp_a = tmp_a->next;
    // }
	lstclear(stack);
	
}




int main(int ac, char **argv)
{
	int *arr;
	t_stack *stack;

	stack = NULL;
	if(ac > 1)
	{
		arr = checker(argv);
		if (arr == NULL)
			return 0;
		
		stack =  parser(arr);
		turk_sort(&stack);
	
		// while (stack != NULL)
		// {
		// 	printf("a%d ",((int)stack->data));		
		// 	stack = stack->next;
		// }
	}
	else
		return (0);
}


//a nın ve b nin maliyetini ayrı ayrı hesaplayıp topla
