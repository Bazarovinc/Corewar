/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 11:27:21 by ddamaris          #+#    #+#             */
/*   Updated: 2020/07/14 11:27:43 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned char	*read_str(int fd, size_t len)
{
	size_t			size;
	unsigned char	*tmp;

	tmp = (unsigned char *)ft_strnew(len);
	size = read(fd, tmp, len);
	if (size == -1)
	{
		free (tmp);
		print_error("ERROR: Can't open champion file");
	}
	if (size < len)
	{
		free(tmp);
		print_error("ERROR: Invalid champion file");
	}
	return (tmp);
}

static void		check_zero(int fd)
{
	char		*str;

	str = read_str(fd, 4);
	if (!(str[0] == 0 && str[1] == 0 && str[2] == 0 && str[3] == 0))
	{
		free(str);
		print_error("ERROR: No null control bytes");
	}
}
static int 			parse_code_size(int fd)
{
	unsigned char	*str;
	int32_t			res;

	res = 0;
	str = read_str(fd, 4);
	res = str[3] + str[2] * 256 + str[1] * 65536 + str[0] * 16777216;
	if (res > CHAMP_MAX_SIZE)
		print_error("ERROR: Invalid code size");
	return (res);
}

void				parse_champion(int fd, t_player *player)
{
	unsigned char	*str;

	str = read_str(fd, 4);
	if (!(str[0] == 0 && str[1] == 234 && str[2] == 131 && str[3] == 243))
	{
		free(str);
		print_error("ERROR: Invalid magic header");
	}
	player->name = read_str(fd, PROG_NAME_LENGTH);
	check_zero(fd);
	player->code_size = parse_code_size(fd);
	player->comment = read_str(fd, COMMENT_LENGTH);
	check_zero(fd);
	player->code = read_str(fd, player->code_size);
}
