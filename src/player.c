/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:32:21 by ddamaris          #+#    #+#             */
/*   Updated: 2020/07/13 16:32:43 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_player	*init_player(void)
{
	t_player	*player;

	if (!(player = (t_player *)ft_memalloc(sizeof(t_player))))
		print_error("ERROR: Memory allocation error");
	player->id = 0;
	player->name = NULL;
	player->comment = NULL;
	player->code_size = 0;
	player->code = NULL;
	player->last_live = 0;
	player->curr_lives_num = 0;
	player->prev_lives_num = 0;
	player->next = NULL;
	return (player);
}

static void	put_player(t_player *player, t_vm *vm)
{
	int		i;

	i = 0;
	while (vm->players[i])
		i++;
	player->id = i + 1;
	vm->players[i] = player;
}

void		*add_player(char *filename, int id, t_vm *vm)
{
	t_player	*player;
	t_player 	*tmp;
	int			fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
		print_error("ERROR: Can't open file with champion");
	player = init_player();
	player->id = id;
	parse_champion(fd, player);
	if (id)
	{
		if (!vm->players[id - 1])
			vm->players[id - 1] = player;
		else
		{
			tmp = vm->players[id - 1];
			vm->players[id - 1] = player;
			put_player(tmp, vm);
		}
	}
	else
		put_player(player, vm);
}
