/*
 * Melendez_Prime.c
 *
 *      Author: Antonio Melendez
 *
 *      The purpose of this program is to compute and print the first 100 prime numbers
 */
#include <stdio.h>

int prime(int i)		// Function used to calculate Prime numbers
{
   int j;
						/*
						* Here we use a for loop to determine whether a number is a prime number
						* To do this we divide the current i value by every number starting from 2
						* Up until the number before i. If i is divisible by any of those numbers then
						* it is not a prime number. To determine this we use modulus, which gives
						* us the remainder. if remainder is 0 then we know that i is divisible by that
						* number.
						*/
	for ( j = 2 ; j <= i - 1 ; j++ )
	{
		if ( i%j == 0 )		// modulus to check remainder
			return 0;		// this will disallow the print function in main
	}

	if ( j == i )			// if j reaches i then it is a prime number
		return 1;			// This will allow the print function to work in main
return 0;					// Needed for our first loop through the function when i =1
}

int  main()
{
    int i,g;
    g = 1;
    printf("The following are the first 100 Prime numbers\n");
    for (i = 1; ; i++)		// 541 is the top of the values we need to get 100 prime numbers
    {
    	if(prime(i) == 1)			// Calls the function prime and sends the current i value
    	{
    		printf("%d\n", i);			// Prints only if the number in question is a prime number
    		g++;
    		if(g==100)
    		{
    			break;
    		}
    	}

    }
    return 0;
}
