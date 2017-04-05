/*
** my.h for bootstrap in /home/Rev/CSFML/bootstrap
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Thu Nov	10 10:15:08 2016 Roméo Nahon
** Last update	Thu Nov	10 10:15:08 2016 Roméo Nahon
*/

#ifndef MY_H
# define MY_H

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define RECEIVE struct sigaction receive_p
#define MSG t_value.msg_attack
#define REC t_value.receive_p
#define B_E_1 map->nb_boat_enemy_p1
#define B_E_2 map->nb_boat_enemy_p2

char	*my_printf(char *str, ...);
int	my_strlen(char *);
int	my_getnbr(char *str);
void	my_putchar(char);
char	*my_revstr(char *str);
char	*my_strcat(char *str, char *str2);
char	*my_itoa(int, char *);
char	*my_ctoa(char str);
char	*binary(int nb);
int	decimal(char *str);
int	my_power_it(int, int);
int	my_intlen(int);
char	*my_memset(char *str, char, int);
char	*get_next_line(int fd);
void	my_putstr(char *);
char	*my_strdup(char *src);
char	**parse_in_tab(char *str, char *to_parse);
char	**my_str_to_wordtabmod(char *str, char);
void  my_puterror(char *);

typedef struct	s_map
{
  char	**map_p1;
  char	**map_p2;
  char	**map_enemy_p1;
  char	**map_enemy_p2;
  char	*coord;
  int	nb_boat_p1;
  int	nb_boat_p2;
  int	nb_boat_enemy_p1;
  int	nb_boat_enemy_p2;
}	t_map;

typedef struct	s_value
{
  int	begin;
  int	end;
  int	orientation;
  char	name;
}	t_value;

typedef struct		s_p1_value
{
  int			pid_p2;
  struct sigaction	first;
  struct sigaction	receive_p;
  siginfo_t		*siginfo;
  char			*msg_attack;
  int			i;
  int			r;
}			t_p1_value;

int	player2_operation(RECEIVE, pid_t pid_p1, t_map *map);
int	player1_operation(RECEIVE, int pid_p2, char *, t_map *);
int	player1(t_map *map);
int	player2(pid_t pid_p1, t_map *map);
int	main(int ac, char **av);

void	init(t_map *map);
int	start_game(int ac, t_map *map, char **av);
int check_pid(char **av);

void	signal_first_p1(int signum, siginfo_t *info, void *ptr);
void	signal_first_p2();
void	signal_usr_p(int, siginfo_t *info, void *ptr);

int	send_info_p1(char *msg, pid_t pid_p1);
char	*receive_info_p(struct sigaction, int value);
char	*receive_info_p_next(struct sigaction, int *, char *);

int	check_sending(struct  sigaction receive_p, pid_t, int);
char	*check_sending_next(char *check, int *i, struct  sigaction);
void	get_permission_sending(pid_t pid);

int	check_touch_or_not(struct sigaction, pid_t);
char	*check_code(char *check, int *i, struct  sigaction receive_p);
void	signal_hit(pid_t pid, int);
void	signal_missed(pid_t pid, int);

void	display_map(char **map);
char	**create_map();
void  display_all_map_p1(t_map* map);
void  display_all_map_p2(t_map* map);

void	draw_hori(t_value value, char **map_p);
void	draw_vertical(t_value value, char **map_p);
void	start_drawing(t_map *map, char **, char **, t_value);
int	boat_draw(t_map *map, char **map_p, char *);

int	first_analyse(char **tab);
int	second_analyse(char **tab);
int	map_analyze(char *str);

int	check_player(char *str, char **);
int	check_enemy_map(char *str, char** map_enemy, int, int);
int	check_good_coord(char *str);
char	*check_invert_coord(char *str);
int	my_conv(char c);

int	receive_all_p2(struct  sigaction, pid_t, t_map *);
int	sending_all_p2(t_map * map, char *, pid_t, struct  sigaction);
char	*get_msg_p2(t_map* map, char *msg_attack);
void	first_display_p2(struct  sigaction first, t_map *map, pid_t);

int	receive_all_p1(struct  sigaction receive_p, pid_t pid_p2, t_map*);
int	sending_all_p1(struct  sigaction, pid_t, char *, t_map *);
char	*get_msg_p1(t_map *map, char* msg_attack);

#endif /* MY_H */