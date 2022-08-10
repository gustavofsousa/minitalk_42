/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:03:01 by gusousa           #+#    #+#             */
/*   Updated: 2022/08/09 18:24:16 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static int	count;
	static int	c;	

	(void)(ucontext);
	if (sig == SIGUSR1)
	{
		c = c << 1;
		c = c | 1; 	
	}
	else if (sig == SIGUSR2)
		c = c << 1;	
	if (count == 8)
	{
		count = 0;
		write(1, &c, 1);
		kill(info->si_pid, SIGUSR1);
	}
	else
		kill(info->si_pid, SIGUSR2);
}

int	main()
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_sig;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("PID: %d\n", getpid());
	while (42)
		pause();
	return (0);
}
