/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whorpe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:00:33 by whorpe            #+#    #+#             */
/*   Updated: 2019/11/03 18:31:00 by whorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# define I_TET (int[8]) {0,0,1,0,2,0,3,0}
# define IH_TET (int[8]) {0,0,0,1,0,2,0,3}
# define T_TET (int[8]) {0,0,0,1,0,2,1,1}
# define TD_TET (int[8]) {0,1,1,0,1,1,1,2}
# define TL_TET (int[8]) {0,1,1,0,1,1,2,1}
# define TR_TET (int[8]) {0,0,1,0,1,1,2,0}
# define O_TET (int[8]) {0,0,0,1,1,0,1,1}
# define L_TET (int[8]) {0,0,1,0,2,0,2,1}
# define LD_TET (int[8]) {0,0,0,1,1,1,2,1}
# define LL_TET (int[8]) {0,2,1,0,1,1,1,2}
# define LR_TET (int[8]) {0,0,0,1,0,2,1,0}
# define J_TET (int[8]) {0,1,1,1,2,0,2,1}
# define JD_TET (int[8]) {0,0,0,1,1,0,2,0}
# define JL_TET (int[8]) {0,0,0,1,0,2,1,2}
# define JR_TET (int[8]) {0,0,1,0,1,1,1,2}
# define S_TET (int[8]) {0,0,1,0,1,1,2,1}
# define SH_TET (int[8]) {0,1,0,2,1,0,1,1}
# define Z_TET (int[8]) {0,1,1,0,1,1,2,0}
# define ZH_TET (int[8]) {0,0,0,1,1,1,1,2}

typedef struct	s_tetrimin
{
	char				letter;
	int					*id;
	int					x_offset;
	int					y_offset;
	struct s_tetrimin	*next;
}				t_tetrimin;

typedef struct	s_block
{
	int			x;
	int			y;
	char		letter;
}				t_block;

void			ft_lstrev(t_tetrimin **list);
void			print_tab(char **tab, int size);
void			free_tab(char **tab, int size);
t_tetrimin		*free_list(t_tetrimin **list);
int				*detect_id(char **tab);
t_tetrimin		*create_list(char *str, char letter);
char			**split_tab(char *str);
t_tetrimin		*reading_tetris(int fd);
void			find_xymax(t_tetrimin *tet, int *xmax, int *ymax);
int				solve(char **tab, t_tetrimin *tet, int size);
char			**main_solve(t_tetrimin *tet, int *size);
int				verify_chars(char *str, int count);
int				checking_connections(char *str);
#endif
