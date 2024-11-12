/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:52:05 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/12 15:13:09 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_rarb(t_list *sa, t_list *sb, int nb, int count)
{
	int	i_sb;

	i_sb = positioning_sb(nb, sb, 1);
	while (i_sb > 0)
	{
		rotate(sb);
		i_sb--;
	}
	count = count - i_sb;
	while (count > 0)
	{
		rotate(sa);
		count--;
	}
	push(sa, sb);
	return (-1);
}
int	exec_rrarrb(t_list *sa, t_list *sb, int nb, int count)
{
	int	i_sb;

	i_sb = positioning_sb(nb, sb, 2);
	while (i_sb > 0)
	{
		reverse_rotate(sb);
		i_sb--;
	}
	count = count - i_sb;
	while (count > 0)
	{
		reverse_rotate(sa);
		count--;
	}
	push(sa, sb);
	return (-1);
}
int	exec_rrarb(t_list *sa, t_list *sb, int nb, int count)
{
	int	i_sb;

	i_sb = positioning_sb(nb, sb, 1);
	while (i_sb > 0)
	{
		rotate(sb);
		i_sb--;
	}
	count = count - i_sb;
	while (count > 0)
	{
		reverse_rotate(sa);
		count--;
	}
	push(sa, sb);
	return (-1);
}
int	exec_rarrb(t_list *sa, t_list *sb, int nb, int count)
{
	int	i_sb;

	i_sb = positioning_sb(nb, sb, 2);
	while (i_sb > 0)
	{
		reverse_rotate(sb);
		i_sb--;
	}
	count = count - i_sb;
	while (count > 0)
	{
		rotate(sa);
		count--;
	}
	push(sa, sb);
	return (-1);
}
