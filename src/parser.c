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

static void	parse_dump_flag(char **argv, t_vm *vm)
{
	int	num;

	num = 0;
	if ((num = ft_strtoint(*argv + 1)) >= 0)
		vm->dump_fl = num;
	else
		print_error("ERROR: Wrong argument for -dump");
}

static int		parse_n_flag(char **argv, t_vm *vm)
{
	int id;

	id = 0;
	if ((id = ft_strtoint(*argv)) >= 0 && id <= MAX_PLAYERS)
	{
		if (ft_strcmp(*(argv + 1), ".cor"))
			add_player(*(argv + 1), id, vm);
	}
	return (1);
}

void 	parser(t_vm *vm, char **argv)
{
	argv++;
	while (*argv)
	{
		if (!ft_strcmp(*argv, "-dump"))
			parse_dump_flag(++argv, vm);
		else if (!ft_strcmp(*argv, "-n") && parse_n_flag(++argv, vm))
			argv++;
//		else if (!ft_strcmp(*argv, "-visu"))
//			vm->vis_fl = 1;
//		else if (!ft_strcmp(*argv, "-aff"))
//			parse_aff(parser, vm);
//		else if (!ft_strcmp(*argv, "-stat"))
//			vm->stat_fl = 1;
		else if (file_is_cor(*argv))
			add_player(*argv, 0, vm);
		argv++;
	}
}