/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:37:42 by admansar          #+#    #+#             */
/*   Updated: 2023/01/09 20:11:53 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac, char **av)
{
	int i = 0;
	if (ac == 2)
		exit(0);
	while (av[2][i])
	{
		to_binary(av[2][i], atoi(av[1]));
		i++;
	}
}
