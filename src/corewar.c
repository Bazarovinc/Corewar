/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 14:32:21 by ddamaris          #+#    #+#             */
/*   Updated: 2020/07/05 18:32:43 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_vm		*init_vm(void)
{
	t_vm *vm;

	if (!(vm = (t_vm *)malloc(sizeof(t_vm))))
		print_error("ERROR: Memory allocation error");
	vm->players_num = 0;
	vm->last_alive = NULL;
	vm->cursors = NULL;
	vm->cursors_num = 0;
	vm->lives_num = 0;
	vm->cycles = 0;
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
//		run_vm(vm);
//		visualisation;
//		print_winner(vm);
//		free_vm;
	}
	else
		print_usage();
	return (0);
}