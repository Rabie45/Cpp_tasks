#include <iostream>
#include <algorithm>
int main(){
std::array <int,6> arr ={2,3,6,5,48,9};
std::array <int,4> arr1 ={1,6,7,6};
std::array <int,10> arr3;
std::merge(arr.begin(),arr.end(),arr1.begin(),arr1.end(),arr3.begin());
for( auto i :arr3){
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