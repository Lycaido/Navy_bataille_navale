/*
** map.c for navy in /home/Rev/PSU_2016_navy/player1
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Feb	1 17:14:37 2017 Roméo Nahon
** Last update	Wed Feb	1 17:14:37 2017 Roméo Nahon
*/

#include "include/my.h"

void	display_map(char **map)
{
  int	i;

  i = -1;
  while (map[++i])
    my_printf("%s\n", map[i]);
}

char	**create_map()
{
  char	**map;

  if ((map = malloc(sizeof(char*) * 11)) == NULL)
    return (NULL);
  map[0] = my_strdup(" |A B C D E F G H");
  map[1] = my_strdup("-+---------------");
  map[2] = my_strdup("1|. . . . . . . .");
  map[3] = my_strdup("2|. . . . . . . .");
  map[4] = my_strdup("3|. . . . . . . .");
  map[5] = my_strdup("4|. . . . . . . .");
  map[6] = my_strdup("5|. . . . . . . .");
  map[7] = my_strdup("6|. . . . . . . .");
  map[8] = my_strdup("7|. . . . . . . .");
  map[9] = my_strdup("8|. . . . . . . .");
  map[10] = NULL;

  return (map);
}

void	display_all_map_p2(t_map* map)
{
  my_printf("\nmy positions:\n");
  display_map(map->map_p2);
  my_printf("\nenemy's positions:\n");
  display_map(map->map_enemy_p2);
}

void	display_all_map_p1(t_map* map)
{
  my_printf("\nmy positions:\n");
  display_map(map->map_p1);
  my_printf("\nenemy's positions:\n");
  display_map(map->map_enemy_p1);
}
