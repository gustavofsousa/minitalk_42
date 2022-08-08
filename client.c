/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:01:31 by gusousa           #+#    #+#             */
/*   Updated: 2022/08/08 17:56:20 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

int	*convert_int_binary(int num)
{
	static int	bytes[8];
	int	i;

	i = -1;
	while (++i < 8)
	{
		bytes[7 - i] = num % 2;
		num /= 2;
	}
	return (bytes);
}

void	send_char(int *byte, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (byte[i] == 1)
			kill(pid, SIGUSR1);
		else if (byte[i] == 0)
			kill(pid, SIGUSR2);
		//pause();
		usleep(250);
	}
}

int	main(int argc, char **argv)
{
	int	*byte;
	static int	c;
	int			pid_process;
	
	if (argc != 3)
		printf("Bad. Send it right next time");
	pid_process = ft_atoi(argv[1]);
	c = 0;
	while (argv[2][c])
	{
		byte = convert_int_binary(argv[2][c]);
		c++;
		send_char(byte, pid_process);
		pause();
	}
	printf("End game\n");
}


