/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:47:41 by qmoreau           #+#    #+#             */
/*   Updated: 2022/06/22 17:34:27 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "Libft/libft.h"

typedef struct s_struct
{
	int		size;
	char	*str;
	int		rec;
	pid_t	pid;
}	t_struct;

static t_struct	g_gv;

void	size(int in)
{
	static int		i = 31;

	if (in == 1)
		g_gv.size |= 1 << i;
	i--;
	if (g_gv.rec == 32)
		i = 31;
}

void	handle(int code, siginfo_t *info, void *context)
{
	g_gv.pid = info->si_pid;
	if (g_gv.rec < 32)
	{
		if (code == SIGUSR1)
			size(1);
		else
			size(0);
	}
	if (g_gv.rec >= 32)
	{
		if (code == SIGUSR1)
			g_gv.str[(g_gv.rec - 32) / 8] |= 1 << (7 - (g_gv.rec % 8));
	}
	g_gv.rec++;
}

int	check(int *temp)
{	
	if (*temp != g_gv.rec)
	{
		*temp = g_gv.rec;
	}
	if (g_gv.rec == 32)
	{
		g_gv.str = ft_calloc(g_gv.size + 1, 1);
		if (!g_gv.str)
			return (0);
	}
	if (g_gv.rec >= g_gv.size * 8 + 32 && g_gv.size != 0 || g_gv.size < 0)
	{
		ft_printf("%s\n", g_gv.str);
		g_gv.size = 0;
		g_gv.rec = 0;
		free(g_gv.str);
		g_gv.str = NULL;
		kill(g_gv.pid, SIGUSR2);
		*temp = 0;
	}
	usleep(500);
	kill(g_gv.pid, SIGUSR1);
	return (1);
}

int	main(void)
{
	int					temp;
	pid_t				pid;
	struct sigaction	sa;

	temp = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
	{
		pause();
		if (!check(&temp))
			return (0);
	}
}
