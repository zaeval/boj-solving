//
//  14583_rope.cpp
//  acm_icpc
//
//  Created by 홍승의 on 2017. 5. 29..
//  Copyright © 2017년 홍승의. All rights reserved.
//

#include <iostream>
#include <math.h>
int main(){
    double a,h,w,l,prop,b;
    scanf("%lf %lf",&w,&h);
    
    a=w*h/(sqrt((h*h)+(w*w)) + w);
    l=(w*h - w*a)/2;
    prop = w/h;
    b=sqrt(l*prop);
    printf("%.2lf %.2lf",b,b/prop);
}
