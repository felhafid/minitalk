/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:31:27 by felhafid          #+#    #+#             */
/*   Updated: 2024/06/05 18:12:03 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct mini{
	char	*s;
	char	c;
	int		len;
	int		i;
	int		id;
	int		bit;
	int		j;
}t_minitalk;

int		ft_atoi(char *s);
void	ft_putnbr(int nb);
void	writestr(char *s);

#endif