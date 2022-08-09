/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:01:31 by gusousa           #+#    #+#             */
/*   Updated: 2022/08/09 16:35:33 by gusousa          ###   ########.fr       */
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
		pause();
		//usleep(250);
	}
}

void	catcher(int signum)
{
	//printf("Catch + 1\n");
	(void)signum;
}

int	main(int argc, char **argv)
{
	int	*byte;
	int	c;
	int			pid_process;
	struct sigaction	sa;
	
	if (argc != 3)
	{
		ft_putstr_fd("Bad. Send it right next time", 1);
		exit(1);
	}
	sa.sa_handler = catcher;
	sigaction(SIGUSR1, &sa, NULL);
	pid_process = ft_atoi(argv[1]);
	c = 0;
	while (argv[2][c])
	{
		byte = convert_int_binary(argv[2][c]);
		send_char(byte, pid_process);
		c++;
	}
	byte = convert_int_binary(3);
	send_char(byte, pid_process);
	ft_putstr_fd("End game\n", 1);
	return (0);
}
