class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
         int n=nums.size();
         vector<pair<int,int>>v;
         for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
         }
         sort(v.begin(),v.end());
         vector<int> v1,v2;
         v1.push_back(v[0].first);
         v2.push_back(v[0].second);
         for(int i=1;i<n;i++){
            if(v[i].first-v[i-1].first<=limit){
         v1.push_back(v[i].first);
         v2.push_back(v[i].second);
            }
            else{
                sort(v2.begin(),v2.end());
                for(int j=0;j<v2.size();j++){
                    nums[v2[j]]=v1[j];
                }
                v1.clear();
                v2.clear();
                 v1.push_back(v[i].first);
         v2.push_back(v[i].second);
            }
         }
          sort(v2.begin(),v2.end());
                for(int j=0;j<v2.size();j++){
                    nums[v2[j]]=v1[j];
                }
                return nums;
    }
};