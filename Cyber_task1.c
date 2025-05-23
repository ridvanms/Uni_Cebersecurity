#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h> // Add this line

bool is_prime(int num)
{
  if (num < 2)
  {
    return false;
  }
  if (num == 2)
  {
    return true;
  }
  if (num % 2 == 0)
  {
    return false;
  }
  int end = (int)sqrt((double)num);
  for (int i = 3; i <= end; i += 2)
  {
    if (num % i == 0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  if (is_prime(num))
  {
    printf("%d is a prime number.\n", num);
  }
  else
  {
    printf("%d is not a prime number.\n", num);
  }
  return EXIT_SUCCESS;
}