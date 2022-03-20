// 合并多个set直至彼此没有交集

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


void outputset(set<int> & s){
    for(set<int>::iterator it = s.begin(); it != s.end(); it++)
        cout<<*it<<" ";
}
int main()
{
    set<int>s1 = {1,2,3};
    set<int>s2 = {7,9};
    set<int>s3 = {6,0};
    set<int>s4 = {3,4,5};
    vector<set<int>>v = {s1,s2,s3,s4};
    set<int>C;
    vector<set<int>>ans;
    for (int i = 0; i < v.size(); ++i) {
        while(v[i].size() == 0){
            i++;
        }
        if(i >= v.size()) break;
        set<int> t = v[i]; // 从v[i]向后合并所有
        v[i].clear();
        for(int j = i+1; j < v.size(); j++){
            set_intersection(t.begin(),t.end(),v[j].begin(),v[j].end(), inserter(C,C.begin()));
            if(!C.empty()){ // 有交集，合并v[j]到t上，清空v[j]，用新t向后继续合并
                set_union(t.begin(),t.end(),v[j].begin(),v[j].end(),inserter(t, t.begin() ) );
                v[j].clear(); // 被合并的清空，先不删除
            }
            else{ // 没有交集，不管
                continue;
            }
            C.clear();
        }
        ans.push_back(t);
    }
    for(int i = 0; i < ans.size(); ++i) {
        cout << "ans "<< i <<":";
        outputset(ans[i]);
        cout << endl;
    }
    return 0;
}