// this is how to modify a string
// void removeWhitespaces(char *exp)
// {
// int i = 0, j = 0;
// while (exp[i] != '\0')
// {
// if (exp[i] != ' ' && exp[i] != '\t' && exp[i] != '\n')
// {
// exp[j] = exp[i];
// j++;
// }
// i++;
// }
// exp[j] = '\0';
// }

// this is how to convert corresponding array of chars
// char exp[26] = {0};
// scanf("%[^\n]%*c", exp);
// for (int i = 0; exp[i] != '\0'; i++)
// {
// printf("%d", exp[i] - 'a');
// }

// this is to do if input is int only
// int a;
// if (scanf("%d", &a) != 1)
// printf("no");
// else
// printf("The number is %d\n", a);

// this is to check if a given number is prime or not
// int isPrime(int num)
// {
// if (num < 2)
// return 0; // 0 and 1 are not prime number
// till sqrt of num cause after that repeatations take place
// for (int i = 2; i * i <= num; i++)
// {
// if (num % i == 0)
// {
// return 0; // Not a prime number
// }
// }
// return 1; // Prime number
// }


// this is conversion of ascii values
// printf("\n");
// char ch = ('z'+3);
// int a = (int)(ch);
// printf("%d", a%122);
// printf("%c",'a'+3-1);
