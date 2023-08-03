#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ans;
        unordered_map<int, int> db;
        for(int i = 0; i < nums.size(); i++)
        {
            if(db.count(target - nums[i]))
            {
                ans.push_back(db[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            db[nums[i]] = i;
        }

        return ans;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    int target = 9;

    Solution test;
    vector<int> res = test.twoSum(nums, target);
    for(const auto& e: res)
    {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
