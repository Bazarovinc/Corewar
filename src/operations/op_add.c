/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 19:32:52 by ctelma            #+#    #+#             */
/*   Updated: 2020/07/15 20:09:12 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_add(t_cursor *cursor, int32_t r1_id, int32_t r2_id,
                    int32_t r3_id)
{
	ft_printf("cursor of %10s executes operation: add ", cursor->player->name);
	ft_printf("r%d r%d r%d\n", r1_id, r2_id, r3_id);
}

void    op_add(t_vm *vm, t_cursor *cursor)
{
    int32_t	r1_id;
    int32_t	r2_id;
    int32_t	r3_id;
    int32_t	value;

    cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
    r1_id = get_byte(vm, cursor->pc, cursor->step);
    cursor->step += REG_LEN;
    r2_id = get_byte(vm, cursor->pc, cursor->step);
    cursor->step += REG_LEN;
    value = cursor->reg[INDEX(r1_id)] + cursor->reg[INDEX(r2_id)];
    cursor->carry = !value;
    r3_id = get_byte(vm, cursor->pc, cursor->step);
    cursor->reg[INDEX(r3_id)] = value;
    cursor->step += REG_LEN;
    if (vm->stat_fl)
        print_add(cursor, r1_id, r2_id, r3_id);
}