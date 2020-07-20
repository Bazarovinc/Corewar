/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 21:23:25 by ctelma            #+#    #+#             */
/*   Updated: 2020/07/18 21:23:25 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_lldi(t_cursor *cursor, int32_t addr_1, int32_t addr_2,
						int32_t r_id)
{
	ft_printf("cursor of %10s executes operation: ", cursor->player->name);
	ft_printf("lldi %d %d r%d", addr_1, addr_2, r_id);
	ft_printf("\t\t| -> load from %d + %d = %d (with pc %d)\n",
			addr_1, addr_2, addr_1 + addr_2, cursor->pc + (addr_1 + addr_2));
}

void				op_lldi(t_vm *vm, t_cursor *cursor)
{
	int32_t	addr_1;
	int32_t	addr_2;
	int32_t	r_id;

	cursor->step += OP_CODE_LEN + ARGS_CODE_LEN;
	addr_1 = get_op_arg(vm, cursor, 1, true);
	addr_2 = get_op_arg(vm, cursor, 2, true);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[r_id - 1] = bytecode_to_int32(vm->arena,
			cursor->pc + (addr_1 + addr_2), DIR_SIZE);
	cursor->step += REG_LEN;
	if (vm->stat_fl)
		print_lldi(cursor, addr_1, addr_2, r_id);
}
