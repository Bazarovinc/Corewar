/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:18:24 by dheredat          #+#    #+#             */
/*   Updated: 2020/07/23 13:51:15 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	return (c >= 97 && c <= 122) ? 1 : 0;
}

int			ft_toupper(int c)
{
	return (ft_islower(c)) ? (c - 32) : c;
}
