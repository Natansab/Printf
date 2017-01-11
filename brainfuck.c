#include <stdio.h>
#include <string.h>

void ft_wtf(char **str)
{
  int i;

  i = 0;
  while (str[i])
  {
    printf("i is %i and *str[i] is %c\n", i, str[0][i]);
    i++;
  }
}

int main(void)
{
  int i;
  char *str;

  str = strdup("hello");
  i = 0;
  while (str[i])
  {
    printf("i is %i and str[i] is %c\n", i, str[i]);
    i++;
  }

  ft_wtf(&str);
  return (0);
}
