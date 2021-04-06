#include "../inc/ft_printf.h"

t_flag	*ft_treat_flag(char c, t_flag *flags)
{
	if (c == '0')
		flags->zero = 1;
	if (c == '-')
		flags->minus = 1;
	if (c == '*')
		flags->star_f = 1;
	return (flags);
}

char	*ft_treat_zero(int size)
{
	char	*zero;

	zero = ft_calloc(sizeof(char), size + 1);
	if (!zero || !size)
		return (NULL);
	ft_memset(zero, '0', size);
	zero[size] = '\0';
	return (zero);
}

void	ft_treat_star(va_list args, t_flag *flags)
{
	if (flags->star_f == 1)
	{
		flags->field = va_arg(args, int);
		if (flags->field < 0)
		{
			flags->minus = 1;
			flags->field *= -1;
		}
	}
	if (flags->star_p == 1)
	{
		flags->prec = va_arg(args, int);
		if (flags->prec < 0)
		{
			flags->prec = 0;
			flags->dot = 0;
		}
	}
}

t_flag	*ft_treat_minfield(const char *str, int size, t_flag *flags)
{
	char	*field;

	field = ft_calloc(size + 1, sizeof(*field));
	if (!field)
		return (NULL);
	field = ft_strncpy(field, str, size);
	field[size] = '\0';
	flags->field = ft_atoi(field);
	free (field);
	return (flags);
}

t_flag	*ft_treat_prec(const char *str, int size, t_flag *flags)
{
	char	*precision;

	precision = ft_calloc(size + 1, sizeof(*precision));
	if (!precision)
		return (NULL);
	precision = ft_strncpy(precision, str, size);
	precision[size] = '\0';
	flags->prec = ft_atoi(precision);
	free (precision);
	return (flags);
}
