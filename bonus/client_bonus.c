/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:30:27 by felhafid          #+#    #+#             */
/*   Updated: 2024/06/04 12:46:45 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	writemsg(int signal)
{
	if (signal == SIGUSR2)
	{
		write(1, "SEND SUCCESSFULLY\n", 18);
	}
	exit (0);
}

void	sendlen(int len, int id)
{
	int	i;
	int	b;

	i = 32;
	b = len;
	while (--i >= 0)
	{
		len = b;
		len = (len >> i) & 1;
		if (len == 0)
			kill(id, SIGUSR2);
		else if (len == 1)
			kill(id, SIGUSR1);
		usleep(200);
	}
}

void	sendbits(char *s, int id, int len)
{
	int		i;
	int		y;
	int		bit;

	i = 8;
	y = 0;
	while (--i >= 0)
	{
		bit = s[y] >> i & 1; 
		if (bit == 0)
			kill(id, SIGUSR2);
		else if (bit == 1)
			kill(id, SIGUSR1);
		usleep(150);
		if (i == 0)
		{
			i = 8;
			y++;
		}
		if (y == len)
			return ;
	}
}

int	main(int c, char **v)
{
	int	id;
	int	len;

	if (c == 3 && ft_atoi(v[1]) > 0)
	{
		id = ft_atoi(v[1]);
		len = ft_strlen(v[2]);
		signal(SIGUSR2, writemsg);
		sendlen(len, id);
		sendbits(v[2], id, len);
		while (1)
			pause();
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
