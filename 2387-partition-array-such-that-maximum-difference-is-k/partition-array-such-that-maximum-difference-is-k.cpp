class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int st = 0;
        int count =0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]-nums[st]<=k)
            {
                if(i == nums.size()-1)
                {
                    count++;
                }
                continue;
            }
            else
            {
                    count++;
                    st = i;
                    i--;
            }

        }
        return count;
    }
};