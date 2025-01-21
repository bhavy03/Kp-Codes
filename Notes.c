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
// char ch = ('z' + 3);
// int a = (ch - 'a');
// printf("%d\n", a%26);
// printf("%c\n",(a%26)+'a');

// if in static 2D array function declaration the size of arr is not known
// then we have to first write int size then int arr[][size] like this
// void flip(int n, int arr[n][n])
// if arr is statically declared like arr[n][n] in main 
// then we can't declare it in function call like this void flip(int n, int **arr)
// cause this a pointer type and in main it arr type

// scanf doesn't take input after space in string but it ignores spaces, newline and tabs integers
// scanf("%d %d",&c,&r);
// or
// scanf("%d", &r);
// scanf("%d",&c);
// these above two both work in same way no difference whether take input as newline or spaced

// In C, when you pass a pointer (e.g., struct Node *head) to a function, the function receives a copy of the pointer,
// not the actual pointer from the calling function. So, when you modify the pointer inside the function, 
// you only modify the copy of the pointer within the function scope, not the original pointer in main.
// Even though you modify the content of the node (e.g., ptr->data), 
// the head pointer in main doesn't get updated to the new node unless you return the modified pointer back to main.

// Why the copy happens: In C, when you pass a pointer to a function, 
// you are passing the value of the pointer (not the address of the original pointer). 
// So inside the function, you're working with a local copy of the pointer. 
// Any change to the pointer itself (e.g., changing where it points) 
// won't affect the original pointer unless you return it and assign it back in main.

// here is the example
// setting ptr = NULL within the function only affects the local copy of the pointer. 
// The original pointer p in main remains unchanged.
// void modifyPointer(int *ptr) {
//     *ptr = 10; // Modify the value pointed to by the pointer
//     ptr = NULL; // Modify the pointer itself
// }
// int main() {
//     int x = 5;
//     int *p = &x; 
//     printf("Before: x = %d, p = %p\n", x, p);
//     modifyPointer(p);
//     printf("After: x = %d, p = %p\n", x, p); 
//     Before: x = 5, p = 0x7ffeefbff58c
//     After: x = 10, p = 0x7ffeefbff58c
//     return 0;
// }

// now this is how to modify the pointer also
// void modifyPointer(int **ptr) {
//     **ptr = 10; // Modify the value pointed to by the pointer
//     *ptr = NULL; // Modify the pointer itself
// }
// modifyPointer(&p);

// void modifyPointer(int **ptr,int **nptr) {
//     // **ptr = 10; // Modify the value pointed to by the pointer
//     *ptr = *nptr ; // Modify the pointer itself
//     printf("%d",**ptr);
// }
// int x = 5,z =12;
// int *p = &x; 
// int *k = &z;
// modifyPointer(&p,&k);
