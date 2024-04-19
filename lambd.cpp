#include <iostream>
#include <algorithm>
int main(){
int arr[6]= {2,3,6,5,48,9};
std::sort(std::begin(arr),std::end(arr),[](int a,int b){
    return a>b;
});
for(auto i:arr){
std::cout<<i<<" ";
}

*max_element(arr, arr + n)
return 0;
}





