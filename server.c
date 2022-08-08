/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:03:01 by gusousa           #+#    #+#             */
/*   Updated: 2022/08/08 15:53:35 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/*
int	power(int base, int expo)
{

}
*/

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


void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static int	count;
	int			*byte;
	int			deci;

	if (sig == SIGUSR1)
		byte[count] = 1;
	else if (sig == SIGUSR2)
		byte[count] = 0;
	count++;
	if (count == 8)
	{
		count = 0;
		deci = convert_byte_dec(byte);	
		write(1, &deci, 1);
		kill(info->si_pid, SIGUSR1);
	}
}


int	main()
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_sig;
	sa.sa_flags = SA_SIGINFO;
	printf("PID: %d\n", getpid());
	while (42)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}




}
