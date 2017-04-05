/*
** signal.c for navy in /home/Rev/PSU_2016_navy/player1
**
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Jan	30 12:45:38 2017 Roméo Nahon
** Last update	Mon Jan	30 12:45:38 2017 Roméo Nahon
*/

#include "include/my.h"

extern int	g_catch_signal;

void	signal_first_p1(int signum, siginfo_t *info, void *ptr)
{
  static int	i = 0;

  if (i == 0)
    {
      i = 1;
      g_catch_signal = 1;
      my_printf("enemy connected\n");
      g_catch_signal = info->si_pid;
      kill(info->si_pid, SIGUSR1);
    }
}

void	signal_first_p2()
{
  static int	i = 0;

  if (i == 0)
    {
      i = 1;
      g_catch_signal = 1;
      my_printf("successfully connected\n\n");
    }
}

void	signal_usr_p(int signum, siginfo_t *info, void *ptr)
{
  if (signum == SIGUSR1)
    g_catch_signal = 1;
  else if (signum == SIGUSR2)
    g_catch_signal = 2;
}
