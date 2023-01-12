/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:37:42 by admansar          #+#    #+#             */
/*   Updated: 2023/01/12 13:20:02 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_putstr_fd("\033[0;31myou should use 3 argument\n", 1);
		exit(0);
	}
	while (av[2][i])
	{
		to_binary(av[2][i], ft_atoi(av[1]));
		i++;
	}
	return (0);
}
