#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkValidity(char *temp)
{
    int num = 0;
    for (int i = 0; i < strlen(temp); i++)
    {
        if (temp[i] == '0' && (temp[i + 1] >= '1' || temp[i + 1] <= '9'))
        {
            return 1;
        }
    }
    for (int i = 0; i < strlen(temp); i++)
    {
        num = num * 10 + (temp[i] - '0');
    }
    if (num >= 0 && num <= 255)
    {
        return 1;
    }
    return 0;
}

int main()
{
    char input[16];
    int count = 0;
    char temp[16];
    // for(int i = 0;i<16;i++){
    //   scanf("%c",input);
    // }
    fgets(input, 16, stdin);
    int i = 0;
    int length = 0;
    while (input[i++] != '\0')
    {
        length++;
    }

    char *ptr = input;
    char *nptr;

    for (int i = 0; i < length - 1; i++)
    {
        temp[i] = input[i];
        if (input[i] == '.')
        {
            temp[i] = '\0';
            nptr = temp;
            // printf("new ptr %s\t", nptr);

            // printf("%s",input);
            // ptr = input + i;
            // printf("%c",*ptr);
            if (checkValidity(nptr))
            {
                count++;
            };
        }
    }
    if (count == 4)
    {
        printf("Valid");
    }
    else
    {
        printf("Invalid");
    }
    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
//
// Function to validate a single segment of the IPv4 address
// int checkValidity(char *segment) {
// int len = strlen(segment);
//
// Check if the segment is empty or exceeds 3 characters
// if (len == 0 || len > 3) {
// return 0;
// }
//
// Check if the segment contains only digits
// for (int i = 0; i < len; i++) {
// if (!isdigit(segment[i])) {
// return 0;
// }
// }
//
// Convert segment to integer and validate the range
// int num = atoi(segment);
// if (num < 0 || num > 255) {
// return 0;
// }
//
// Check for leading zeros (only allowed if the segment is exactly "0")
// if (segment[0] == '0' && len > 1) {
// return 0;
// }
//
// return 1;
// }
//
// Main function
// int main() {
// char input[16];
// printf("Enter an IPv4 address: ");
// fgets(input, sizeof(input), stdin);
//
// Remove trailing newline character from input, if present
// input[strcspn(input, "\n")] = '\0';
//
// char *segment;
// int segmentCount = 0;
//
//   Tokenize the input string by "."
// segment = strtok(input, ".");
// while (segment != NULL) {
// if (!checkValidity(segment)) {
// printf("Invalid\n");
// return 0;
// }
// segmentCount++;
// segment = strtok(NULL, ".");
// }
//
// Ensure the address contains exactly 4 segments
// if (segmentCount == 4) {
// printf("Valid\n");
// } else {
// printf("Invalid\n");
// }
//
// return 0;
// }
//