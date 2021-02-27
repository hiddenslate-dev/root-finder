#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
char** rootFinder();

char** rootFinder(int a, int b, int c)
{
  int i;
  int d;
  char *root1[30];
  char *root2[30];
  char **roots_str; 
  roots_str = malloc(3 * sizeof(char*));
  
  for (int i = 0; i < 3; i++)
    roots_str[i] = malloc((30+1) * sizeof(char));

  d = b*b - 4*a*c;

  if (d < 0) 
  { // complex roots, i is for iota (√-1, square root of -1)
    snprintf(root1, 128, "%.2lf + i%.2lf", -b/(double)(2*a), sqrt(-d)/(2*a));
    snprintf(root2, 128, "%.2lf - i%.2lf", -b/(double)(2*a), sqrt(-d)/(2*a));
    strcpy(roots_str[0], root1);
    strcpy(roots_str[1], root2 );
  }
  else { // real roots
    snprintf(root1, 128, "%.2lf", (-b + sqrt(d))/(2*a));
    snprintf(root2, 128, "%.2lf", (-b - sqrt(d))/(2*a));
    strcpy(roots_str[0], root1 );
    strcpy(roots_str[1], root2 );
  }
  return roots_str;
}
int main(int argc, char *argv[])
{   
    int i;
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    char **roots_str;
    
    roots_str = rootFinder(a,b,c);
    
    for(i=0; i<2; i++)
    {
        printf("%s\n", roots_str[i]);
    }
    return 0; 
}
