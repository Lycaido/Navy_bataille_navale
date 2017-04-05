/*
** mapanalyser.c for navy in /home/Rev/PSU_2016_navy
**
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
**
** Started on Thu Feb 2 11:19:03 2017 Roméo Nahon
** Last update Sun Feb 19 19:37:11 2017 Roméo Nahon
*/

#include "include/my.h"

int	check_lenght(char **tab)
{
  int	i;

  i = -1;
  while (++i < 4)
    {
      if ((((tab[i][5] - tab[i][2]) + (tab[i][6] - tab[i][3])) + 1)
	  != (tab[i][0] - 48))
        return (84);
    }
  return (0);
}

int	first_analyse(char **tab)
{
  int	i;

  if (tab[0][0] != '2' || tab[1][0] != '3' || tab[2][0] != '4' ||
    tab[3][0] != '5')
      return (84);
  i = -1;
  while (++i < 4)
    if (tab[i][2] < 'A' || tab[i][2] > 'H')
      return (84);
  i = -1;
  while (++i < 4)
    if (tab[i][5] < 'A' || tab[i][5] > 'H')
      return (84);
  i = -1;
  while (++i < 4)
    if (tab[i][3] < '1' || tab[i][3] > '8')
      return (84);
  i = -1;
  while (++i < 4)
    if (tab[i][6] < '1' || tab[i][6] > '8')
      return (84);
  if ((check_lenght(tab)) == 84)
    return (84);
  return (0);
}

int	second_analyse(char **tab)
{
  int	i;

  i = -1;
  while (++i < 4)
    if (tab[i][1] != ':' || tab[i][4] != ':')
      return (84);
  i = -1;
  while (++i < 4)
    if (tab[i][2] == tab[i][5] && tab[i][3] == tab[i][6])
      return (84);
  return (0);
}

int	map_analyze(char *str)
{
  char	**tab;

  if (my_strlen(str) < 31)
    return (84);
  tab = my_str_to_wordtabmod(str, '\n');
  if (first_analyse(tab) == 84)
    return (84);
  if (second_analyse(tab) == 84)
    return (84);
  return (3);
}
