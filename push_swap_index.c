/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:51:43 by romlambe          #+#    #+#             */
/*   Updated: 2023/12/06 16:33:16 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
t_list	*swap_2_numbers(t_list **lst, int index)
{
	define_index(lst);
	if ((*lst)->index > index)
		ft_sa(lst, 1);
	return (*lst);
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
    // t_list    *lstb = NULL;

    add_node(&lsta, 5);
    add_node(&lsta, 3);
    // add_node(&lsta, 2);
    // add_node(&lsta, 4);
    // add_node(&lsta, 7);
    // add_node(&lsta, 9);

    // define_index(&lsta);
    printf("Voici la liste : \n");
    print_lst(lsta);
    printf("\n");
	swap_2_numbers(&lsta,lsta->next->index);
    printf("\nVoici la liste apres les modifications : \n");
    print_lst(lsta);
    write(1, "\n", 1);
    return (0);
}
