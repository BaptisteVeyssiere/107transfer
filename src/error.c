/*
** error.c for 107 in /home/scutar_n/rendu/maths/107transfer
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon Feb 29 18:35:31 2016 nathan scutari
** Last update Mon Feb 29 18:38:56 2016 nathan scutari
*/

int	my_strlen(char *str)
{
  int	x;

  x = -1;
  while (str[++x]);
  return (x);
}

int	my_perror(char *str, int output)
{
  write(2, str, my_strlen(str));
  return (output);
}
