#include <iostream>

using namespace std;
int main(){
    int arr[502][502],n,max=0;
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>arr[i][j];
            arr[i][j]=(arr[i-1][j-1]+arr[i][j] > arr[i-1][j]+arr[i][j])?(arr[i-1][j-1]+arr[i][j]):(arr[i-1][j]+arr[i][j]);
            if(max<arr[i][j])
                max=arr[i][j];
        }
    }
    cout << max <<endl;
    
    
    return 0;
}
