/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:09:21 by ddamaris          #+#    #+#             */
/*   Updated: 2020/07/14 22:12:43 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void			init_cursor(t_player *player, t_cursor *cursor, int32_t pc)
{
	int32_t		cursor_id;

	cursor->carry = 0;
	cursor->op_code = 0;
	cursor->last_live_cycle = 0;
	cursor->cycles_to_exec = 0;
	cursor->pc = pc;
	cursor->step = 0;
	cursor->reg[0] = -(player->id);
	cursor->player = player;
	cursor->next = NULL;
}

void			add_cursor(t_player *player, int32_t pc, t_vm *vm)
{
	t_cursor	*cursor;
	t_cursor	*tmp;

	cursor = NULL;
	if (!(cursor = (t_cursor *)malloc(sizeof(t_cursor))))
		print_error("ERROR: Memory allocation error");
	init_cursor(player, cursor, 0);
	if (!vm->cursors)
		vm->cursors = cursor;
	else
	{
		tmp = vm->cursors;
		vm->cursors = cursor;
		vm->cursors->next = tmp;
	}
}
void			init_cursors(t_vm *vm)
{
	int			i;

	i = MAX_PLAYERS - 1;
	while (i >= 0)
	{
		if (vm->players[i])
			add_cursor(vm->players[i], vm->players[i]->pc, vm);
		i--;
	}
}

void			init_arena(t_vm *vm)
{
	int			i;
	int32_t		pc;

	i = 0;
	pc = 0;
	while (i < MAX_PLAYERS)
	{
		if (vm->players[i])
		{
			ft_memcpy(&(vm->arena[pc]), vm->players[i]->code,
				(vm->players[i]->code_size));
			vm->players[i]->pc = pc;
			pc += MEM_SIZE / vm->players_num;
		}
		i++;
	}
}