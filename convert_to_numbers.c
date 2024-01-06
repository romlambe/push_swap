/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:48:56 by romlambe          #+#    #+#             */
/*   Updated: 2024/01/06 17:10:12 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')
			|| (str[0] == '-' && str[1] >= '0' && str <= '9')))
			return (-1);
		i++;
	}
	return (0);
}

int	available_size(long long digit)
{
	if (digit > INT_MAX || digit < INT_MIN)
		return (-1);
	return (0);
}

long long	atoi_conversion(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= '9' && str[i] <= '13'))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (-1);
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_atoi_ps(char *str)
{
	long long	res;
	long long	digit_size;
	int			digit;

	res = 0;
	digit = is_digit(str);
	if (digit == -1)
	{
		write (1, "Error", 6);
		return (-1);
	}
	res = atoi_conversion(str);
	digit_size = available_size(res);
	if (digit_size == -1)
	{
		write (1, "Error", 6);
		return (-1);
	}
	return ((int)res);
}
