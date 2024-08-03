/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:44:21 by felhafid          #+#    #+#             */
/*   Updated: 2024/06/06 10:56:54 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	recieve_len(int signal, t_minitalk *p)
{
	if (signal == SIGUSR1)
		p->len = (p->len << 1) | 1;
	else if (signal == SIGUSR2)
		p->len = p->len << 1;
	return (p->len);
}

int	rinitialize(t_minitalk *p)
{
	if (p->i > 32)
	{
		free(p->s);
		p->s = NULL;
	}
	p->i = 0;
	p->len = 0;
	p->j = 0;
	p->bit = 0;
	return (1);
}

void	bits(int signal, t_minitalk *p)
{
	if (signal == SIGUSR1)
		p->c = p->c << 1 | 1;
	else if (signal == SIGUSR2)
		p->c = p->c << 1;
	(p->j)++;
	if (p->j > 7)
	{
		if (p->bit > p->len)
		{
			rinitialize(p);
			return ;
		}
		p->j = 0;
		p->s[p->bit] = p->c ;
		p->bit++;
	}
	if (p->bit == p->len)
	{
		p->s[p->bit] = '\0';
		writestr(p->s);
		kill(p->id, SIGUSR2);
		rinitialize(p);
	}
}

void	recieve_bit(int signal, siginfo_t *info, void *content)
{
	static t_minitalk	p;

	(void)content;
	if (p.i == 0)
		p.id = info->si_pid;
	if (info->si_pid != p.id)
	{
		rinitialize(&p);
		p.id = info->si_pid;
	}
	if (p.i < 32)
	{
		p.len = recieve_len(signal, &p);
		p.i++;
	}
	else
	{
		if (p.i++ == 32 && p.len >= 0)
		{
			p.s = (char *)malloc(p.len + 1);
			if (!p.s)
				exit(rinitialize(&p));
		}
		bits(signal, &p);
	}
}

int	main(int c, char **v)
{
	int					id;
	struct sigaction	p;

	(void)v;
	if (c == 1)
	{
		id = getpid();
		p.sa_flags = SA_RESTART;
		p.sa_sigaction = recieve_bit;
		sigaction(SIGUSR1, &p, NULL);
		sigaction(SIGUSR2, &p, NULL);
		ft_putnbr(id);
		write(1, "\n", 1);
		while (1)
			pause();
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
