//
//  2146_make_bridge.cpp
//  acm_icpc
//
//  Created by 홍승의 on 2017. 5. 29..
//  Copyright © 2017년 홍승의. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
class Point{
public:
    int x;
    int y;
    int group;
    int level;
    int value;
    Point(int x,int y,int group,int level,int value){
        this->x=x;
        this->y=y;
        this->group=group;
        this->level=level;
        this->value=value;
    }
};

int main(){
    int mapping[101][101]={0,},N,group=1,groupChecked[101][101]={0,},checked[101][101]={0,};
    int xy[2][4]={{1,-1,0,0},{0,0,1,-1}},MIN=987654321;
    queue<Point> q;
   
    scanf("%d",&N);
    
    int temp;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf("%d",&mapping[i][j]);
            checked[i][j]=mapping[i][j];
            if(mapping[i][j]==1){
                if(mapping[i][j-1])
                    mapping[i][j]=mapping[i][j-1];
                else if(mapping[i-1][j])
                    mapping[i][j]=mapping[i-1][j];
                else
                    mapping[i][j]=group;
            }
            else if(mapping[i][j]==0){
                if(mapping[i-1][j]){
                    group=mapping[i-1][j]+1;
                }
                if(mapping[i][j-1]){
                    
                    group=mapping[i][j-1]+1;
                }
            }
            groupChecked[i][j]=mapping[i][j];
        }
    }
    
    printf("\nmap: \n");
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            printf("%d ",mapping[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("checked: \n");
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            printf("%d ",checked[i][j]);
        }
        printf("\n");
    }
    printf("\ngroup: \n");
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            printf("%d ",groupChecked[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if (mapping[i][j]!=0){
                if(mapping[i][j-1]==0 && j>1)
                    q.push(Point(j,i,mapping[i][j],0,mapping[i][j]));
                else if(mapping[i][j+1]==0 && j<N)
                    q.push(Point(j,i,mapping[i][j],0,mapping[i][j]));
                else if(mapping[i-1][j]==0 && i>1)
                    q.push(Point(j,i,mapping[i][j],0,mapping[i][j]));
                else if(mapping[i+1][j]==0 && i<N)
                    q.push(Point(j,i,mapping[i][j],0,mapping[i][j]));
            }
        }
    }
    while(q.size()){
        Point r=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int y=r.y+xy[1][k];
            int x=r.x+xy[0][k];
            if(!checked[y][x] && y>0 && x>0 && y<=N && x<=N){
                groupChecked[y][x]=r.group;
                checked[y][x]=r.level+1;
                q.push(Point(x,y,r.group,r.level+1,r.level+1));
            }
            else{
                //다른 섬에 도착했을때
                if(mapping[y][x] && mapping[y][x]!=r.group && MIN>r.level){
                    MIN=r.level;
                }
                //다른섬에서 잇기 시작한 다리와 만났을때
                if(!mapping[y][x] && groupChecked[y][x] && groupChecked[y][x]!=r.group && MIN>r.level+checked[y][x]){
                    MIN=r.level+checked[y][x];
                }
                //같은 그룹일때, 이전에 온 값이 더 작으면 그걸로 재갱신
                if(!mapping[y][x] && groupChecked[y][x] && groupChecked[y][x]==r.group && checked[y][x]>r.level+1){
                    checked[y][x]=r.level+1;
                    q.push(Point(x,y,r.group,r.level+1,r.level+1));
                }
            }
//            printf("\nmap: \n");
//            for(int i=0;i<=N;i++){
//                for(int j=0;j<=N;j++){
//                    printf("%d ",mapping[i][j]);
//                }
//                printf("\n");
//            }
//            printf("\n");
//            printf("checked: \n");
//            for(int i=0;i<=N;i++){
//                for(int j=0;j<=N;j++){
//                    printf("%d ",checked[i][j]);
//                }
//                printf("\n");
//            }
//            printf("\ngroup: \n");
//            for(int i=0;i<=N;i++){
//                for(int j=0;j<=N;j++){
//                    printf("%d ",groupChecked[i][j]);
//                }
//                printf("\n");
//            }
//            printf("\n");
        }
    }
    printf("%d\n",(MIN==987654321)?(0):MIN);
}
