/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 14:32:21 by ddamaris          #+#    #+#             */
/*   Updated: 2020/07/22 21:16:05 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_vm		*init_vm(void)
{
	t_vm *vm;

	vm = NULL;
	if (!(vm = (t_vm *)malloc(sizeof(t_vm))))
		error_func("r-", "ERROR: Memory allocation error", vm);
	vm->players_num = 0;
	vm->last_alive = NULL;
	vm->cursors = NULL;
	vm->cursors_num = 0;
	vm->lives_num = 0;
	vm->cur_cycle = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->cycles_after_check = 0;
	vm->checks_num = 0;
	vm->vis_fl = 0;
	vm->stat_fl = 0;
	vm->dump_fl = -1;
	vm->aff_fl = -1;
	return (vm);
}

int			main(int argc, char **argv)
{
	t_vm *vm;

	if (argc >= 2)
	{
		vm = init_vm();
		parser(vm, argv);
		print_introducing(vm);
		init_arena(vm);
		init_cursors(vm);
		run_vm(vm);
		print_winner(vm);
		free_vm(vm);
	}
	else
		print_usage(vm);
	return (0);
}