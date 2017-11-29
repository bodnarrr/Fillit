/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:53:07 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/26 18:21:42 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <stdint.h>
# include <string.h>

# define FULL_BLOCK			'#'
# define EMPTY_BLOCK		'.'

# define ISVALID_ELEM(c) ((c == FULL_BLOCK || c == EMPTY_BLOCK) ? 1 : 0)

typedef	struct			s_tetr
{
	uint8_t				id;
	char				name;
	char				**matrix;
	struct s_tetr		*next;
}						t_tetr;

t_tetr					*ft_tetrnew(const uint8_t id);
void					ft_tetradd(t_tetr **start, t_tetr *new);
void					ft_tetrdel(t_tetr **start);
t_tetr					*ft_readfile(const char *file_name);
uint8_t					ft_get_id(const char *tetrimino);

int						ft_min_square_size(t_tetr *head, int *fig_nb);
void					ft_make_all_matrix(t_tetr *head, int s);
int						ft_bigmatrix_size(int s, t_tetr *head);
char					**ft_make_bigmatrix(int size, t_tetr *head);
char					**ft_clear_rows(char **matrix, int pos_y);
void					ft_print_result(char **matrix, int s);
int						ft_find_line_for_solution(char **matrix);
void					ft_clear_same_letter (char **matrix, int pos_y);
void					ft_change_symbol_in_row(char **matrix, int pos_y);
int						ft_l_counter(char **matrix);
int						ft_b_counter(char **matrix);
char					**ft_copy_matrix(char **matrix);
void					ft_swap_rows(char **copy, char name);
char					*ft_fillit(char **matrix, int s, \
		const int fcount, char c);
void					ft_del_matrix(char ***matrix);

char					**ft_matrix_one(t_tetr *head, int s, size_t j);
char					**ft_matrix_two(t_tetr *head, int s, size_t j);
char					**ft_matrix_three(t_tetr *head, int s, size_t j);
char					**ft_matrix_four(t_tetr *head, int s, size_t j);
char					**ft_matrix_five(t_tetr *head, int s, size_t j);

#endif
