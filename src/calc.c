/*
** calc.c for 107transfer in /home/VEYSSI_B/rendu/Maths/107transfer
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Feb 29 16:09:40 2016 Baptiste veyssiere
** Last update Mon Feb 29 16:58:44 2016 Baptiste veyssiere
*/

#include "107transfer.h"

double		polynome(int nbr, int *list, double x)
{
  int		i;
  double	result;

  result = 0;
  i = -1;
  while (++i < nbr)
    result += (list[i] * pow(x, i));
  return (result);
}

double	polynomial_resolution(t_component comp, double x)
{
  double	numerator;
  double	denominator;
  double	result;

  numerator = 0;
  result = 0;
  denominator = 0;
  numerator = polynome(comp.nbr, comp.nbrs, x);
  denominator = polynome(comp.den, comp.dens, x);
  result = numerator / denominator;
  return (result);
}

void	calc_for_x(t_args *args, double x)
{
  double	result;
  int		i;

  result = 0;
  i = -1;
  while (++i < args->args)
    result += polynomial_resolution(args->comp[i], x);
  printf("%.3g->%.5f\n", x, result);
}

void	calc(t_args *args)
{
  double	x;

  x = 0;
  while (x <= 1.000)
    {
      calc_for_x(args, x);
      x += 0.001;
    }
}
