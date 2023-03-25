#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int found = 0;
        int current, iterator = 0;
        while (!found)
        {

            int seconsIterator = iterator++;

                        while (seconsIterator < nums.size())
            {

                if (nums[iterator] + nums[seconsIterator] == target)
                {
                    found = 1;
                    return {iterator, seconsIterator};
                }
                cout << iterator << " " << seconsIterator << endl;
                seconsIterator++;
            }
            iterator++;
        }
        return {-1, -1};
    };
};

int main()
{

    Solution solution;
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> result = solution.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }

    return 0;
}