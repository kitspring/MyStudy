//
#include <iostream>
#include <chrono> // time lib
#include <vector>

using namespace std;
using namespace chrono;

//------在此定义函数------//
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
//------在此定义函数------//

void time_consumption() {
        milliseconds start_time = duration_cast<milliseconds>(
                system_clock::now().time_since_epoch()
        );

        //------在此调用函数------//
        int s = 7;
        vector<int> nums = {2,3,1,2,4,3};
        minSubArrayLen(s, nums);
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