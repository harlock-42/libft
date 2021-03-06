/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:25:50 by tallaire          #+#    #+#             */
/*   Updated: 2019/12/09 14:20:54 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

static	long	long	check_ovf(int ovf, long long nbr, int sign)
{
	if (ovf == 1)
		return (nbr * sign);
	else
		return ((long long)ovf);
}

long	long	ft_atoll(const char *str)
{
	long long	nbr;
	int			sign;
	int			ovf;

	nbr = 0;
	sign = 1;
	ovf = 1;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nbr = (nbr * 10) + *str++ - '0';
		if (nbr < 0 && sign == 1)
			ovf = -1;
		else if (nbr < 0 && sign == -1)
			ovf = 0;
	}
	return (check_ovf(ovf, nbr, sign));
}
