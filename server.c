/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:03:01 by gusousa           #+#    #+#             */
/*   Updated: 2022/08/03 16:15:42 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <signal.h>
#include <stdio.h>

int	convert_byte_dec(int *byte)
{
	int	i;
	int	pot;
	int	deci;
	int	j;

	i = 8;
	deci = 0;
	while (--i >= 0)
	{
		j = i;
		pot = 1;
		while (7 - j != 0)
		{
			pot *= 2;
			j++;

		}
		deci += byte[i] * pot;
	}
	return (deci);
}


void	handle_sig1(int sig)
{
	if (sig == 1)
		byte[count] = 1;
	else if (sig == 0)
		byte[count] = 0;
}


int	main()
{
	char	letter[8];
	struct sigaction	sa;

	int	point[8] = {0,0,1,1,0,0,1,1};
	printf("%c", convert_byte_dec(point));


	/*
	while (42)
	{
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handle_sig;

		sigaction(SIGUSR1, &sa, NULL);

	}
	*/
}
