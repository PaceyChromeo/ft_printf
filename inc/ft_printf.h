/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:00:17 by pjacob            #+#    #+#             */
/*   Updated: 2021/04/05 17:18:08 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define BASE_HEXA_UP "0123456789ABCDEF"
# define BASE_HEXA_DOWN "0123456789abcdef" 

typedef struct s_flag
{
	int		minus;
	int		zero;
	int		field;
	int		prec;
	int		star_f;
	int		star_p;
	int		index;
	int		dot;
	int		neg;
	int		ptr;
}				t_flag;

int		ft_printf(const char *input, ...);
int		ft_get_args(const char *str, int i, va_list args, t_flag *flags);
int		ft_putstr(const char *str, int i, va_list args, t_flag *flags);
int		ft_parse_str(const char *str, va_list args);
int		ft_get_char(va_list args, t_flag *flags);
int		ft_get_str(va_list args, t_flag *flags);
int		ft_get_pointer(va_list args, t_flag *flags);
int		ft_get_int(va_list args, t_flag *flags);
int		ft_get_uint(va_list args, t_flag *flags);
int		ft_get_hexa(va_list args, char c, t_flag *flags);
int		ft_get_percent(va_list args, t_flag *flags);
int		ft_isnt_convert(char c);
int		ft_flag_on(t_flag *flags);
int		ft_isspace(int c);
int		ft_dispatch_hexa(char *hexa, int len, long nbr, t_flag *flags);
int		ft_hexa_spe(long nbr, char *hexa, int len, t_flag *flags);
int		ft_putchar_fd_count(char c);
char	*ft_uitoa(unsigned int nb);
char	*ft_uitoa_base(unsigned int nbr, char *base);
char	*ft_ullitoa_base(unsigned long long nbr, char *base);
char	*ft_treat_space(int size);
char	*ft_treat_zero(int size);
void	ft_treat_str(char *str, t_flag *flags);
void	ft_treat_char(unsigned char c, size_t size, t_flag *flags);
void	ft_treat_int(char *str, t_flag *flags);
void	ft_treat_hexa(int len, char *hexa, t_flag *flags);
void	ft_putstr_prec(char *str, size_t size, char *space, t_flag *flags);
void	ft_putnbr_prec(char *str, char *space, t_flag *flags);
void	ft_putnbr_hexa_prec(char *hexa, char *space, t_flag *flags);
void	ft_putnbr_with_zero(char *space, t_flag *flags);
void	ft_treat_star(va_list args, t_flag *flags);
void	ft_putnbr_zero(char *space, char *zero,	char *nbr, t_flag *flags);
t_flag	*ft_get_flags(const char *str, int i, t_flag *flags);
t_flag	*ft_treat_flag(char c, t_flag *flags);
t_flag	*ft_treat_minfield(const char *str, int size, t_flag *flags);
t_flag	*ft_treat_prec(const char *str, int size, t_flag *flags);
t_flag	ft_flag_init(void);

#endif
