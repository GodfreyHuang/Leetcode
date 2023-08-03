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