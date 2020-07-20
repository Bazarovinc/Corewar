/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 21:24:07 by ctelma            #+#    #+#             */
/*   Updated: 2020/07/18 21:24:07 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_xor(t_cursor *cursor, int32_t value_1, int32_t value_2,
						int32_t r_id)
{
	ft_printf("cursor of %10s executes operation: ", cursor->player->name);
	ft_printf(" xor %d %d r%d\n", value_1, value_2, r_id);
}

void				op_xor(t_vm *vm, t_cursor *cursor)
{
	int32_t	value_1;
	int32_t	value_2;
	int32_t	value;
	int32_t	r_id;

	cursor->step += OP_CODE_LEN + ARGS_CODE_LEN;
	value_1 = get_op_arg(vm, cursor, 1, true);
	value_2 = get_op_arg(vm, cursor, 2, true);
	value = value_1 ^ value_2;
	cursor->carry = !value;
	r_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[r_id - 1] = value;
	cursor->step += REG_LEN;
	if (vm->stat_fl)
		print_xor(cursor, value_1, value_2, r_id);
}
