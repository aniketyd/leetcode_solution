class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> out;
        nums.push_back(0);
        for (int i = 0; i < nums.size(); i++){
            while (nums[i] != i){
                if (nums[i] != nums[nums[i]]) swap(nums[i], nums[nums[i]]);
                else break;
            }
        }

        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != i) out.push_back(i);
        }

        return out;
    }
};