/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:34:21 by ddamaris          #+#    #+#             */
/*   Updated: 2020/07/15 12:36:43 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			run_vm(t_vm *vm)
{
	t_cursor	*cursor;

	while (vm->cursors_num)
	{
		if (vm->dump_fl == vm->cur_cycle)
		{
			print_dump(vm->arena);
			print_error("Aborting execution");
		}
		cursor = vm->cursors;
		while (currsor)
		{
			do_operation(cursor, vm);
			cursor = cursor->next;
		}
		if (vm->cycles_to_die == vm->cycles_after_check
			|| vm->cycles_to_die <= 0)
			check_cursor_to_die(vm);
		vm->cur_cycle++;
		vm->cycles_after_check++;
	}
}