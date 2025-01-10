#include <string.h>
#include <stdio.h>

int stringLength(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

int main()
{
    char sentence[101];
    char *wordArray[10];
    char temp[100];
    int tempIndex = 0;
    int wordIndex = 0;
    if (fgets(sentence, sizeof(sentence), stdin) == NULL)
    {
        return 0;
    }
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == '\n')
        {
            sentence[i] = '\0';
            break;
        }
    }
    // for (int i = 0; i <= stringLength; i++)
    // {
    // int j = 0;
    // *(temp + i) = *(sentence + i);
    // if (sentence[i] == ' ')
    // {
    // *(temp + i) = '\0';
    // int *ptr = temp;
    // wordArray[j++] = ptr;
    // }
    // }
    for (int i = 0; i <= stringLength(sentence); i++)
    { // Use <= to include null terminator
        char *ptr = temp;
        if (sentence[i] == ' ' || sentence[i] == '\0')
        {
            temp[tempIndex] = '\0';       // Null-terminate the current word
            wordArray[wordIndex++] = ptr; // Copy the word to wordArray
            tempIndex = 0;                // Reset temp index for the next word
        }
        else
        {
            // char *ptr = temp;
            temp[tempIndex++] = sentence[i]; // Add character to temp
        }
    }
    // the problem with this is that wordarray points to ptr and ptr points to temp 
    // but after each iteration temp is changed and resused so it will point to the last temp
    
    // Print words (for testing)
    for (int i = 0; i < wordIndex; i++)
    {
        printf("Word %d: %s\n", i + 1, wordArray[i]);
    }

    return 0;
}