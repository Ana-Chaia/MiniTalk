/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:30:39 by anacaro5          #+#    #+#             */
/*   Updated: 2024/04/04 15:23:20 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bits_chr = 0;

int	main(void)
{
	struct sigaction	create;

	create.sa_sigaction = create_chr;
	create.sa_flags = SA_SIGINFO;
	ft_printf("Server's PID is: %i\n\n", getpid());
	sigaction(SIGUSR1, &create, NULL);
	sigaction(SIGUSR2, &create, NULL);
	while (42)
		pause();

}

void	create_chr(int signo, siginfo_t *siginfo, void *context)
{
	static unsigned char	c = 0;

	(void)context;
	g_bits_chr++;
	if (signo == SIGUSR2)
			c |= 1;
	if (g_bits_chr == 8)
	{
		write (1, &c, 1);
		g_bits_chr = 8;
		c = 0;
	}
	c <<= 1;
	kill(siginfo->si_pid, SIGUSR1);
}
