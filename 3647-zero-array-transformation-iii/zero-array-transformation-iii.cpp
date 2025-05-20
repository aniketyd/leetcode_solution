
class Solution {
public:
   static bool cmp(vector<int> &v1,vector<int> &v2){
        if(v1[0]==v2[0])
        return v2[1]<v1[1];
        return v1[0]<v2[0];
    }
    int maxRemoval(vector<int>& nums, vector<vector<int>>& qu) {
        int n=nums.size();
        int q=qu.size();
        priority_queue<int,vector<int>,greater<int>>minpq;
        priority_queue<int>maxpq;
        sort(qu.begin(),qu.end(),cmp);
        int j=0;
        for(int i=0;i<n;i++){
            while(j<qu.size()&&qu[j][0]==i){
                maxpq.push(qu[j][1]);
                j++;
            }
            while(minpq.size()>0&&minpq.top()<i)
            minpq.pop();
            while(minpq.size()<nums[i]){
                if(maxpq.size()==0||maxpq.top()<i)return -1;
                minpq.push(maxpq.top());
                maxpq.pop();
            }
        }
        return (int)maxpq.size();
    }
};