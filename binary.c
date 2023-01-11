/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:39:48 by admansar          #+#    #+#             */
/*   Updated: 2023/01/11 15:59:14 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void to_binary(char a, int pid)
{

    int 	i = 7;
	char		b;


    while (i != -1)
    {
        b = '0' + (a >> i & 1); 
  		if (b == '0')
		  {
		 	kill(pid , SIGUSR1);
      		write (1, &b, 1);
		  }
		if (b == '1')
		{
			kill(pid , SIGUSR2);
			write (1, &b, 1);
		}
		usleep(100);
		i--;
    }
	write (1, " ", 1);
}
