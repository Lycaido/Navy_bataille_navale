/*
** navy.c for navy in /home/Rev/PSU_2016_navy
**
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Jan	30 09:16:36 2017 Roméo Nahon
** Last update	Mon Jan	30 09:16:36 2017 Roméo Nahon
*/

#include "include/my.h"

int	g_catch_signal = 0;

int	player2_operation(RECEIVE, pid_t pid_p1, t_map *map)
{
  char	*msg_attack;

  if (g_catch_signal > 0)
    {
      if (g_catch_signal == 1)
	if (receive_all_p2(receive_p, pid_p1, map) == 1)
	  return (1);
      if (g_catch_signal == 2)
      {
        msg_attack = get_msg_p2(map, msg_attack);
        usleep(200000);
      }
      if (msg_attack != NULL && g_catch_signal == 2)
	if (sending_all_p2(map, msg_attack, pid_p1, receive_p) == 0)
    return (0);
    }
  return (2);
}

int	player1_operation(RECEIVE, int pid_p2, char *msg_attack, t_map *map)
{
  int	r;
  int	r_2;

  sigaction(SIGUSR2, &receive_p, NULL);
  if (g_catch_signal == 2)
    {
      r = receive_all_p1(receive_p, pid_p2, map);
      if (r == 1) return (1);
    }
  if (g_catch_signal != 3)
    {
      msg_attack = get_msg_p1(map, msg_attack);
      usleep(200000);
    }
  if (msg_attack != NULL && g_catch_signal != 3)
    {
      r_2 = sending_all_p1(receive_p, pid_p2, msg_attack, map);
      if (r_2 == 0) return (0);
    }
  return (2);
}

int	player2(pid_t pid_p1, t_map *map)
{
  pid_t			pid_p2;
  struct sigaction	first;
  struct sigaction	receive_p;
  int			i;
  int			r;

  pid_p2 = getpid();
  my_printf("my_pid: %d\n", pid_p2);
  first.sa_sigaction = &signal_first_p2;
  receive_p.sa_sigaction = &signal_usr_p;
  i = 0;
  while (42)
    {
      sigaction(SIGUSR1, &receive_p, NULL);
      if (i++ == 0)
	{
	  first_display_p2(first, map, pid_p1);
	}
      r = player2_operation(receive_p, pid_p1, map);
      if (r == 1)
	       return (1);
      else if (r == 0)
	       return (0);
      usleep(15000);
    }
}

int		player1(t_map *map)
{
  pid_t		pid_p1;
  t_p1_value	t_value;

  pid_p1 = getpid();
  my_printf("my_pid: %d\nwaiting for enemy connexion...\n", pid_p1);
  t_value.first.sa_sigaction = &signal_first_p1;
  t_value.receive_p.sa_sigaction = &signal_usr_p;
  t_value.first.sa_flags = SA_SIGINFO;
  if (g_catch_signal == 0) sigaction(SIGUSR2, &t_value.first, NULL);
  t_value.i = 0;
  while (42)
    {
      if (g_catch_signal > 0)
	{
	  if (t_value.i++ == 0)
	    t_value.pid_p2 = g_catch_signal;
	  t_value.r = player1_operation(REC, t_value.pid_p2, MSG, map);
	  if (t_value.r == 1)
	    return (1);
	  if (t_value.r == 0)
	    return (0);
	  usleep(15000);
	}
    }
}

int	main(int ac, char **av)
{
  t_map	*map;
  int   r;

  if ((map = malloc(sizeof(t_map))) == NULL)
    return (84);
  init(map);
  r = start_game(ac, map, av);
  if (r == 0)
    return (0);
  else if (r == 1)
    return (1);
  else if (r == 84)
    return (84);
}
