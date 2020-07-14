/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:32:21 by ddamaris          #+#    #+#             */
/*   Updated: 2020/07/13 14:32:43 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	is_positive_number(char *string)
{
	int	l;
	char 	*str;

	str = string;
	l = ft_strlen(str);
	if (l <= 11 && ((*str >= '0' && *str <= '9') ||
		(*str == '+' && *(str + 1) != '\0')))
	{
		str++;
		while (*str)
		{
			if (!(*str >= '0' && *str <= '9'))
				return (0);
			str++;
		}
	}
	else
		return (0);
	return (1);
}

int    	ft_strtoint(char *str)
{
	long	num;
	char	*s;

	num = 0;
	if (is_positive_number(str))
	{
		if (*str == '+')
			str++;
		while (*str)
			num = num * 10 + (*str++ - '0');
		if (num >= 0 && num <= 2147483647)
			return ((int) num);
	}
	else
		return (-1);
}

int file_is_cor(char *str)
{
	while (*str && *str != '.')
		str++;
	if (*str == '.' && !ft_strcmp(++str, "cor"))
		return (1);
	else
		return (0);
}