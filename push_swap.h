/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:03:39 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/10 08:38:04 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	long			nb;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct s_rarb
{
	int	i_sb;
	int	i_sa;
	int	same;
}				t_rarb;

typedef struct s_rrarrb
{
	int	i_sb;
	int	i_sa;
	int	same;
}				t_rrarrb;

// handle_input.c
long		ft_across(char *str, t_list *sa, t_list *sb);
long		ft_atol(t_list *sa, t_list *sb, char *nptr);
int			ft_check_dup(long result, t_list *root);
int			ft_count(long n);

//handle_input2.c
int			prepare_sorting(t_list *sa, t_list *sb);
int			write_error(t_list *sa, t_list *sb);
void		errors_result(t_list *sa, t_list *sb, long result);
int			is_space(char *str);

// stacks_utils.c
int			check_order(t_list *root);
void		ft_free(t_list **root);
void		*add_back(t_list *root, long value);
t_list		*create_list(void);
void		del_node(t_list *element);

//stacks_utils2.c
int			ft_error(t_list *sa, t_list *sb);
int			ft_iszero(char *str, t_list *sa, t_list *sb);
int			len_lst(t_list *root);
void		add_front(t_list *root, long content);

//operations.c
void		push(t_list *from, t_list *to);
void		swap(t_list *root);
void		rotate(t_list *root);
void		reverse_rotate(t_list *root);

//small_list.c
void		three_elems(t_list *root);
void		four_elems(t_list *sa, t_list *sb);

//big_list.c
void		sort_list(t_list *sa, t_list *sb);
void		place_in_a(t_list *sa, t_list *sb);
int			find_case(long nb, t_list *root);

//combinations.c
int			find_combination(t_list *sa, t_list *sb);
int			combination_rarb(long nb, t_list *sa, t_list *sb);
int			combination_rrarrb(long nb, t_list *sa, t_list *sb);
int			combination_rrarb(long nb, t_list *sa, t_list *sb);
int			combination_rarrb(long nb, t_list *sa, t_list *sb);

//exec_operations.c
int			exec_rarb(t_list *sa, t_list *sb, long nb);
int			exec_rrarrb(t_list *sa, t_list *sb, long nb);
int			exec_rrarb(t_list *sa, t_list *sb, long nb);
int			exec_rarrb(t_list *sa, t_list *sb, long nb);

//exec_operations2.c
int			exec_case_r(t_list *sa, t_list *sb, int i);
int			exec_case_rr(t_list *sa, t_list *sb, int i);

//exec_operations_utils.c
t_rarb		calculate_indices_rarb(t_list *sa, t_list *sb, long nb);
t_rrarrb	calculate_indices_rrarrb(t_list *sa, t_list *sb, long nb);

//sort_utils.c
int			find_place_sb(t_list *root, long nb);
int			positioning_sb(long nb, t_list *sb);
int			find_place_sa(t_list *root, long nb);
int			positioning_sa(long nb, t_list *sa);
void		final_rotate(t_list *sa);

//sort_utils2.c
long		min(t_list *root);
long		max(t_list *root);

//find_case.c
int			case_r(long nb, t_list *sa);
int			case_rr(long nb, t_list *sa);

//exec_print.c
void		ep_sa(t_list *sa);
void		ep_sb(t_list *sb);
void		ep_ss(t_list *sa, t_list *sb);
void		ep_ra(t_list *sa);
void		ep_rb(t_list *sb);

//exec_print2.c
void		ep_rr(t_list *sa, t_list *sb);
void		ep_rra(t_list *sa);
void		ep_rrb(t_list *sb);
void		ep_rrr(t_list *sa, t_list *sb);
void		ep_pa(t_list *sa, t_list *sb);

//exec_print3.c
void		ep_pb(t_list *sa, t_list *sb);

#endif
