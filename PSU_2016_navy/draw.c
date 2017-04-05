/*
** draw.c for navy in /home/Rev/PSU_2016_navy/player1
**
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Feb	1 22:33:15 2017 Roméo Nahon
** Last update	Wed Feb	1 22:33:15 2017 Roméo Nahon
*/

#include "include/my.h"

void	draw_hori(t_value value, char **map_p)
{
  while (value.begin <= value.end)
    {
      map_p[value.orientation][value.begin] = value.name;
      value.begin += 2;
    }
}

void	draw_vertical(t_value value, char **map_p)
{
  while (value.begin <= value.end)
    {
      map_p[value.begin][value.orientation] = value.name;
      value.begin += 1;
    }
}

void	start_drawing(t_map *map, char **map_p, char **pos, t_value value)
{
  int	i;

  i = -1;
  while (++i < 4)
    {
      if (my_conv(pos[i][2]) != my_conv(pos[i][5]))
	{
	  value.begin = my_conv(pos[i][2]);
	  value.end = my_conv(pos[i][5]);
	  value.orientation = pos[i][3] - 47;
	  value.name = pos[i][0];
	  draw_hori(value, map_p);
	}
      else
	{
	  value.begin = pos[i][3] - 47;
	  value.end = pos[i][6] - 47;
	  value.orientation = my_conv(pos[i][2]);
	  value.name = pos[i][0];
	  draw_vertical(value, map_p);
	}
    }
}

int		boat_draw(t_map *map, char **map_p, char *pos_p)
{
  t_value	value;
  char		buffer[100];
  char		**pos;
  int		fd;

  fd = open(pos_p, O_RDONLY);
  if (fd == -1)
    return (84);
  read(fd, buffer, 100);
  if (map_analyze(buffer) == 84)
     return (84);
  pos = parse_in_tab(buffer, "\n");
  start_drawing(map, map_p, pos, value);
}
