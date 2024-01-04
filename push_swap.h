/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:48:34 by romlambe          #+#    #+#             */
/*   Updated: 2024/01/04 16:14:17 by romlambe         ###   ########.fr       */
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


#endif
