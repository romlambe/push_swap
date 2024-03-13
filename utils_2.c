/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:26:00 by romlambe          #+#    #+#             */
/*   Updated: 2024/01/16 14:14:46 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i + 1);
}

t_list	*find_smallest_index(t_list **lsta)
{
	int		smallest;
	t_list	*smallest_node;

	if ((*lsta == NULL || lsta == NULL))
		return (NULL);
	smallest = INT_MAX;
	while (*lsta)
	{
		if ((*lsta)->content < smallest)
		{
			smallest = (*lsta)->content;
			smallest_node = *lsta;
		}
		lsta = &(*lsta)->next;
	}
	return (smallest_node);
}

t_list	*find_second_smallest_index(t_list **lst)
{
	int		second_smallest_value;
	t_list	*second_smallest_node;
	t_list	*smallest_node;
	t_list	*temp;

	if ((*lst == NULL || lst == NULL))
		return (NULL);
	temp = *lst;
	smallest_node = find_smallest_index(&temp);
	second_smallest_value = INT_MAX;
	while (temp)
	{
		if (temp->content < second_smallest_value && temp != smallest_node)
		{
			second_smallest_value = temp->content;
			second_smallest_node = temp;
		}
		temp = temp->next;
	}
	return (second_smallest_node);
}

int	find_highest_nb(t_list *lst)
{
	int	highest_num;

	highest_num = lst->content;
	lst = lst->next;
	while (lst)
	{
		if (lst->content > highest_num)
			highest_num = lst->content;
		lst = lst->next;
	}
	return (highest_num);
}

int	find_highest_index(t_list *lst, int max)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->content == max)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}
