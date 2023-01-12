/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:22:30 by admansar          #+#    #+#             */
/*   Updated: 2023/01/12 18:16:46 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	hani(int sig)
{
	(void)sig;
	ft_putstr_fd("\033[0;32mreceived with success\n", 1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_putstr_fd("\033[0;31myou should use 3 argument\n", 1);
		exit(0);
	}
	signal(SIGUSR1, hani);
	while (av[2][i])
	{
		to_binary(av[2][i], ft_atoi(av[1]));
		i++;
	}
	to_binary(0, ft_atoi(av[1]));
	return (0);
}
