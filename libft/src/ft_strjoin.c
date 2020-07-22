/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 12:47:25 by dheredat          #+#    #+#             */
/*   Updated: 2020/07/22 20:39:16 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len_s1;
	size_t	len_s2;

	if (!(s1) || !(s2))
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 + len_s2 < len_s1 || len_s1 + len_s2 < len_s2
	|| !(newstr = (char*)ft_strnew(len_s1 + len_s2)))
		return (NULL);
	ft_strcpy(newstr, s1);
	ft_strcpy(newstr + len_s1, s2);
	return (newstr);
}
