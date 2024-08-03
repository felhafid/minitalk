/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:20:05 by felhafid          #+#    #+#             */
/*   Updated: 2024/06/04 14:10:28 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check(char *s, int *i)
{
	int	sign;

	sign = 1;
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\t'))
		(*i)++;
	while (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i + 1] == '-' || s[*i + 1] == '+')
			return (0);
		if (s[*i] == '-')
			sign = 0;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(char *s)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	sign = 1;
	nb = 0;
	sign = check(s, &i);
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			nb = nb * 10;
			nb = nb + (s[i] - 48);
		}
		else
			sign = 0;
		i++;
	}
	return (nb * sign);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	writestr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
