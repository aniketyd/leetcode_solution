class Solution {
public:
    bool findSubarrays(vector<int>& nums) {

        set<int>s;

      //  sort(sorted.begin(),sorted.end());

        for(int i=0;i<nums.size()-1;i++)
        {
            if(i!=0&&find(s.begin(),s.end(),nums[i]+nums[i+1])!=s.end())
               return true;
             s.insert(nums[i]+nums[i+1]);

        }


        return false;
    }
};