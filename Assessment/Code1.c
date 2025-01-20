// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

void invert (int **arr ,int r,int c){
    if(arr[r][c] == 0){
        arr[r][c] = 1;
    }else{
        arr[r][c] = 0;
    }
    
}
void flip(int **arr,int n){
    int start = 1;
    int end = n;
    while(start < end){
        for(int i = 1;i<= n;i++){
            int temp = arr[0][i];
            arr[0][i] = arr[n-i+1][i];
            arr[n-i+1][i] = temp;
        }
        start++;
        end--;
    }
}
void rotate(int **arr,int n){
    for(int i = 1;i<= n;i++){
        for(int j = i+1;j<= n;j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    flip(arr,n);
}
int main() {
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    int arr[n][n];
    
    for(int i =1 ; i<=n;i++){
        for(int j = 1;j<=n;j++){
            arr[i][j] = 0;
        }
    }
    
    
    // while(m>0){
    //     int k;
    //     scanf("%d",k);
    //     if(k == 1){
    //         int r;
    //         scanf("%d",&r);
    //         int c;
    //         scanf("%d",&c);
    //         flip(arr[n][n],r,c);
    //     }
    //     if(k == 2){
    //         flip(arr,n);
    //     }
    //     if(k == 3){
    //         rotate(arr,n)
    //     }
    // }
    
    // char input[8];
    // while(m>0){
    //     scanf("%[^/n]%*c",input);
    //     int arr[2];
    //     int index = 0;
    //     for(int i =0;input[i]!='\0';i++){
    //     if(input[0] == '1'){
    //         while(input[i]!='\0'){
    //             if(input[i] == ' '){
    //             i++;
    //         }
    //         if(input[i] == '0' && input[i] == '1'){
    //             arr[index] = input[i];
    //             index++;
    //         }
    //         }
            
    //         invert(arr,arr[0],arr[1]);
    //     }
    //     if(input[0] == '2'){
    //         flip(arr,n);
    //         break;
    //     }
    //     if(input[0] == '3'){
    //         rotate(arr,n);
    //         break;
    //     }
    //   }
    //   input[0] == '\0';
    // m--;
    // }
    
    for(int i =1; i<=n;i++){
        for(int j = 1;j<=n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
