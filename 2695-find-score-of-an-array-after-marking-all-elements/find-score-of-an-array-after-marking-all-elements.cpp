class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        long long sum=0;
        while(!pq.empty()){
        auto t=pq.top();
        if(nums[t.second]!=-1){
            sum+=t.first;
            if(t.second-1>=0)
            nums[t.second-1]=-1;
            if(t.second+1<n)
            nums[t.second+1]=-1;
        }
        pq.pop();

        }
        return sum;
    }
};