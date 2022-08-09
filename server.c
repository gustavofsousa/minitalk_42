/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:03:01 by gusousa           #+#    #+#             */
/*   Updated: 2022/08/09 16:12:31 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int	power(int base, int expo)
{
	int	pot;

	pot = 1;
	while (expo-- != 0)
		pot *= base;
	return (pot);
}

int	convert_byte_dec(int *byte)
{
	int	i;
	int	deci;

	i = 8;
	deci = 0;
	while (--i >= 0)
		deci += byte[i] * power(2, 7 - i);
	return (deci);
}

void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static int	count;
	static int	byte[8];
	int			deci;

	(void)(ucontext);
	if (sig == SIGUSR1)
		byte[count++] = 1;
	else if (sig == SIGUSR2)
		byte[count++] = 0;
	if (count == 8)
	{
		count = 0;
		deci = convert_byte_dec(byte);	
		write(1, &deci, 1);
	}
	kill(info->si_pid, SIGUSR1);
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
