/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:03:39 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/18 11:32:51 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>

typedef struct s_list
{
	long	nb;
	struct	s_list	*prev;
	struct	s_list	*next;
}					t_list;

enum e_coups
{
	PA = 1,
	PB = 2,
	SA = 3,
	SB = 4,
	SS = 5
	RA = 6,
	RB = 7,
	RR = 8,
	RRA = 9,
	RRB = 10,
	RRR = 11,
}

long	ft_across(char *str, t_list *root);
long	ft_atol(char *nptr);
int		ft_count(long n);
int		len_lst(t_list *root);
int		check_order(t_list *root);
void	ft_free(t_list **root);
void	*add_node(t_list *root, long value);
t_list	*create_list(void);
void	push(t_list *from, t_list *to);
void    swap(t_list *root);
void	rotate(t_list *root);
void	reverse_rotate(t_list *root);
void	del_node(t_list *element);
void	three_elems(t_list *root);
void	four_elems(t_list *sa, t_list *sb);
void	five_elems(t_list *sa, t_list *sb);
void	sort_list(t_list *sa, t_list *sb);
int 	find_combination(t_list *sa, t_list *sb);
int		combination_rarb(long nb, t_list *sa, t_list *sb);
int		combination_rrarrb(long nb, t_list *sa, t_list *sb);
int		combination_rrarb(long nb, t_list *sa, t_list *sb);
int		combination_rarrb(long nb, t_list *sa, t_list *sb);
int		exec_rarb(t_list *sa, t_list *sb, long nb);
int		exec_rrarrb(t_list *sa, t_list *sb, long nb);
int		exec_rrarb(t_list *sa, t_list *sb, long nb);
int		exec_rarrb(t_list *sa, t_list *sb, long nb);
long	min(t_list *root);
long	max(t_list *root);
int		find_place(t_list *root, long nb);
int		positioning_sb(long nb, t_list *sb);
void 	print_list(t_list *root);
int		ft_iszero(char *str, t_list *root);
int		ft_check_dup(long result, t_list *root);
void	place_in_a(t_list *sa, t_list *sb);
int		case_r(long nb, t_list *sa);
int		case_rr(long nb, t_list *sa);
int		find_case(long nb, t_list *root);
int		exec_case_r(t_list *sa, t_list *sb, int i);
int		exec_case_rr(t_list *sa, t_list *sb, int i);
void	final_rotate(t_list *sa);

#endif