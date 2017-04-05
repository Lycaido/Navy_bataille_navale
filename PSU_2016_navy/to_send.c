/*
** to_send.c for navy in /home/Rev/PSU_2016_navy/player1
**
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Jan	30 15:02:35 2017 Roméo Nahon
** Last update	Mon Jan	30 15:02:35 2017 Roméo Nahon
*/

#include "include/my.h"

extern int	g_catch_signal;

int	send_info_p1(char *msg, pid_t pid_p2)
{
  char	*nb_to_send;
  int	i;
  int	j;

  if (my_strlen(msg) >= 3 || my_strlen(msg) < 2)
    {
      write(1, "wrong position\n", 15);
      return (84);
    }
  i = -1;
  while (msg[++i])
    {
      j = -1;
      nb_to_send = binary(msg[i]);
      while (nb_to_send[++j])
	{
	  if (nb_to_send[j] == '1')
	    kill(pid_p2, SIGUSR1);
	  else if (nb_to_send[j] == '0')
	    kill(pid_p2, SIGUSR2);
	  usleep(10500);
	}
      usleep(10000);
    }
}

char	*receive_info_p(struct sigaction receive_p, int value)
{
  char	*msg;
  int	nb_msg;
  int	char_msg;
  int	j;
  int	i;

  j = 0;
  while (j < 2)
    {
      i = -1;
      if ((msg = malloc(sizeof(char) * 8)) == NULL)
	return (NULL);
      msg = my_memset(msg, '\0', 8);
      msg = receive_info_p_next(receive_p, &i, msg);
      usleep(10000);
      if (i == 8) j += 1;
      if (j == 1) char_msg = decimal(msg);
      if (j == 2) nb_msg = decimal(msg);
      free(msg);
    }
  g_catch_signal = value;
  if ((msg = malloc(sizeof(char) * 2)) == NULL) return (NULL);
  msg = my_strcat(my_ctoa(char_msg), my_ctoa(nb_msg));
  return (msg);
}

char	*receive_info_p_next(struct sigaction receive_p, int *i, char *msg)
{
  while (++(*i) < 8)
    {
      sigaction(SIGUSR1, &receive_p, NULL);
      if (g_catch_signal == 1)
	{
	  msg[*i] = '1';
	  g_catch_signal = 3;
	}
      sigaction(SIGUSR2, &receive_p, NULL);
      if (g_catch_signal == 2)
	{
	  msg[*i] = '0';
	  g_catch_signal = 3;
	}
      usleep(20000);
    }
  return (msg);
}
