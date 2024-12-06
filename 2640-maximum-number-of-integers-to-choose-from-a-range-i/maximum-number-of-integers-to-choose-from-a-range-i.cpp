class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(),banned.end());
        
        int num=1;
        long long sum=0;
        int s=banned.size();
        // for(int i=0;i<s;i++)
        // cout<<banned[i]<<' ';
        // cout<<endl;
        int c=0;
        int j=0;
        while(num<=n){
          while(j<s&&num==banned[j]){
            while(j<s&&num==banned[j])++j;
        num++;
          }
          if((sum+num)>maxSum||num>n)break;
          c++;
         
          sum+=num;
           
          num++;
        }
        return c;
    }
};