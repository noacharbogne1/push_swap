/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noacharbogne <noacharbogne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:56:32 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/06 11:27:42 by noacharbogn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(stack_a **root)
{
	stack_a	*tmp;
	stack_a	*next;

	if (*root == NULL)
		return ;
	tmp = *root;
	if (tmp->next == (*root))
	{
		free(tmp);
		*root = NULL;
		return ;
	}
	next = tmp->next;
	while (next != (*root))
	{
		tmp = next;
		next = tmp->next;
		free(tmp);
	}
	free(*root);
	*root = NULL;
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

int	ft_check_dup(int result, stack_a *root)
{
	stack_a	*tmp;

	tmp = root;
	tmp = tmp-> next;
	while (tmp != root)
	{
		if (tmp->nb == result)
			return (1);
		tmp = tmp->next;
	}
	return (0);
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
		if (ft_check_dup(result, root))
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
		ft_swap_a(root);
		print_list(root);
	}
	write(1, "Error\n", 6);
	return (0);
}
