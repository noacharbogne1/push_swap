/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:56:32 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/05 16:45:47 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(stack_a **root)
{
	stack_a	*tmp;

	tmp = *root;
	while (root)
	{
		tmp = (*root)->next;
		free(*root);
		*root = tmp;
	}
}

int	ft_count(int n)
{
	size_t		count;

	count = 1;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_atoi(char *nptr)
{
	int	i;
	int	n;
	int	result;

	i = 0;
	n = 0;
	result = 0;
	if (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (n == 1)
		return (result * -1);
	return (result);
}

int	ft_across(char *str, stack_a *root)
{
	int	i;
	int	result;

	i = 0;
	while (str[i])
	{
		result = ft_atoi(&str[i]);
		if (!result)
			return (0);
		add_node(root, result);
		i += ft_count(result);
		if (str[i] == ' ')
			i++;
	}
	return (result);
}

#include <stdio.h>

void print_list(stack_a *root)
{
	if (!root)
		return;
    stack_a *current = root;
    while (current)
    {
       	printf("\n%d", current->nb);
        current = current->next;
		if (current == root)
			return ;
    }
}

int	main(int argc, char **argv)
{
	int		i;
	stack_a	*root;

	i = 1;
	root = create_stack_a();
	if (argc >= 2)
	{
		while (argv[i])
		{
			if (!ft_across(argv[i], root))
			{
				write(1, "Error\n", 6);
				ft_free(&root);
				return (0);
			}
			i++;
		}
		print_list(root);
	}
	write(1, "Error\n", 6);
	return (0);
}
