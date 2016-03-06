/*
** 107transfer.c for 107transfer in /home/VEYSSI_B/rendu/Maths/107transfer
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Feb 29 15:59:00 2016 Baptiste veyssiere
** Last update Mon Feb 29 18:50:39 2016 nathan scutari
*/

#include "107transfer.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int	check_arg(char *str, int x, int **nbrs)
{
  int	i;
  int	y;
  char	*strd;

  i = 0;
  y = -1;
  while (i < x)
    if (str[++y] == '*')
      ++i;
  i = y;
  while (str[++y] && str[y] != '*');
  strd = malloc(y - i);
  y = -1;
  while (str[++i] && str[i] != '*')
    strd[++y] = str[i];
  strd[++y] = 0;
  i = -1;
  if (strd[0] == '-')
    ++i;
  while (strd[++i])
    if (strd[i] < '0' || strd[i] > '9')
      return (-1);
  (*nbrs)[x] = atoi(strd);
  free(strd);
  return (0);
}

int	get_nbrs_in_arg(char *str, int *nbr, int **nbrs)
{
  int	x;

  x = -1;
  *nbr = 1;
  while (str[++x])
    if (str[x] == '*')
      (*nbr)++;
  x = -1;
  if ((*nbrs = malloc(sizeof(int) * (*nbr))) == NULL)
    return (-1);
  while (++x < *nbr)
    if (check_arg(str, x, nbrs) == -1)
      return (-1);
}

int	get_spec_comp(int num, int den, char **av, t_component *comp)
{
  if (get_nbrs_in_arg(av[num], &comp->nbr, &comp->nbrs) == -1)
    return (-1);
  else if (get_nbrs_in_arg(av[den], &comp->den, &comp->dens) == -1)
    return (-1);
  return (0);
}

t_args	*get_components(int ac, char **av)
{
  t_args	*arg;
  int		x;
  int		compo;

  x = 0;
  compo = -1;
  if ((arg = malloc(sizeof(t_args))) == NULL)
    return (NULL);
  arg->args = ac / 2;
  if ((arg->comp = malloc(sizeof(t_component) * (ac / 2))) == NULL)
    return (NULL);
  while (++x < ac)
    {
      if (get_spec_comp(x, x + 1, av, &arg->comp[++compo]) == -1)
	return (NULL);
      ++x;
    }
  return (arg);
}

int	main(int ac, char **av)
{
  t_args	*comp;

  comp = NULL;
  if (ac % 2 != 1 || ac < 2)
    return (my_perror("Invalid number of arguments\n", 84));
  if ((comp = get_components(ac, av)) == NULL)
    return (my_perror("Error while loading arguments\n", 84));
  calc(comp);
  return (0);
}
