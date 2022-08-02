/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:01:31 by gusousa           #+#    #+#             */
/*   Updated: 2022/08/02 15:22:56 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_str_is_numeric(argv[1]))
	{
		ft_printf("Bad. Send it right next time");
		break	;
	}
	sigaction(SIGUSR1, handle_sig1);
	sigaction(SIGUSR2, handle_sig2);
	
}
