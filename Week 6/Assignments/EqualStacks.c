int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3) {
// printf("%d",h1_count);
// printf("%d",h2_count);
// printf("%d",h3_count);
    int top1 = 0;
    int top2 = 0;
    int top3 = 0;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    for(int i = 0;i<h1_count;i++) sum1 += h1[i];
    
    for(int i = 0;i<h2_count;i++) sum2 += h2[i];
    
    for(int i = 0;i<h3_count;i++) sum3 += h3[i];
    
    // if we put && then we have to make it equal as if 5 5 8 then in && it won't work
    // if we put || then it will work
    while(top1<h1_count && top2<h2_count && top3<h3_count){
        if(sum1==sum2 && sum2==sum3) return sum1;
        
        if(sum1>=sum2 && sum1>=sum3){
            sum1 = sum1-h1[top1];
            top1++;
        }
        else if(sum2>=sum1 && sum2>=sum3){
            sum2 = sum2-h2[top2];
            top2++;
        }
        else{
            sum3 = sum3-h3[top3];
            top3++;
        }
    }
    
    return 0;

}