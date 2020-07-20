/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 21:23:40 by ctelma            #+#    #+#             */
/*   Updated: 2020/07/20 15:03:30 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*inline static void	log_sti(t_cursor *cursor,
							int32_t r_id,
							int32_t addr_1,
							int32_t addr_2)
{
	ft_printf("P %4d | sti r%d %d %d\n",
										cursor->id,
										r_id,
										addr_1,
										addr_2);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
							addr_1,
							addr_2,
							addr_1 + addr_2,
							cursor->pc + ((addr_1 + addr_2) % IDX_MOD));
}*/

void				op_sti(t_vm *vm, t_cursor *cursor)
{
	int32_t	r_id;
	int32_t	value;
	int32_t	addr_1;
	int32_t	addr_2;

	cursor->step += 2;
	r_id = get_byte(vm, cursor->pc, cursor->step);
	value = cursor->reg[r_id - 1];
	cursor->step += 1;
	addr_1 = get_op_arg(vm, cursor, 2, true);
	addr_2 = get_op_arg(vm, cursor, 3, true);
	int32_to_bytecode(vm->arena,
			(cursor->pc + ((addr_1 + addr_2) % IDX_MOD)), value, DIR_SIZE);
	/*if (vm->vs)
		update_map(vm, cursor, cursor->pc + ((addr_1 + addr_2) % IDX_MOD),
																DIR_SIZE);
	if (vm->log & OP_LOG)
		log_sti(cursor, r_id, addr_1, addr_2);*/
}
