/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 21:23:35 by ctelma            #+#    #+#             */
/*   Updated: 2020/07/22 20:39:16 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*inline static void	log_st(uint32_t cursor_id, int32_t r_id, int32_t addr)
{
	ft_printf("P %4d | st r%d %d\n", cursor_id, r_id, addr);
}

inline static void	vs_st(t_vm *vm, t_cursor *cursor, int32_t addr)
{
	if (vm->vs)
		update_map(vm, cursor, cursor->pc + (addr % IDX_MOD), DIR_SIZE);
}*/

void				op_st(t_vm *vm, t_cursor *cursor)
{
	int32_t	r_id;
	int32_t	r_value;
	int32_t	addr;

	cursor->step += 2;
	r_id = get_byte(vm, cursor->pc, cursor->step);
	r_value = cursor->reg[r_id - 1];
	cursor->step += 1;
	if (cursor->args_types[1] == T_REG)
	{
		addr = get_byte(vm, cursor->pc, cursor->step);
		cursor->reg[addr - 1] = r_value;
		cursor->step += 1;
	}
	else
	{
		addr = bytecode_to_int32(vm->arena,
							cursor->pc + cursor->step, IND_SIZE);
		int32_to_bytecode(vm->arena, cursor->pc + (addr % IDX_MOD),
							r_value, DIR_SIZE);
		//vs_st(vm, cursor, addr);
		cursor->step += IND_SIZE;
	}
	//if (vm->log & OP_LOG)
	//	log_st(cursor->id, r_id, addr);
}
