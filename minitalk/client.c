/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:47:50 by qmoreau           #+#    #+#             */
/*   Updated: 2022/05/06 13:22:06 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "Libft/libft.h"

void	handle(int code, siginfo_t *info, void *context)
{
	if (code == SIGUSR2)
		ft_printf("Message bien transmis\n");
}

void	siz(int pid, size_t size)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	j = 31;
	while (j >= 0)
	{
		if (size & (1 << j))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		j--;
		t = usleep(50000);
		if (t == 0)
			return ;
	}
}

void	bin(char *str, int pid)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (str[i])
	{
		j = 7;
		while (j >= 0)
		{
			if (str[i] & (1 << j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			t = usleep(50000);
			if (t == 0)
				return ;
			j--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	size_t				size;
	int					pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Error");
		return (0);
	}
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(argv[1]);
	size = ft_strlen(argv[2]);
	siz(pid, size);
	bin(argv[2], pid);
	usleep(50);
}
