#include <iostream>
#include <cstdlib>
#include <cstring>
#define SEC_IN_DAY 86400

using namespace std;

string itoa(int n){
    char arr[3] = {'0','0','\0'};
    if(n<10){
        arr[1]+=n;
    }
    else{
        arr[0]+=n/10;
        arr[1]+=n%10;
    }
    return arr;
}
int main(){
    
    char now[9]={0,}, start[9]={0,}, now_token[3][3]={0,},start_token[3][3]={0,};
    int now_time[3]={0,},start_time[3]={0,};
    
    cin >> now;
    cin >> start;
    
    //token분리 & 초로 계산.
    for(int i=0,j=0;i<strlen(now);i++){
        if(now[i]!=':'){
            now_token[i/3][j]=now[i];
            start_token[i/3][j]=start[i];
            j++;
        }
        else{
            now_time[i/3 + 1] += (atoi(now_token[i/3])+now_time[i/3])*60;
            start_time[i/3 + 1] += (atoi(start_token[i/3])+start_time[i/3])*60;
            j=0;
        }
    }

    now_time[2]+=atoi(now_token[2]);
    start_time[2]+=atoi(start_token[2]);

    int result;
    if(now_time[2]>start_time[2])
        result=(start_time[2]+SEC_IN_DAY)-now_time[2];
    else
        result=start_time[2]-now_time[2];
    
    
    cout<<itoa(result/3600)<<":"<<itoa(result%3600/60)<<":"<<itoa(result%60)<<endl;
    return 0;
}
