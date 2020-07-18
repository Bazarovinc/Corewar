/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 21:22:49 by ctelma            #+#    #+#             */
/*   Updated: 2020/07/18 21:22:49 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*inline static void	log_ld(uint32_t cursor_id, int32_t value, int32_t r_id)
{
	ft_printf("P %4d | ld %d r%d\n", cursor_id, value, r_id);
}*/

void				op_ld(t_vm *vm, t_cursor *cursor)
{
	int32_t	value;
	int32_t	r_id;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	value = get_op_arg(vm, cursor, 1, true);
	cursor->carry = !value;
	r_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[INDEX(r_id)] = value;
	cursor->step += REG_LEN;
	/*if (vm->log & OP_LOG)
		log_ld(cursor->id, value, r_id);*/
}
