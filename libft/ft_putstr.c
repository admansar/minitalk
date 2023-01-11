/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:42:22 by admansar          #+#    #+#             */
/*   Updated: 2022/10/27 16:31:34 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *a)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", a);
		return ;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		(*a)++;
	}
}
