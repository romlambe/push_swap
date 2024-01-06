/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:51:43 by romlambe          #+#    #+#             */
/*   Updated: 2024/01/06 18:26:32 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	add_node(&lsta, 3);
	add_node(&lsta, 4);
	add_node(&lsta, 2);
    add_node(&lsta, 5);
    add_node(&lsta, 1);
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
