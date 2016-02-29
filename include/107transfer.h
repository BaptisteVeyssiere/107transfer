/*
** 107transfer.h for 107transfer in /home/VEYSSI_B/rendu/Maths/107transfer
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Feb 29 15:57:12 2016 Baptiste veyssiere
** Last update Mon Feb 29 16:19:12 2016 Baptiste veyssiere
*/

#ifndef TRANSFER_H_
# define TRANSFER_H_

# include <math.h>
# include <stdio.h>

typedef struct
{
  int	nbr;
  int	den;
  int	*nbrs;
  int	*dens;
}		t_component;

typedef struct
{
  int	args;
  t_component	*comp;
}		t_args;

#endif /* !TRANSFER_H_ */
