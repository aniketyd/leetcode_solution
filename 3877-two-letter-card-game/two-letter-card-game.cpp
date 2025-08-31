class Solution {
public:
    pair<int,int> fun(unordered_map<string,int>&mp){
        priority_queue<int>pq;
        for(auto val:mp){
            pq.push(val.second);
        }
        int sum=0;
        while(pq.size()>=2){
            int top=pq.top();
            pq.pop();
            int secondTop=pq.top();
            pq.pop();
            top--;
            secondTop--;
            if(top>0)pq.push(top);
            if(secondTop>0)pq.push(secondTop);
            sum+=1;
        }
        if(pq.size()==1)return {pq.top(),sum};
        return {0,sum};
    }
    int score(vector<string>& cards, char x) {
        int n=cards.size();
        unordered_map<string,int>mp1,mp2;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cards[i][0]==x&&cards[i][1]!=x)
                mp1[cards[i]]++;
            else if(cards[i][0]!=x&&cards[i][1]==x)
                mp2[cards[i]]++;
            else if(cards[i][0]==x&&cards[i][1]==x)
                cnt++;
        }
        auto val1=fun(mp1);
        auto val2=fun(mp2);
        // cout<<val1.first<<' '<<val1.second<<endl;
        // cout<<val2.first<<' '<<val2.second<<endl;
        // cout<<cnt<<endl;
        int ans=0;
        ans+=min(val1.first,cnt);
        cnt-=min(val1.first,cnt);
        ans+=min(val2.first,cnt);
        cnt-=min(val2.first,cnt);
        if(cnt%2==1)cnt--;
        ans+=min(2*(val1.second+val2.second),cnt);
        ans+=(2*(val1.second+val2.second)-min(2*(val1.second+val2.second),cnt))/2;
        return ans;
    }
};