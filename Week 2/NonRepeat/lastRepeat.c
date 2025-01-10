#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// int compareString(char str1[], char str2[]){
// 
    // while(*str1 != '\0' && *str2 != '\0'){
// 
        // if(*str1 != *str2){
            // return 1; //the strings are different
        // }
// 
        // str1++;
        // str2++;
    // }
// 
    // if(*str1 == '\0' && *str2 == '\0'){
            // return 0; //the strings are same
    // }else{
        // return 1;
    // }
    // 
// }
int are_strings_equal(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}
void nonRepeatingWord(char sentence[]){
    
    char * ptr = sentence;
    char* array[100];
    int i=0;

  
    while(*ptr != '\0'){
        while(*ptr == ' ') ptr++; //skip spaces
        
        array[i++]= ptr;

        while(*ptr != ' ' && *ptr != '\0') ptr++;

        if(*ptr != '\0'){
            *ptr = '\0';
            ptr++;
        }
    }

    for(int j=0; j<i; j++){
        int repeating=0;
        for(int k=0; k<i; k++){
            if(j!=k    &&    
            (are_strings_equal(array[j], array[k]))){
                repeating=1;
            }
        }
        if(!repeating){
            printf("%s", array[j]);
            break;
        }
    }
}
int main() {
    char sentence[100];
    if (scanf("%[^\n]%*c", sentence) != 1) {
        return 0; 
    }
    nonRepeatingWord(sentence);
    return 0;
}