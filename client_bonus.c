/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:01:31 by gusousa           #+#    #+#             */
/*   Updated: 2022/08/11 14:17:14 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

void	catcher(int signum)
{
	write(1, "I have finished my message!\n", 28);
	(void)signum;
}

void	send_char(int pid, unsigned char c)
{
	int	counter;

	counter = 8;
	while (counter--)
	{
		if (c >> counter & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(250);
	}
}

void	prepare_message(char *str_pid, char *message)
{
	int	pid;

	pid = ft_atoi(str_pid);
	while (*message)
		send_char(pid, *message++);
	send_char(pid, 0);
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
