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
	unsigned char		*name;
	unsigned char		*comment;
	size_t				code_size;
	unsigned char		*code;
	size_t				last_live;
	size_t				curr_lives_num;
	size_t				prev_lives_num;
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
	u_int8_t			arena[MEM_SIZE];
	t_player			*players[MAX_PLAYERS];
	int					players_num;
	t_player			*last_alive;
	t_cursor			*cursors;
	size_t				cursors_num;
	size_t				lives_num;
	size_t				cycles;
	size_t				cycles_to_die;
	size_t				cycles_after_check;
	size_t				checks_num;
	int 				vis_fl;
	int 				stat_fl;
	size_t 				dump_fl;
	int					aff_fl;
}						t_vm;

typedef struct			s_op
{
	char				*name;
	int8_t				code;
	int8_t				args_num;
	char				args_types_code;
	int8_t				args_types[3];
	char				modify_carry;
	int8_t				t_dir_size;
	unsigned int		cycles;
}						t_op;

static t_op				g_op[16] = {
		{
				.name = "live",
				.code = 0x01,
				.args_num = 1,
				.args_types_code = false,
				.args_types = {T_DIR, 0, 0},
				.modify_carry = false,
				.t_dir_size = 4,
				.cycles = 10,
		},
		{
				.name = "ld",
				.code = 0x02,
				.args_num = 2,
				.args_types_code = true,
				.args_types = {T_DIR | T_IND, T_REG, 0},
				.modify_carry = true,
				.t_dir_size = 4,
				.cycles = 5,
		},
		{
				.name = "st",
				.code = 0x03,
				.args_num = 2,
				.args_types_code = true,
				.args_types = {T_REG, T_REG | T_IND, 0},
				.modify_carry = false,
				.t_dir_size = 4,
				.cycles = 5,
		},
		{
				.name = "add",
				.code = 0x04,
				.args_num = 3,
				.args_types_code = true,
				.args_types = {T_REG, T_REG, T_REG},
				.modify_carry = true,
				.t_dir_size = 4,
				.cycles = 10,
		},
		{
				.name = "sub",
				.code = 0x05,
				.args_num = 3,
				.args_types_code = true,
				.args_types = {T_REG, T_REG, T_REG},
				.modify_carry = true,
				.t_dir_size = 4,
				.cycles = 10,
		},
		{
				.name = "and",
				.code = 0x06,
				.args_num = 3,
				.args_types_code = true,
				.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
				.modify_carry = true,
				.t_dir_size = 4,
				.cycles = 6,
		},
		{
				.name = "or",
				.code = 0x07,
				.args_num = 3,
				.args_types_code = true,
				.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
				.modify_carry = true,
				.t_dir_size = 4,
				.cycles = 6,
		},
		{
				.name = "xor",
				.code = 0x08,
				.args_num = 3,
				.args_types_code = true,
				.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
				.modify_carry = true,
				.t_dir_size = 4,
				.cycles = 6,
		},
		{
				.name = "zjmp",
				.code = 0x09,
				.args_num = 1,
				.args_types_code = false,
				.args_types = {T_DIR, 0, 0},
				.modify_carry = false,
				.t_dir_size = 2,
				.cycles = 20,
		},
		{
				.name = "ldi",
				.code = 0x0A,
				.args_num = 3,
				.args_types_code = true,
				.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
				.modify_carry = false,
				.t_dir_size = 2,
				.cycles = 25,
		},
		{
				.name = "sti",
				.code = 0x0B,
				.args_num = 3,
				.args_types_code = true,
				.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
				.modify_carry = false,
				.t_dir_size = 2,
				.cycles = 25,
		},
		{
				.name = "fork",
				.code = 0x0C,
				.args_num = 1,
				.args_types_code = false,
				.args_types = {T_DIR, 0, 0},
				.modify_carry = false,
				.t_dir_size = 2,
				.cycles = 800,
		},
		{
				.name = "lld",
				.code = 0x0D,
				.args_num = 2,
				.args_types_code = true,
				.args_types = {T_DIR | T_IND, T_REG, 0},
				.modify_carry = true,
				.t_dir_size = 4,
				.cycles = 10,
		},
		{
				.name = "lldi",
				.code = 0x0E,
				.args_num = 3,
				.args_types_code = true,
				.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
				.modify_carry = true,
				.t_dir_size = 2,
				.cycles = 50,
		},
		{
				.name = "lfork",
				.code = 0x0F,
				.args_num = 1,
				.args_types_code = false,
				.args_types = {T_DIR, 0, 0},
				.modify_carry = false,
				.t_dir_size = 2,
				.cycles = 1000,
		},
		{
				.name = "aff",
				.code = 0x10,
				.args_num = 1,
				.args_types_code = true,
				.args_types = {T_REG, 0, 0},
				.modify_carry = false,
				.t_dir_size = 4,
				.cycles = 2,
		}
};

void					print_introducing(t_vm *vm);
void					print_usage(void);
void					print_error(char *error);
int						file_is_cor(char *str);
void					parser(t_vm *vm, char **argv);
int						ft_strtoint(char *str);
void					parse_champion(int fd, t_player *player);
unsigned char			*read_str(int fd, size_t len);
void					*add_player(char *filename, int id, t_vm *vm);

#endif
