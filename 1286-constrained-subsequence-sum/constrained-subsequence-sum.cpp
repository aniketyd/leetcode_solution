class Solution {
public:
    int fun(vector<int>&nums,int k){

        int n=nums.size();
        if(n<k)return 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k-1});
        int mi=INT_MAX;
        for(int i=0;i<n;i++){
             while(pq.top().second<i){
               pq.pop();
             }
            int ans=pq.top().first+nums[i];
            pq.push({ans,i+k});
             if(n-i<=k){
                mi=min(mi,ans);
             }
        }
        return mi;
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>finalNums,temp;
        int sum=0;
        int f=0;
        for(int i=0;i<n;i++){
          if(nums[i]>=0){
            if(temp.size()>0)
            finalNums.push_back(-1*fun(temp,k));
            temp.clear();
            sum+=nums[i];f=1;

          }
          else{
            if(sum!=0)
            finalNums.push_back(sum);sum=0;
             temp.push_back(abs(nums[i]));
          }
        }
        if(sum!=0)
            finalNums.push_back(sum);
            if(temp.size()>0)
            finalNums.push_back(-1*fun(temp,k));
        if(f==0){
            return *max_element(nums.begin(),nums.end());
        }
        int maxSum=0,currSum=0;
        for(int i=0;i<finalNums.size();i++){
              currSum+=finalNums[i];
              currSum=max(currSum,0);
              maxSum=max(maxSum,currSum);
        }
        return maxSum;
    }
};