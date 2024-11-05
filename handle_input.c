/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:56:32 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/05 13:56:35 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_across(char *str)
{
	int	i;
	int	result;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
		{
			result = ft_atoi(&str[i]);
				if (!result)
				return (0);
			i += ft_count(result);
		}
		else if (str[i] == '0')
		{
			result = ft_atoi(&str[i]);
			i++;
		}
		if (str[i] == ' ')
			i++;
	}
	return (result);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	result;

	i = 1;
	result = 0;
	if (argc >= 2)
	{
		while (argv[i])
		{
			result = ft_across(argv[i]);
			if (!result)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			i++;
		}
		printf("%d", result);
		return (0);
	}
	write(1, "Error\n", 6);
	return (0);
}