/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:51:43 by romlambe          #+#    #+#             */
/*   Updated: 2024/01/04 16:52:30 by romlambe         ###   ########.fr       */
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

t_list *find_highest_node(t_list *lst)
{
	int		highest;
	t_list	*highest_node;

	if (lst == NULL)
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

t_list	*swap_2_numbers(t_list **lst, int index)
{
	define_index(lst);
	if ((*lst)->index > index)
		ft_sa(lst, 1);
	return (*lst);
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
	first_smallest_node = find_smallest_node(lst);
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


void    add_node(t_list **lst, int content)
{
    t_list    *new_node;
    t_list    *temp;

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

void    print_lst(const t_list *lst)
{
    const t_list    *current;

    current = lst;
    if (!lst)
        return ;
    while (current != NULL)
    {
        printf("%d (%d)\n", current->content, current->index);
        current = current->next;
    }
}
int    main(void)
{
    t_list    *lsta = NULL;
    t_list    *lstb = NULL;

	add_node(&lsta, 1);
	add_node(&lsta, 4);
	add_node(&lsta, 2);
    add_node(&lsta, 3);
    // add_node(&lsta, 6);
    // add_node(&lsta, 9);

    printf("Voici la liste : \n");
    print_lst(lsta);
    printf("\n");
	define_index(&lsta);
	//swap_2_numbers(&lsta,lsta->next->index);
	// sort_3_numbers(&lsta);
	swap_5_numbers(&lsta, &lstb);
    printf("\nVoici la liste apres les modifications : \n");
    print_lst(lsta);
	printf("\n");
    write(1, "\n", 1);
    return (0);
}
