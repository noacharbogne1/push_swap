/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:47:05 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/18 10:21:36 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_case_r(t_list *sa, t_list *sb, int i)
{
	while (i > 0)
	{
		rotate(sa);
		i--;
	}
	push(sb, sa);
	return (-1);
}

int	exec_case_rr(t_list *sa, t_list *sb, int i)
{
	while (i > 0)
	{
		reverse_rotate(sa);
		i--;
	}
	push(sb, sa);
	return (-1);
}