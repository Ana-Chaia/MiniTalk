/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:10:22 by anacaro5          #+#    #+#             */
/*   Updated: 2024/04/22 09:39:15 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libplus/libft.h"

//server.c
void	create_chr(int signo, siginfo_t *siginfo, void *context);

//client.c
int		ft_verify(int argc, char *pid);
void	signal_receipt(int signo);
void	send_bit(int server_pid, char c);

# define TRUE 1
# define FALSE 0

#endif
