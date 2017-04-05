/*
** mod_map.c for navy in /home/Rev/PSU_2016_navy/player1
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Feb	1 17:46:54 2017 Roméo Nahon
** Last update	Wed Feb	1 17:46:54 2017 Roméo Nahon
*/

#include "include/my.h"

int	check_player(char *str, char **map_p)
{
  if (map_p[str[1] - 47][my_conv(str[0])] == '.'
      || map_p[str[1] - 47][my_conv(str[0])] == 'o')
    {
      map_p[str[1] - 47][my_conv(str[0])] = 'o';
      return (0);
    }
  else if (map_p[str[1] - 47][my_conv(str[0])] == 'x')
      return (0);
    else
    {
        map_p[str[1] - 47][my_conv(str[0])] = 'x';
        return (1);
    }
}

int	check_enemy_map(char *str,
		    char** map_enemy,
		    int type,
		    int nb_boat_enemy)
{
  if (type == 1)
  {
    if (map_enemy[str[1] - 47][my_conv(str[0])] == '.'
      || map_enemy[str[1] - 47][my_conv(str[0])] == 'x')
    {
      nb_boat_enemy -= 1;
      map_enemy[str[1] - 47][my_conv(str[0])] = 'x';
    }
    else
      map_enemy[str[1] - 47][my_conv(str[0])] = 'o';
    return (nb_boat_enemy);
  }
  if (type == 0)
  {
    if (map_enemy[str[1] - 47][my_conv(str[0])] == '.'
      || map_enemy[str[1] - 47][my_conv(str[0])] == 'o')
      map_enemy[str[1] - 47][my_conv(str[0])] = 'o';
    else
      map_enemy[str[1] - 47][my_conv(str[0])] = 'x';
    return (nb_boat_enemy);
  }
}

int	check_good_coord(char *str)
{
  if (my_strlen(str) > 2)
  {
    write(1, "wrong position\n", 15);
    my_printf("attack: ");
    return (-1);
  }
  else if (str[0] < 'A' || str[0] > 'H')
  {
    write(1, "wrong position\n", 15);
    my_printf("attack: ");
    return (-1);
  }
  else if (str[1] < '1' || str[1] > '8')
  {
    write(1, "wrong position\n", 15);
    my_printf("attack: ");
    return (-1);
  }
  else
    return (0);
}

char	*check_invert_coord(char *str)
{
  char	temp;
  char	*newstr;

  if ((newstr = malloc(sizeof(char) * 3)) == NULL)
    return (NULL);
  newstr = my_memset(newstr, '\0', 3);
  if (str[0] >= '1' && str[0] <= '8' && str[1] >= 'A' && str[1] <= 'H')
  {
    temp = str[0];
    newstr[0] = str[1];
    newstr[1] = temp;
    free(str);
    return (newstr);
  }
  free(newstr);
  return (str);
}

int	my_conv(char c)
{
  if (c == 'A')
    return (2);
  else if (c == 'B')
    return (4);
  else if (c == 'C')
    return (6);
  else if (c == 'D')
    return (8);
  else if (c == 'E')
    return (10);
  else if (c == 'F')
    return (12);
  else if (c == 'G')
    return (14);
  else if (c == 'H')
    return (16);
}
