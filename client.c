/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:01:31 by gusousa           #+#    #+#             */
/*   Updated: 2022/08/03 16:15:42 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>

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



int	main(int argc, char **argv)
{
	int	i = -1;
	int	*byte;

	byte = convert_int_binary('a');
	while (i < 8)
	{
		if (byte[i] == 1)
			kill(*argv, SIGUSR1);
		else if (byte[i] == 0)
			kill(*argv, SIGUSR2);
	}
	
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &handle_sig;
	sigaction(SIGUSR1, &sa, NULL);


	while (++i < 8)
		printf("%d", byte[i]);

	/*
	if (argc != 3 || !ft_str_is_numeric(argv[1]))
	{
		ft_printf("Bad. Send it right next time");
		break	;
	}
	*/
	//sigaction(SIGUSR1, handle_sig1);
	//sigaction(SIGUSR2, handle_sig2);
	
}


