/*
** init.c for navy in /home/Rev/PSU_2016_navy
**
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Thu Feb	2 17:45:53 2017 Roméo Nahon
** Last update	Thu Feb	2 17:45:53 2017 Roméo Nahon
*/

#include "include/my.h"

void	init(t_map *map)
{
  map->map_p1 = create_map();
  map->map_p2 = create_map();
  map->map_enemy_p1 = create_map();
  map->map_enemy_p2 = create_map();
  map->nb_boat_p1 = 14;
  map->nb_boat_p2 = 14;
  map->nb_boat_enemy_p1 = 14;
  map->nb_boat_enemy_p2 = 14;
}

int	start_game(int ac, t_map *map, char **av)
{
  int	r;

  if (ac == 2)
  {
    if ((boat_draw(map, map->map_p1, av[1])) == 84) return (84);
    r = player1(map);
    if (r == 1) return (1);
    else if (r == 0) return (0);
  }
  else if (ac == 3)
  {
    if ((boat_draw(map, map->map_p2, av[2])) == 84) return (84);
    if ((check_pid(av)) == 84)
      return (84);
    r = player2(my_getnbr(av[1]), map);
    if (r == 1) return (1);
    else if (r == 0) return (0);
  }
  else
  {
    my_printf("pour le joueur 1 './navy pos1'\nPour le joueur 2 './navy [pid joueur 1] pos2'\n");
    return (84);
  }
}

int	check_pid(char **av)
{
  int	i;

  i = - 1;
  while (av[1][++i] != '\0')
  {
    if (av[1][i] < '0' || av[1][i] > '9')
      return (84);
  }
  return (3);
}