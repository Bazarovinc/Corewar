/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 21:23:10 by ctelma            #+#    #+#             */
/*   Updated: 2020/07/18 21:23:10 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static void	print_live(t_cursor *cursor)
{
	ft_printf("cursor of %10s executes operation: ", cursor->player->name);
	ft_printf("live %d (%s)\n", FT_ABS(cursor->player->id),
				cursor->player->name);
}

void	print_live_msg(int32_t player_id, char *player_name)
{
	ft_printf("Player %d (%s) is said to be alive\n", player_id, player_name);
}

void				op_live(t_vm *vm, t_cursor *cursor)
{
	int32_t		player_id;
	t_player	*player;

	cursor->step += OP_CODE_LEN;
	player_id = get_op_arg(vm, cursor, 1, false);
	vm->lives_num++;
	cursor->last_live_cycle = vm->cur_cycle;
	player = NULL;
	if (player_id == cursor->player->id)
	{
		player = vm->players[FT_ABS(player_id) - 1];
		player->last_live_cycle = vm->cur_cycle;
		player->curr_lives_num++;
		vm->last_alive = player;
/*		if (vm->vs)
		{
			vm->vs->map[cursor->pc].wait_cycles_live = CYCLE_TO_WAIT;
			vm->vs->map[cursor->pc].player_live = player;
		}*/
		if (vm->alive_fl)
			print_live_msg(FT_ABS(player_id), player->name);
	}
	if (vm->stat_fl)
		print_live(cursor);
}
