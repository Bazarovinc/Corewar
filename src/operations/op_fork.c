/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:49:17 by ablizniu          #+#    #+#             */
/*   Updated: 2020/07/20 16:18:45 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*inline static void	log_fork(t_cursor *cursor, int32_t addr)
{
	ft_printf("P %4d | fork %d (%d)\n",
										cursor->id,
										addr,
										cursor->pc + addr % IDX_MOD);
}*/

/*void	add_cursor_1(t_cursor **list, t_cursor *new)
{
    if (new)
        new->next = *list;
    *list = new;
}*/

void				op_fork(t_vm *vm, t_cursor *cursor)
{
	int32_t		addr;
	//t_cursor	*new;

	cursor->step += 1;
	addr = get_op_arg(vm, cursor, 1, true);
	duplicate_cursor(cursor, addr % IDX_MOD, vm);
	//add_cursor_1(&(vm->cursors), new);
	vm->cursors_num++;
	/*if (vm->log & OP_LOG)
		log_fork(cursor, addr);*/
}
