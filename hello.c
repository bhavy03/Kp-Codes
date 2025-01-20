#include <stdio.h>

int isPrime(int num)
{
    if (num < 2)
        return 0; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0; // Not a prime number
        }
    }
    return 1; // Prime number
}

int main()
{
    int array[25];
    int primeNumbers[25]; // To store prime numbers
    int count = 0;

    // Fill the array with values from 1 to 25
    for (int i = 0; i < 25; i++)
    {
        array[i] = i + 1;
    }

    // Find prime numbers in the array
    for (int i = 0; i < 25; i++)
    {
        if (isPrime(array[i]))
        {
            primeNumbers[count++] = array[i];
        }
    }

    // Print the prime numbers
    printf("Prime numbers in the array are: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", primeNumbers[i]);
    }
    printf("\n");

    return 0;
}
