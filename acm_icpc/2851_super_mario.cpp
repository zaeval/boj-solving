//
//  super_mario.cpp
//  acm_icpc
//
//  Created by 홍승의 on 2017. 5. 29..
//  Copyright © 2017년 홍승의. All rights reserved.
//

#include <iostream>

int main(){
    int tot=0;
    int temp=0;
    for(int i=0;i<10;i++){
        scanf("%d",&temp);
        tot+=temp;
        if(tot>=100)break;
    }
    tot=(tot-100 <= (100-tot+temp))?(tot):(tot-temp);
    printf("%d",tot);
    return 0;
}
