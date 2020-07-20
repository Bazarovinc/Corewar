/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:09:17 by ctelma            #+#    #+#             */
/*   Updated: 2020/07/20 15:03:30 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_aff(t_vm *vm, t_cursor *cursor)
{
    int32_t	r_id;
    //int32_t	value;

    cursor->step += 2;
    r_id = get_byte(vm, cursor->pc, cursor->step);
    //value = cursor->reg[INDEX(r_id)];
    cursor->step += 1;
    /*if (vm->display_aff)
        ft_printf("Aff: %c\n", (char)value);
    if (vm->vs)
    {
        vm->vs->aff_symbol = (char)value;
        vm->vs->aff_player = cursor->player;
    }*/
}