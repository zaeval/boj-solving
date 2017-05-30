//
//  6378_digital_root.cpp
//  acm_icpc
//
//  Created by 홍승의 on 2017. 5. 29..
//  Copyright © 2017년 홍승의. All rights reserved.
//

#include <iostream>
#include <string.h>
int main(){
    char N[1001]={0};
    while(true){
        scanf("%s",N);
        int carry=0;
        int i=0;
        do{
            int len=strlen(N)-1;
            for(i=0;i<len;i++){
                int a=(N[i]=='\0')?(0):(N[i]-'0');
                int b=(N[i+1]=='\0')?(0):(N[i+1]-'0');
                int sum=(a+b)%10;
                carry=(a+b)/10;
                (carry)?(N[i]=sum+'0',N[i+1]=carry+'0'):(N[i]=sum+'0',N[i+1]='\0');
            }
        }while(strlen(N)-1);
        if(N[0]=='0')return 0;
        printf("%d\n",N[0]-'0');
    }
}
