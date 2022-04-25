-----HEADER-----

#include "libft.h"

static int  wordscnt(char const *s, char c);
static char *stringmkr(char const *s, char c);

char  **ft_split(char const *s, char c)
{
  char  **dst;
  int   words;
  int   i;
  
  if (!s)
    return (0);
  i = 0;
  words = wordscnt(s, c);
  dst = (char **)malloc(sizeof(char *) * (words + 1));
  if (!dst)
    return (0);
  while (*s)
  {
    while (*s && *s == c)
      s++;
    if (*s && *s != c)
    {
      dst[i] = stringmkr(s, c);
      i++;
      while (*s && *s != c)
         s++;
    }
  }
  dst[i] = '\0';
  return (dst);
}

static int  wordscnt(char const *s, char c)
{
  int   words;
  int   i;
  
  words = 0;
  i = 0;
  if (!s)
    return (0);
  if (s[i] != c)
  {
     i++;
     words++;
  }
  while (s[i] != '\0')
  {
    if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
      words++;
    i++;
  }
  return (words);
}

static char *stringmkr(char const *s, char c)
{
  char  *word;
  int   i;
  
  i = 0;
  while (s[i] && s[i] != c)
    i++;
  word = (char *)malloc(sizeof(char) * (i + 1));
  if (!word)
      return (0);
  i = 0;
  while (s[i] && s[i] != c)
  {
    word[i] = s[i];
    i++;
  }
  word[i] = '\0';
  return (word);
}
