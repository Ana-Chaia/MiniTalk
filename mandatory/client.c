/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:19:12 by anacaro5          #+#    #+#             */
/*   Updated: 2024/04/04 15:12:13 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_handshake = 0;

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*str;
	struct sigaction	sighandshake;

	if (ft_verify(argc, argv[1]))
		return (1);
	server_pid = ft_atoi (argv[1]);
	str = argv[2];
	sighandshake.sa_handler = signal_receipt;
	sighandshake.sa_flags = 0;
	sigaction(SIGUSR1, &sighandshake, NULL);
	while (*str != '\0')
		send_bit(server_pid, *(str)++);
}

void	signal_receipt(int signo)
{
	if (signo == SIGUSR1)
		g_handshake = 1;
}

void	send_bit(int server_pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_handshake = 0;
		if (((c >> bit) & 1) == 0)
			kill(server_pid, SIGUSR1);
		else if (((c >> bit) & 1) == 1)
			kill(server_pid, SIGUSR2);
		bit--;
		while (!g_handshake)
			;
	}
}

int	ft_verify(int argc, char *pid)
{
	int	i;

	i = 0;
	if (argc != 3)
		return (ft_printf("Wrong number of arguments.\n"));
	while (pid[i] != '\0')
	{
		if (!ft_isdigit(pid[i]))
			return (ft_printf("PID Error.\n"));
		i++;
	}
	return (0);
}
