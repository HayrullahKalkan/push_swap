#include "push_swap.h"

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
