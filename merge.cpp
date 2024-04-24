#include <array>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
int main(){
std::array <int,6> arr ={2,3,6,5,48,9};
std::array <int,4> arr1 ={1,6,7,6};
std::array <int,10> arr3;
std::merge(arr.begin(),arr.end(),arr1.begin(),arr1.end(),arr3.begin());
std::vector<int> v{1,23};
std::vector<int> v2{10,15};
std::vector<int> v3(v.size()+v2.size());
v.resize(v.size()+v2.size());
std::merge(v.begin(),v.end(),v2.begin(),v2.end(),v3.begin());
std::sort(std::begin(v3),std::end(v3));
std::cout<<std::endl;
std::cout<<std::endl;
return 0;


for( auto i :v3){
    std::cout<<i<<" ";
}
}

/*

how it works 1<2 
1
2<3
2
3<6
3
6=6
6
6<5
5
6<7
6
7<48
7
48<6
6
48 then 9

std::merge compares elements from both input sequences and copies the smaller element to the output sequence.
If both elements are equal, elements from the first sequence are copied before those from the second sequence.
The operation continues until all elements from both sequences have been merged into the output sequence.
 

*/