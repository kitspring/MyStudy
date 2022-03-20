// 递归的空间复杂度：递归的深度*每次递归中操作的空间复杂度
#include <iostream>
#include <chrono> // time lib
using namespace std;
using namespace chrono;

int fibonacci_3(int first, int second, int n) {
    if (n <= 0) {
        return 0;
    }
    if (n < 3) {
        return 1;
    }
    else if (n == 3) {
        return first + second;
    }
    else {
        return fibonacci_3(second, first + second, n - 1);
    }
}

void time_consumption() {
    int n;
    while (cin >> n) {
        milliseconds start_time = duration_cast<milliseconds >(
                system_clock::now().time_since_epoch()
        );

        cout << fibonacci_3(1, 1, n);

        milliseconds end_time = duration_cast<milliseconds >(
                system_clock::now().time_since_epoch()
        );
        cout << "耗时" << milliseconds(end_time).count() - milliseconds(start_time).count()
             <<" ms"<< endl;
    }
}

int main()
{
    time_consumption();
    return 0;
}