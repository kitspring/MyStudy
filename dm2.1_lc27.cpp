// 原地移除元素
#include <iostream>
#include <chrono> // time lib
#include <vector>

using namespace std;
using namespace chrono;

//------在此定义函数------//
int removeElement(vector<int>& nums, int val) {
    int slowI = 0; // 慢指针，指向有效数组的末尾
    int fastI = 0; // 快指针，遍历整个数组，寻找目标元素
    for(; fastI < nums.size(); fastI++){
        if(nums[fastI] != val){
            nums[slowI++] = nums[fastI];
        }
        else{
            continue; // 慢指针不变，快指针继续走
        }
    }
    return slowI;
}
//------在此定义函数------//

void time_consumption() {
    milliseconds start_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
    );

    //------在此调用函数------//
    vector<int> nums = {3,2,2,3};
    int val = 3;
    cout << removeElement(nums, val);
    //---------------------//

    milliseconds end_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
    );
    cout << "耗时" << milliseconds(end_time).count() - milliseconds(start_time).count()
         << " ms" << endl;
}

int main() {
    time_consumption();
    return 0;
}