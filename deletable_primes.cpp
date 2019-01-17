/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */
 #include "deletable_primes.h"
 #include <math.h>


 int remove_digit(int i, int num)
 {
   int left_site = 0 ;
   double right_site = 0;
   int total = 0;

   if (i == 0)
   {
     return num / 10;
   }

   left_site = num / pow(10 , i + 1);
   right_site = num % (int)pow(10 , i);
   total = left_site * pow(10 , i) + right_site;

   return total;
 }

 int get_ways(int num)
 {
   int new_num = num;
   int len = 0;

   for (int i = 0; i < get_length(new_num); i++)
   {
     if (get_length(new_num) == 1)
     {
       if (is_prime(new_num) == true)
       {
          len ++;
       }
       // else
       // {
       //   return 0;
       // }
     }
     if (get_length(new_num) != 1 && is_prime(remove_digit(i,new_num)) )
     {
       new_num = remove_digit(i,new_num);
       len = get_ways(new_num);
      }

     }
   return len;
 }

 int get_length(int num)
{
  int clone = num;
  int len = 0;
  if (num < 10)
  {
    return 1;
  }
  while (clone != 0)
  {
    clone = clone/10;
    len++;
  }
  return len;
}

bool is_prime(int num)
{
  int i = 2;
  int cloned_num = num;
  while (i <= sqrt(num))
  {
    if (cloned_num %(int)i == 0)
    {
      return false;
    }
    i++;
  }
  return true;
}
