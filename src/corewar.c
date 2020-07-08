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

int			main(int argc, char **argv)
{
	t_vm *vm;

	if (argc >= 2)
	{
		parsing(argc, argv);
		print_introducing(vm->players, vm->players_num);
		run_vm(vm);
		visualisation;
		print_winner(vm);
		free_vm;
	}
	else
		print_usage();
	return (0);
}