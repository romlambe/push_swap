/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:48:34 by romlambe          #+#    #+#             */
/*   Updated: 2023/11/22 15:36:47 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "unistd.h"
# include "stdlib.h"
# include <stdio.h>

typedef	struct	s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}				t_list;

#endif
