/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base_c_piscine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:33:17 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/03 20:03:01 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ctype.h>

static int	ft_is_base_contains(char c, char *base)
{
	while (*base)
	{
		if (c == *base)
			return (1);
		base++;
	}
	return (0);
}

static int	ft_is_valid_base(char *base, int base_len)
{
	int		i;
	int		j;
	char	current;

	if (base_len < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		current = base[i];
		if (isspace(current) || current == '+' || current == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (current == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_calculate_nb(char *str, char *base, int base_len, int sign)
{
	long int	nb;
	int			i;

	nb = 0;
	while (*str && ft_is_base_contains(*str, base))
	{
		nb *= base_len;
		i = 0;
		while (base[i] && *str != base[i])
			i++;
		nb += i;
		str++;
	}
	nb *= sign;
	return (nb);
}

int			atoi_base_c_piscine(char *str, char *base)
{
	int			base_len;
	int			sign;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (!ft_is_valid_base(base, base_len))
		return (0);
	while (isspace(*str))
		str++;
	sign = 1;
	while (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign *= -1;
	return (ft_calculate_nb(str, base, base_len, sign));
}
