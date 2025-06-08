class Solution {
public:
vector<int>ans;
int N;
    void lexOrder(int n){
        if(n>N)return;
        ans.push_back(n);
        n*=10;
        for(int i=0;i<10;i++){
            n+=i;
            if(n>N)break;
            lexOrder(n);
            n-=i;
        }
    }
    vector<int> lexicalOrder(int n) {
        N=n;
        for(int i=1;i<=9;i++)
        lexOrder(i);
        return ans;
    }
};