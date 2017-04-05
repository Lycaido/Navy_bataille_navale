/*
** check_code.c for navy in /home/Rev/PSU_2016_navy/player1
**
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Feb	1 14:09:58 2017 Roméo Nahon
** Last update	Wed Feb	1 14:09:58 2017 Roméo Nahon
*/

#include "include/my.h"

extern int	g_catch_signal;

int	check_touch_or_not(struct sigaction receive_p, pid_t pid)
{
  char	*check;
  int	i;

  i = 0;
  while (42)
    {
      if (i == 0)
	{
	  i = 1;
	  if ((check = malloc(sizeof(char) * 5)) == NULL) return (84);
	}
      check = check_code(check, &i, receive_p);
      if (check[2] == '1' && check[3] == '1' && check[4] == '1' &&
	  check[5] == '1')
	{
	  free(check);
	  return (1);
	}
      else if (check[2] == '0' && check[3] == '0' && check[4] == '0' &&
	       check[5] == '0')
	{
	  free(check);
	  return (0);
	}
    }
}

char	*check_code(char *check, int *i, struct  sigaction receive_p)
{
  sigaction(SIGUSR1, &receive_p, NULL);
  if (g_catch_signal == 1)
    {
      check[*i] = '1';
      *i += 1;
      g_catch_signal = 3;
    }
  sigaction(SIGUSR2, &receive_p, NULL);
  if (g_catch_signal == 2)
    {
      check[*i] = '0';
      *i += 1;
      g_catch_signal = 3;
    }
  return (check);
}

void	signal_hit(pid_t pid, int siguser)
{
  kill(pid, SIGUSR1);
  usleep(10000);
  kill(pid, SIGUSR1);
  usleep(10000);
  kill(pid, SIGUSR1);
  usleep(10000);
  kill(pid, SIGUSR1);
  usleep(10000);
  kill(pid, siguser);
}

void	signal_missed(pid_t pid, int siguser)
{
  kill(pid, SIGUSR2);
  usleep(5000);
  kill(pid, SIGUSR2);
  usleep(5000);
  kill(pid, SIGUSR2);
  usleep(5000);
  kill(pid, SIGUSR2);
  usleep(5000);
  kill(pid, siguser);
}
