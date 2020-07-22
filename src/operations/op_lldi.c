/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 21:23:25 by ctelma            #+#    #+#             */
/*   Updated: 2020/07/22 20:39:16 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*inline static void	log_lldi(t_cursor *cursor,
							int32_t addr_1,
							int32_t addr_2,
							int32_t r_id)
{
	ft_printf("P %4d | lldi %d %d r%d\n", cursor->id, addr_1, addr_2, r_id);
	ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
											addr_1,
											addr_2,
											addr_1 + addr_2,
											cursor->pc + (addr_1 + addr_2));
}*/

void				op_lldi(t_vm *vm, t_cursor *cursor)
{
	int32_t	addr_1;
	int32_t	addr_2;
	int32_t	r_id;

	cursor->step += 2;
	addr_1 = get_op_arg(vm, cursor, 1, true);
	addr_2 = get_op_arg(vm, cursor, 2, true);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[r_id - 1] = bytecode_to_int32(vm->arena,
			cursor->pc + (addr_1 + addr_2), DIR_SIZE);
	cursor->step += 1;
	/*if (vm->log & OP_LOG)
		log_lldi(cursor, addr_1, addr_2, r_id);*/
}
