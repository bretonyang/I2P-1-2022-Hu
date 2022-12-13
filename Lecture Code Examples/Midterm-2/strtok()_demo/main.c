/**
 * The strtok(char *str, char *delimeters) function splits the
 * `str` string according to the `delimeters`, which is an array
 * of delimeter characters.
 *
 * This function will simply scan through `str` char array, and
 * look for any delimeter character, if it finds one, it'll
 * destructively replace that delimeter char in the original
 * `str` by the null character '\0'.
 *
 * It then returns the address of the starting char of the
 * current string token.
 */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="- This, a sample string.";
  int len = strlen(str);
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-"); // delimeters: ' ' & ',' & '.' & '-'
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }

  for (int i = 0; i < len; i++) {
    printf("%d ", str[i]);
  }
  putchar('\n');

  return 0;
}
