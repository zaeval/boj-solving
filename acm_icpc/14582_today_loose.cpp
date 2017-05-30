//
//  14582_today_loose.cpp
//  acm_icpc
//
//  Created by 홍승의 on 2017. 5. 29..
//  Copyright © 2017년 홍승의. All rights reserved.
//

#include <iostream>

int main(){
    int ulim[10],temp,tot=0;
    bool check=false;
    for (int i=1;i<10;i++){
        scanf("%d",&ulim[i]);
        ulim[i]=ulim[i-1]+ulim[i];
    }
    for(int i=1;i<10;i++){
        scanf("%d",&temp);
        if(ulim[i]-tot>0)
            check=true;
        tot+=temp;
    }
    if(tot>ulim[9] && check)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
