/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noacharbogne <noacharbogne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:56:32 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/05 14:58:19 by noacharbogn      ###   ########.fr       */
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

long	ft_atol(t_list *root, char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] == '0')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (!errors_result(root, result))
		return (0);
	add_back(root, (result * sign));
	return (i);
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
		i += ft_atol(root, &str[i]);
	}
	return (result);
}
#include <stdio.h>
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
		t_list *tmp = sa->next;
		while (tmp != sa)
		{
			printf("%ld\n", tmp->nb);
			tmp = tmp->next;
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
