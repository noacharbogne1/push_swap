/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:26:53 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/18 16:29:37 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ep_sa(t_list *sa)
{
	swap(sa);
	write(1, "sa\n", 3);
}

void	ep_sb(t_list *sb)
{
	swap(sb);
	write(1, "sb\n", 3);
}

void	ep_ss(t_list *sa, t_list *sb)
{
	swap(sa);
	swap(sb);
	write(1, "ss\n", 3);
}

void	ep_ra(t_list *sa)
{
	rotate(sa);
	write(1, "ra\n", 3);
}

void	ep_rb(t_list *sb)
{
	rotate(sb);
	write(1, "rb\n", 3);
}
