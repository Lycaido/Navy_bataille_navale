/*
** player1.c for navy in /home/Rev/PSU_2016_navy
**
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
**
** Started on	Thu Feb	2 16:40:48 2017 Roméo Nahon
** Last update Sat Feb 11 16:42:59 2017 Roméo Nahon
*/

#include "include/my.h"

extern int	g_catch_signal;

int	receive_all_p1(RECEIVE, pid_t pid_p2, t_map* map)
{
  char	*attack_enemy;

  check_sending(receive_p, pid_p2, SIGUSR1);
  usleep(14000);
  attack_enemy = receive_info_p(receive_p, 1);
  if (check_player(attack_enemy, map->map_p1) == 1)
  {
    signal_hit(pid_p2, SIGUSR1);
    map->nb_boat_p1 -= 1;
    my_printf("\n%s: hit\n", attack_enemy);
    if (map->nb_boat_p1 == 0)
    {
      display_all_map_p1(map);
      my_printf("\nEnemy won\n");
      return (1);
    }
  }
  else
  {
    signal_missed(pid_p2, SIGUSR1);
    my_printf("\n%s: missed\n", attack_enemy);
  }
  return (2);
}

int	sending_all_p1(RECEIVE, pid_t pid_p2, char *msg_attack, t_map *map)
{
  get_permission_sending(pid_p2);
  if (g_catch_signal == 2)
  {
    send_info_p1(msg_attack, pid_p2);
    if (check_touch_or_not(receive_p, pid_p2) == 1)
    {
     B_E_1 = check_enemy_map(msg_attack, map->map_enemy_p1, 1, B_E_1);
     my_printf("\n%s: hit\n", msg_attack);
     if (map->nb_boat_enemy_p1 == 0)
     {
       display_all_map_p1(map);
       my_printf("\nI won\n");
       return (0);
     }
   }
   else
   {
     B_E_1 = check_enemy_map(msg_attack, map->map_enemy_p1, 0, B_E_1);
     my_printf("\n%s: missed\n", msg_attack);
   }
   usleep(15000);
   my_printf("\nwaiting for enemy's attack...\n");
 }
}

char	*get_msg_p1(t_map *map, char* msg_attack)
{
  display_all_map_p1(map);
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
