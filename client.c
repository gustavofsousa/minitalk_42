/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:01:31 by gusousa           #+#    #+#             */
/*   Updated: 2022/08/08 15:56:57 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

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

void	send_char(int *byte)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (byte[i] == 1)
			kill(argv[1], SIGUSR1);
		else if (byte[i] == 0)
			kill(argv[1], SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	int	i = -1;
	int	*byte;
	static int	c;
	
	c = 0;
	while (argv[2][c])
	{
		byte = convert_int_binary(argv[2][c]);
		c++;
		send_char(byte);
		pause();
	}

	/*
	if (argc != 3 || !ft_str_is_numeric(argv[1]))
	{
		ft_printf("Bad. Send it right next time");
		break	;
	}
	*/
	
}


