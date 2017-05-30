//
//  vertical_read.cpp
//  acm_icpc
//
//  Created by 홍승의 on 2017. 5. 8..
//  Copyright © 2017년 홍승의. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define big(a,b) (a>b)?a:b

int main(){
    char arr[5][16]={0,},max=0;
    
    for(int i=0;i<5;i++){
        gets(arr[i]);
        max=big(strlen(arr[i]),max);
    }
    
    for(int i=0;i<max;i++){
        for(int j=0;j<5;j++){
            if(arr[j][i]!=0){
                printf("%c",arr[j][i]);
            }
        }
    }
    printf("\n");
    return 0;
}
