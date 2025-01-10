#include <stdio.h>
#include <string.h>
#include <ctype.h>

int stringLength(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}
void reverseWords(char *sentence)
{
    char *start = sentence;
    char *end = sentence + stringLength(sentence) - 1;

    // Remove leading spaces
    while (*start == ' ')
        start++;

    // Remove trailing spaces
    while (end >= start && *end == ' ')
        end--;

    // Temporary array to store the reversed sentence
    char temp[101];
    char *tempPtr = temp;

    // Iterate backwards to extract words and copy them to temp
    while (end >= start)
    {
        // Find the end of the current word
        while (end >= start && *end == ' ')
            end--; // Skip spaces

        char *wordEnd = end;

        // Find the start of the current word
        while (end >= start && *end != ' ')
            end--;
        char *wordStart = end + 1;

        // Copy the word into the temp array
        while (wordStart <= wordEnd)
        {
            *tempPtr++ = *wordStart++;
        }

        // Add a space if more words are present
        if (end >= start)
        {
            *tempPtr++ = ' ';
        }
    }

    *tempPtr = '\0'; // Null-terminate the reversed sentence

    // Copy temp back to the original sentence
    strcpy(sentence, temp);
}

int main()
{
    char sentence[101];
    // Read input
    if (fgets(sentence, sizeof(sentence), stdin) != NULL)
    {
        // Remove trailing newline character if present
        sentence[strcspn(sentence, "\n")] = '\0';

        // Reverse the words in the sentence
        reverseWords(sentence);

        // Print the reversed sentence
        printf("%s\n", sentence);
    }
    return 0;
}
