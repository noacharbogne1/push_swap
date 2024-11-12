/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:03:39 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/12 16:27:05 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int	nb;
	struct	s_list	*prev;
	struct	s_list	*next;
}					t_list;

int		ft_across(char *str, t_list *root);
int		ft_atoi(char *nptr);
int		ft_count(int n);
int		len_lst(t_list *root);
int		check_order(t_list *root);
void	ft_free(t_list **root);
void	*add_node(t_list *root, int value);
t_list	*create_list(void);
void	push(t_list *from, t_list *to);
void    swap(t_list *root);
void	rotate(t_list *root);
void	reverse_rotate(t_list *root);
void	del_node(t_list *element);
void	three_elems(t_list *root);
void	four_elems(t_list *sa, t_list *sb);
void	five_elems(t_list *sa, t_list *sb);
int		positioning_sb(int nb, t_list *sb, int rotation);
void	sort_list(t_list *sa, t_list *sb);
int 	find_combination(t_list *sa, t_list *sb);
int		combination_rarb(int nb, t_list *sa, t_list *sb);
int		combination_rrarrb(int nb, t_list *sa, t_list *sb);
int		combination_rrarb(int nb, t_list *sa, t_list *sb);
int		combination_rarrb(int nb, t_list *sa, t_list *sb);
int		exec_rarb(t_list *sa, t_list *sb, int nb, int count);
int		exec_rrarrb(t_list *sa, t_list *sb, int nb, int count);
int		exec_rrarb(t_list *sa, t_list *sb, int nb, int count);
int		exec_rarrb(t_list *sa, t_list *sb, int nb, int count);
int		min(t_list *root);

#endif