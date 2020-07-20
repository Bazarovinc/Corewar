/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 21:23:05 by ctelma            #+#    #+#             */
/*   Updated: 2020/07/18 21:23:05 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_lfork(t_cursor *cursor, int32_t addr)
{
	ft_printf("cursor of %10s executes operation: ", cursor->player->name);
	ft_printf("lfork %d (%d)\n", addr, cursor->pc + addr);
}

void				op_lfork(t_vm *vm, t_cursor *cursor)
{
	int32_t		addr;
	t_cursor	*new;

	cursor->step += OP_CODE_LEN;
	addr = get_op_arg(vm, cursor, 1, true);
	duplicate_cursor(cursor, addr % IDX_MOD, vm);
	if (vm->stat_fl)
		print_lfork(cursor, addr);
}
