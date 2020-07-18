/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 21:24:11 by ctelma            #+#    #+#             */
/*   Updated: 2020/07/18 21:24:11 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*inline static void	log_zjmp(t_cursor *cursor, int32_t addr)
{
	ft_printf("P %4d | zjmp %d %s\n",
									cursor->id,
									addr,
									(cursor->carry) ? "OK" : "FAILED");
}*/

void				op_zjmp(t_vm *vm, t_cursor *cursor)
{
	int32_t addr;

	cursor->step += OP_CODE_LEN;
	addr = get_op_arg(vm, cursor, 1, true);
	if (cursor->carry)
	{
		//if (vm->vs)
		//	clear_cursor(vm, cursor);
		cursor->pc = address_norming(cursor->pc + (addr % IDX_MOD));
		//if (vm->vs)
		//	draw_cursor(vm, cursor);
		cursor->step = 0;
	}
	//if (vm->log & OP_LOG)
	//	log_zjmp(cursor, addr);
}
