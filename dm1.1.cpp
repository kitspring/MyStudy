// 递归算法的时间复杂度：递归次数*每次递归的操作
// 例：求x的n次方
#include<iostream>
using namespace std;

// 一般思路：递归n次，每次1次乘法操作，即O(n*1)=O(n)
int function2(int x, int n){
    if(n == 0){
        return 1;
    }
    return function2(x, n-1) * x;
}

// 递归log2(n)次，每次乘法操作
int function4(int x, int n){
    if(n == 0){
        return 1;
    }
    int t = function4(x, n / 2); // 先用一个常数项把递归操作提取出来
    if(n % 2 == 0){
        return t * t;
    }
    else{
        return t * t * x;
    }
}

int main() {
    int x = 2;
    int n = 4;
    int res = function4 (x, n);
    cout<<res<<endl;

    return 0;
}