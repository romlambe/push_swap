/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:58:06 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/21 16:38:06 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_list **lst, int content)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->index = -1;
	new_node->next = NULL;
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	sort_lst(t_list **lsta, t_list **lstb, int *array, t_data *data)
{
	if (is_sorted(lsta) != -1)
	{
		if (lst_size(lsta) == 2)
			swap_2_numbers(lsta);
		else if (lst_size(lsta) == 3)
			sort_3_numbers(lsta);
		else if (lst_size(lsta) <= 5)
			swap_5_numbers(lsta, lstb);
		else
		{
			data->t_num = lst_size(lsta);
			data->median = (data->t_num / 2);
			if (data->t_num <= 30)
				data->n = 5;
			else if (data->t_num <= 150)
				data->n = 8;
			else
				data->n = 18;
			data->size = (data->t_num / data->n);
			data->start = data->median - data->size;
			data->end = data->median + data->size;
			sort_stack_a_to_b(lsta, lstb, array, data);
			sort_stack_b_to_a(lsta, lstb, array, data);
		}
	}
}

int	is_sorted(t_list **lst)
{
	while (lst && (*lst)->next)
	{
		if ((*lst)->content > (*lst)->next->content)
			return (0);
		lst = &(*lst)->next;
	}
	return (-1);
}

void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if ((j + 1 < size) && array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*sort_array(t_list *lst)
{
	int	i;
	int	*array;

	i = 0;
	array = (int *)malloc(sizeof(int) * (lst_size(&lst)));
	while (lst)
	{
		array[i] = lst->content;
		lst = lst->next;
		i++;
	}
	bubble_sort(array, i);
	return (array);
}
