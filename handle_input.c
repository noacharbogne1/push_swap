/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:56:32 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/21 12:43:53 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(long n)
{
	int	count;

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
		i += is_space(&str[i]);
		if (str[i] == '0')
		{
			i += ft_iszero(&str[i], root);
			if (i == -1)
				return (0);
			else
				result = i;
		}
		i += is_space(&str[i]);
		if (!str[i])
			break ;
		result = ft_atol(&str[i]);
		if (!errors_result(root, result))
			return (0);
		i += ft_count(result);
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*sa;
	t_list	*sb;

	i = 1;
	if (argc >= 2)
	{
		sa = create_list();
		sb = create_list();
		while (argv[i])
		{
			if (!ft_across(argv[i], sa))
				return (write_error(sa, sb));
			i++;
		}
		prepare_sorting(sa, sb);
		if (!prepare_sorting(sa, sb))
			return (ft_error(sa, sb));
		ft_free(&sa);
		ft_free(&sb);
		return (1);
	}
	return (0);
}
