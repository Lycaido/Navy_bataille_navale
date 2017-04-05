/*
** permission.c for navy in /home/Rev/PSU_2016_navy/player1
**
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Tue Jan	31 12:16:44 2017 Roméo Nahon
** Last update	Tue Jan	31 12:16:44 2017 Roméo Nahon
*/

#include "include/my.h"

extern int g_catch_signal;

int	check_sending(struct  sigaction receive_p, pid_t pid, int SIGUSR)
{
  int	i;
  char	*check;

  i = 0;
  while (i != 42)
    {
      if (i == 0)
	{
	  i += 1;
	  if ((check = malloc(sizeof(char) * 4)) == NULL) return (84);
	}
      check = check_sending_next(check, &i, receive_p);
      if (check[2] == '1' && check[3] == '1' && check[4] == '1' &&
	  check[5] == '0')
	{
	  i = 42;
	  kill(pid, SIGUSR);
	}
    }
  free(check);
}

char	*check_sending_next(char *check, int *i, struct  sigaction receive_p)
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

void	get_permission_sending(pid_t pid)
{
  kill(pid, SIGUSR1);
  usleep(5000);
  kill(pid, SIGUSR1);
  usleep(5000);
  kill(pid, SIGUSR1);
  usleep(5000);
  kill(pid, SIGUSR2);
  usleep(5000);
}
