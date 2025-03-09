class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int cnt=0,ans=0;
        for(int i=1;i<k;i++){
            if(colors[i]==colors[i-1])
            cnt++;
        }
        if(cnt==0)ans++;
        for(int i=1;i<n;i++){
            int j=i+k-1;
             if(colors[j%n]==colors[(j-1)%n])
             cnt++;
             if(colors[(i)%n]==colors[(i-1)%n])
             cnt--;
             if(cnt==0)ans++;
        }
        return ans;
    }
};