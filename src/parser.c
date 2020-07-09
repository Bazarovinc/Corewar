/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:32:21 by ddamaris          #+#    #+#             */
/*   Updated: 2020/07/08 14:32:43 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	parse_dump_flag(char **argv, t_vm *vm)
{
	if (!vm->dump_fl && ft_strtoint(*(*argv + 1), true))
	{
		if ((vm->dump_cycle = ft_atoi(*(*argv + 1))) < 0)
			vm->dump_cycle = -1;
		vm->dump_fl = 64;
		(*argv) += 2;
	}
	else
		print_usage();
	return (1);
}

static void		parse_n_flag(char **argv, t_vm *vm)
{
	int id;

	id = 0;

}

void 	parser(t_vm *vm, char **argv)
{
	argv++;
	while (argv)
	{
		if (!ft_strcmp(*argv, "-dump") && parse_dump_flag(++argv, vm))
			argv++;
		else if (!ft_strcmp(*argv, "-n") && parse_n_flag(++argv, vm))
			argv++;
		else if (!ft_strcmp(*argv, "-visu"))
			vm->vis_fl = 1;
		else if (!ft_strcmp(arg, "-aff"))
			parse_aff(parser, vm);
		else if (!ft_strcmp(arg, "-alive"))
			parse_live(parser, vm);
		argv++;
	}
}