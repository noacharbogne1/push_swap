/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:56:32 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/18 17:14:22 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(long n)
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

long	ft_atol(char *nptr)
{
	int		i;
	int		n;
	long	result;

	i = 0;
	n = 0;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
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

int	ft_check_dup(long result, t_list *root)
{
	t_list	*tmp;

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

long	ft_across(char *str, t_list *root)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == '0')
		{
			i += ft_iszero(&str[i], root);
			if (i == -1)
				return (0);
			else
				result = i;
		}
		while (str[i] && str[i] == ' ')
			i++;
		if (!str[i])
			break;
		result = ft_atol(&str[i]);
		if (!result || result > 2147483647 || result < -2147483648 || ft_count(result) > 12)
			return (0);
		if (ft_check_dup(result, root))
			return (0);
		add_node(root, result);
		i += ft_count(result);
	}
	return (result);
}

// À RETIRER //

void print_list(t_list *root)
{
	if (!root)
		return;
    t_list *current = root->next;
    while (current)
    {
       	printf("\n%ld", current->nb);
		current = current->next;
		if (current == root)
			return ;
    }
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*sa;
	t_list	*sb;

	i = 1;
	sa = create_list();
	sb = create_list();
	if (argc >= 2)
	{
		while (argv[i])
		{
			if (!ft_across(argv[i], sa))
			{
				write(1, "Error\n", 6);
				ft_free(&sa);
				return (0);
			}
			i++;
		}
		if (check_order(sa))
			return (0);
		if (len_lst(sa) == 2)
			ep_sa(sa);
		else if (len_lst(sa) == 3)
			three_elems(sa);
		else if (len_lst(sa) == 4)
			four_elems(sa, sb);
		else if (len_lst(sa) == 5)
			five_elems(sa, sb);
		else if (len_lst(sa) > 5)
		{
			sort_list(sa, sb);
			place_in_a(sa, sb);
		}
		print_list(sa);
		ft_free(&sa);
		ft_free(&sb);
	}
	write(1, "Error\n", 6);
	return (0);
}
