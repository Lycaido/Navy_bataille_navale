/*
** player2.c for navy in /home/Rev/PSU_2016_navy
**
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Thu Feb	2 16:17:02 2017 Roméo Nahon
** Last update	Thu Feb	2 16:17:02 2017 Roméo Nahon
*/

#include "include/my.h"

int	receive_all_p2(struct  sigaction receive_p, pid_t pid_p1, t_map *map)
{
  char	*attack_enemy;

  check_sending(receive_p, pid_p1, SIGUSR2);
  usleep(14000);
  attack_enemy = receive_info_p(receive_p, 2);
  if (check_player(attack_enemy, map->map_p2) == 1)
  {
    signal_hit(pid_p1, SIGUSR2);
    map->nb_boat_p2 -= 1;
    my_printf("\n%s: hit\n", attack_enemy);
    if (map->nb_boat_p2 == 0)
    {
      display_all_map_p2(map);
      return (1);
    }
  }
  else
  {
    signal_missed(pid_p1, SIGUSR2);
    my_printf("\n%s: missed\n", attack_enemy);
  }
  usleep(14000);
}

int	sending_all_p2(t_map * map, char *msg_attack, pid_t pid_p1, RECEIVE)
{
  get_permission_sending(pid_p1);
  send_info_p1(msg_attack, pid_p1);
  if (check_touch_or_not(receive_p, pid_p1) == 1)
    {
      B_E_2 = check_enemy_map(msg_attack, map->map_enemy_p2, 1, B_E_2);
      my_printf("\n%s: hit\n", msg_attack);
      display_all_map_p2(map);
      if (map->nb_boat_enemy_p2 == 0)
	{
	  my_printf("\nI won\n");
	  return (0);
	}
    }
  else
    {
      check_enemy_map(msg_attack, map->map_enemy_p2, 0, B_E_2);
      my_printf("\n%s: missed\n", msg_attack);
      display_all_map_p2(map);
    }
  usleep(14000);
  my_printf("\nwaiting for enemy's attack...\n");
}

char	*get_msg_p2(t_map* map, char *msg_attack)
{
  my_printf("\nattack: ");
  msg_attack = get_next_line(0);
  msg_attack = check_invert_coord(msg_attack);
  while (check_good_coord(msg_attack) == -1)
    {
      msg_attack = get_next_line(0);
      msg_attack = check_invert_coord(msg_attack);
    }
  return (msg_attack);
}

void	first_display_p2(struct  sigaction first, t_map *map, pid_t pid_p1)
{
  sigaction(SIGUSR1, &first, NULL);
  kill(pid_p1, SIGUSR2);
  usleep(100);
  display_all_map_p2(map);
  my_printf("\nwaiting for enemy's attack...\n");
}
