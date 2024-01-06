/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:48:34 by romlambe          #+#    #+#             */
/*   Updated: 2024/01/06 18:36:16 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "unistd.h"
# include "stdlib.h"
# include <stdio.h>
# include <limits.h>

typedef	struct	s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}				t_list;

typedef	struct	s_data
{
	int	median;
	int	size;
	int	start;
	int	end;
	int	n;
	int	t_num;
	int	unorder_num;
	int	max;
}				t_data;

void	ft_sa(t_list **lst_a, int print);
void	ft_sb(t_list **lst_b, int print);
void	ft_ss(t_list **lst_a, t_list **lst_b);
void	ft_pa(t_list **lst_a, t_list **lst_b);
void	ft_pb(t_list **lst_a, t_list **lst_b);
void	ft_ra(t_list **lst_a, int print);
void	ft_rb(t_list **lst_b, int print);
void	ft_rr(t_list **lst_a, t_list **lst_b);
void	ft_rra(t_list **lst_a, int print);
void	ft_rrb(t_list **lst_b, int print);
void	ft_rrr(t_list **lst_a, t_list **lst_b);

int	ft_atoi(char *str);
t_list	*new_node(void *content);
t_list	*fill_list(t_list **lst, int ac, char **av);
int	lst_size(t_list **lst);
t_list	*lst_last(t_list **lst);
t_list	*lst_second_to_last(t_list **lst);
int	count_ra(t_list **lst, int content);
int	count_rra(t_list **lst, int content);
t_list *swap_2_numbers(t_list **lst, int index);


void	swap_5_numbers(t_list **lsta, t_list **lstb);
void	both_lowest_at_bottom(t_list **lst);
void	sort_3_numbers(t_list **lst);


#endif
