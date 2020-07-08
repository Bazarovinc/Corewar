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

#ifndef VM_H
# define VM_H

# include "../libft/inc/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdbool.h>
# include <stdlib.h>
# include "op.h"
# include <fcntl.h>

typedef struct			s_player
{
	int					id;
	char				*name;
	char				*comment;
	int					code_size;
	unsigned char		*code;
	ssize_t				c_last_live;
	struct s_player		*next;
}						t_player;

typedef struct			s_cursor
{
	char				carry;
	unsigned char		op_code;
	ssize_t				c_last_live;
	int					cycles_to_exec;
	unsigned char		args_types[3];
	ssize_t				pc;
	unsigned int		step;
	int					reg[REG_NUMBER];
	t_player			*player;
	struct s_cursor		*next;
}						t_cursor;

typedef struct			s_vm
{
	unsigned char		arena[MEM_SIZE];
	t_player			*players[MAX_PLAYERS];
	int					players_num;
	t_player			*last_alive;
	t_cursor			*cursors;
	size_t				cursors_num;
	size_t				lives_num;
	ssize_t				cycles;
	ssize_t				cycles_to_die;
	ssize_t				cycles_after_check;
	size_t				checks_num;
	ssize_t				dump_cycle;
	int					dump_print_mode;
	char				live;
	char				aff;
}						t_vm;


#endif
