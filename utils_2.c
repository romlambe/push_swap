/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:26:00 by romlambe          #+#    #+#             */
/*   Updated: 2024/01/06 18:26:19 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_smallest_node(t_list **lst)
{
	t_list *min;
	t_list *temp;

	min = NULL;
	temp = *lst;
	while (temp)
	{
		if(temp->index == -1 && (min == NULL || temp->content < min->content))
			min = temp;
		temp = temp->next;
	}
	return (min);
}

t_list	*define_index(t_list **lst)
{
	t_list	*min;
	int		index;

	index = 1;
	while(1)
	{
		min = find_smallest_node(lst);
		if (min == NULL)
			return (NULL);
		min->index = index;
		index++;
	}
	return (min);
}

t_list *find_smallest_index(t_list **lsta)
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
