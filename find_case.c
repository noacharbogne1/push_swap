/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:08:39 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/19 17:08:53 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_r(long nb, t_list *sa)
{
	int		i;

	i = positioning_sb(nb, sa);
	if (i == len_lst(sa))
		i = 0;
	if (i != 0)
		i = len_lst(sa) - i;
	return (i);
}

int	case_rr(long nb, t_list *sa)
{
	int		i;

	i = positioning_sb(nb, sa);
	return (i);
}
