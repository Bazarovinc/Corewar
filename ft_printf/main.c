/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 20:13:51 by ddamaris          #+#    #+#             */
/*   Updated: 2019/11/21 20:15:17 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <float.h>

int		main(void)
{
//	printf("|%5.8f|\n|%-5.8f|\n|%+5.8f|\n|% 5.8f|\n|%#5.8f|\n|%05.8f|\n", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN);

	printf("|%Lf|\n", LDBL_MAX);
	ft_printf("|%Lf|\n", LDBL_MAX);

	return (0);
}
