/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 15:31:15 by ctelma            #+#    #+#             */
/*   Updated: 2020/07/19 17:08:28 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void free_players(t_player **players, int p_num)
{
	int i;

	i = 0;
	while (i < p_num)
	{
		if (players[i]->name)
			free(players[i]->name);
		if (players[i]->comment)
			free(players[i]->comment);
		if (players[i]->code)
			free(players[i]->code);
		if (players[i])
			free(players[i]);
		i++;
	}
}

static void free_cursor(t_cursor **cursor)
{
	t_cursor	*current;
	t_cursor	*delete;

	current = *cursor;
	while (current)
	{
		delete = current;
		current = current->next;
		ft_memdel((void **)&delete);
	}
	*cursor = NULL;
}

void		free_vm(t_vm *vm)
{
	free_players(*(vm->players), vm->players_num);
	free_cursor(&(vm->cursors));
	free(vm);
}