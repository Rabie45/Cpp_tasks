#include <iostream>
#include <algorithm>
int main(){
std::array <int,6> arr ={2,3,6,5,48,9};

std::cout<< arr.size()<<std::endl;
auto maxElement= std::max_element(arr.begin(), arr.end(),[](int a, int b){
    return a<b;
});
std::cout<<*maxElement<<std::endl;
int val=3;
auto search=std::find(arr.begin(),arr.end(),val);


std::cout<<(search -arr.data())<<std::endl;


auto remove=std::remove(arr.begin(),arr.end(),6);
for(auto i:arr){
std::cout<<i<<" ";
}
return 0;
}