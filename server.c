/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:21:19 by admansar          #+#    #+#             */
/*   Updated: 2023/01/11 17:33:26 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
//#include <sys/siginfo.h>

int ft_pow(int c, unsigned int b)
{
  int a = 1;

  while (b)
  {
    a *= c;
    b--;
  }
  return (a);
}

char binary_to_decimal(char *s)
{
  int i = 0;
  int j = ft_strlen(s) - 1;
  int b = 0;

    while (i < (int)ft_strlen(s))
  {
    b += (s[i] - '0') * (ft_pow(2, j));
    j--;
    i++;
  }
  return (b);
}

void han(int sig_num, siginfo_t *a, void *nothing)
{	
	static char	str[9];
	static int 	i;
	char 		decimal;
	int 		sigpid;
	static int 	remember;

	(void)nothing;
	if (!remember)
		remember = a->si_pid;
	sigpid = a->si_pid;
	if (remember != sigpid && remember != 0)
	{
	//	ft_bzero(str, ft_strlen(str));
		i = 0;
		remember = sigpid;
	}
	if (sig_num == 30)
		str[i]= '0';
	
	if (sig_num == 31)
		str[i]= '1';
		//  ft_putstr_fd("1", 1);
	i++;
		if(i == 8)
		{
			str[8] = '\0';
			decimal = binary_to_decimal(str);
			write(1, &decimal, 1);
			i = 0;
		}
}

int main()
{
	struct sigaction action;
	int c = getpid();
	ft_putnbr_fd(c, 1);
	ft_putstr_fd("\n", 1);
	action.sa_sigaction = han;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		pause();
	};
}
