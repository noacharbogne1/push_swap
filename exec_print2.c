/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_print2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:29:47 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/18 17:28:36 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ep_rr(t_list *sa, t_list *sb)
{
	rotate(sa);
	rotate(sb);
	write(1, "rr\n", 3);
}

void	ep_rra(t_list *sa)
{
	reverse_rotate(sa);
	write(1, "rra\n", 3);
}

void	ep_rrb(t_list *sb)
{
	reverse_rotate(sb);
	write(1, "rrb\n", 3);
}

void	ep_rrr(t_list *sa, t_list *sb)
{
	reverse_rotate(sa);
	reverse_rotate(sb);
	write(1, "rrr\n", 3);
}

void	ep_pa(t_list *sa, t_list *sb)
{
	push(sb, sa);
	write(1, "pa\n", 3);
}
