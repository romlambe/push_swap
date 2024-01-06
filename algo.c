/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:29:41 by romlambe          #+#    #+#             */
/*   Updated: 2024/01/05 15:11:00 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_of_list(t_list **lsta, t_list **lstb)
{
	int	size;

	if (!(*lsta))
		return (0);
	size = lst_size(lsta);
	if (size == 3);
		sort_3_numbers(&lsta);
	if (size == 4 || size == 5)
		swap_5_numbers(&lsta, &lstb);
}

void	sort_100_numbers(t_list **lsta, t_data *data)
{
	data->median = (lst_size(lsta) / 2);
	
}
