/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:10:22 by anacaro5          #+#    #+#             */
/*   Updated: 2024/04/04 15:16:04 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libplus/libft.h"

void	create_chr(int signo, siginfo_t *siginfo, void *context);

void	signal_receipt(int signo);
void	send_bit(int server_pid, char c);
int		ft_verify(int argc, char *pid);

#endif