-----HEADER-----

#include "libft.h"

static int  lenght(long nb);

char  *ft_itoa(int n)
{
  long  nb;
  char  *dst;
  int   i;
  
  nb = n;
  i = length(nb);
  dst = (char *)malloc(sizeof(char) * (lenght(nb) + 1));
  if (!dst)
    return (0);
  dst[i--] = '\0';
  if (nb == 0)
    dst[0] = '\0';
  if (nb < 0)
  {
    dst[0] = '-';
    nb = -nb;
  }
  while (nb > 0)
  {
    dst[i--] = '0' + (nb % 10);
    nb = nb / 10;
  }
  return (dst);
}

static int  lenght(long nb)
{
  int   len;
  if (nb == 0)
    len = 1;
  else if (nb < 0)
  {
    nb = -nb;
    len++;
  }
  while (nb > 0)
  {
    nb = nb / 10;
    len++;
  }
  return (len);
}
