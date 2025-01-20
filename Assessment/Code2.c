// Online C compiler to run C program online
#include <stdio.h>
int ifMultiple(int i){
    return (i%3 == 0);
}
void encrypts(char *str,int k){
    for(int i =0;str[i] != '\0';i++){
        if(ifMultiple(i) && str[i]!= ' '&& (str[i] >= 'a' && str[i]<= 'z')){
            // printf("%d",i);
            str[i] = (str[i] - 'a' + k)%26 + 'a';
            // printf("%c",str[i]);
        }
    }
}

int main() {
    char string[100];
    scanf("%[^\n]%*c",string);
    int k;
    scanf("%d",&k);
    if(!(0<=k && k<= 30)){
        printf("Enter Valid value of k");
    }else{
        encrypts(string,k);
        printf("%s",string);
    }
    // printf("\n");
    // printf("%d",('y' - 'a'+7 )%26);
    

    return 0;
}
