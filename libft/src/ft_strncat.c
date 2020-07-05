/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:25:38 by dheredat          #+#    #+#             */
/*   Updated: 2020/05/26 10:14:47 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*p_s1;
	char	*p_s2;
	int		i;

	p_s1 = (char*)s1;
	p_s2 = (char*)s2;
	i = 0;
	while (*(p_s1 + i))
		i++;
	while (n-- && *(p_s2))
		*(p_s1 + i++) = *(p_s2++);
	*(p_s1 + i) = '\0';
	return (s1);
}
