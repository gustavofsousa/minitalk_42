/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:03:01 by gusousa           #+#    #+#             */
/*   Updated: 2022/08/02 15:09:15 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <signal.h>

void	handle_sig1()
{
	if (true)
		letter[count] = 1;
	else
		letter[count] = 0;

}

void	handle_sig2()
{

	if (true)
		letter[count] = 1;
	else
		letter[count] = 0;
}



int	main()
{
	char	letter[8];

	while (42)
	{
		sigaction(SIGUSR1, handle_SIG1())
		sigaction(SIGUSR2, handle_SIG2())



	}
}
