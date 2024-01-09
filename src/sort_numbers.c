/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:18:33 by romlambe          #+#    #+#             */
/*   Updated: 2024/01/09 13:59:31 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_2_numbers(t_list **lst)
{
	int	first_index;
	int	second_index;
	if (!(*lst))
		return ;
	first_index = (*lst)->index;
	second_index = (*lst)->next->index;
	if (first_index > second_index)
		ft_sa(lst, 1);
}

t_list *find_highest_node(t_list *lst)
{
	int		highest;
	t_list	*highest_node;

	if (!lst)
		return (NULL);
	highest = INT_MIN;
	while (lst)
	{
		if ((lst)->content > highest)
		{
			highest = (lst)->content;
			highest_node = lst;
		}
		(lst) = (lst)->next;
	}
	return (highest_node);
}

void	sort_3_numbers(t_list **lst)
{
	t_list	*highest_node;

	highest_node = find_highest_node(*lst);
	if (*lst == highest_node)
		ft_ra(lst, 1);
	else if ((*lst)->next == highest_node)
		ft_rra(lst, 1);
	if ((*lst)->content > (*lst)->next->content)
		ft_sa(lst, 1);
}

void	both_lowest_at_bottom(t_list **lst)
{
	t_list	*temp;
	t_list	*first_smallest_node;
	t_list	*second_smallest_node;

	if (!(*lst) && !(*lst)->next)
		return ;
	first_smallest_node = find_smallest_index(lst);
	second_smallest_node = find_second_smallest_index(lst);
	temp = *lst;
	// temp = temp->next;
	while (temp && temp->next)
	{
		temp = temp->next;
		if (temp == second_smallest_node && temp->next == first_smallest_node)
		{
			ft_rra(lst, 1);
			ft_rra(lst, 1);
		}
	}
}

void	swap_5_numbers(t_list **lsta, t_list **lstb)
{
	t_list	*smallest_node;
	int		count;
	int		stack_size;

	count = 0;
	stack_size = lst_size(lsta);
	both_lowest_at_bottom(lsta);
	while(count < (stack_size - 3))
	{
		smallest_node = find_smallest_index(lsta);
		while (*lsta != smallest_node)
			ft_ra(lsta, 1);
		ft_pb(lsta, lstb);
		count++;
	}
	sort_3_numbers(lsta);
	if (stack_size == 5)
	{
		smallest_node = find_smallest_index(lstb);
		if (*lstb == smallest_node)
			ft_sb(lstb, 1);
		ft_pa(lsta, lstb);
	}
	ft_pa(lsta, lstb);
}
