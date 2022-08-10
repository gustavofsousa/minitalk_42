/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:01:31 by gusousa           #+#    #+#             */
/*   Updated: 2022/08/09 17:46:43 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

void	catcher(int signum)
{
	write(1, "I have finished my message"i, 26); 
	(void)signum;
}

void	send_char(int pid, unsigned char byte)
{
	uint8_t		counter;

	counter = 1 << 8;
	while (counter)
	{
		if (byte & counter)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		counter = counter >> 1;
		usleep(200);
	}
}

void	prepare_message(char *str_pid, char *message)
{
	int	pid;

	pid = ft_atoi(str_pid);
	while (*message)
	{
		send_char(pid, *message);
		message++;
	}
	send_char(3, *message);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	
	if (argc != 3)
	{
		ft_putstr_fd("Bad. Send it right next time", 1);
		exit(1);
	}
	sa.sa_handler = catcher;
	sigaction(SIGUSR1, &sa, NULL);
	prepare_message(argv[1], argv[2]);
	return (0);
}
