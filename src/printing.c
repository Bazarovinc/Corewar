/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:00:21 by ddamaris          #+#    #+#             */
/*   Updated: 2020/07/08 17:00:43 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			print_introducing(t_vm *vm)
{
	t_player	*player;
	int			i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < MAX_PLAYERS)
	{
		player = vm->players[i];
		if (player)
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				player->id, player->code_size, player->name, player->comment);
		i++;
	}
}

void			print_dump(u_int8_t *arena)
{
	int			i;
	int			j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.4p : ", i);
		j = 0;
		while (j < 32)
		{
			ft_printf("%.2x ", arena[i + j]);
			j++;
		}
		ft_printf("\n");
		i += 32;
	}
}

void		print_winner(t_vm *vm)
{
	ft_printf("Contestant %d, \"%s\", has won !\n", \
	vm->last_alive->id, vm->last_alive->name);
}

void		print_usage(void)
{
	ft_printf("Usage: ./corewar [ -dump <int num> ] "
			  "[-n <int num>] <champion.cor> <...>\n");
	exit(0);
}

void		print_error(char *error)
{
	ft_printf("%s\n", error);
	exit(0);
}
