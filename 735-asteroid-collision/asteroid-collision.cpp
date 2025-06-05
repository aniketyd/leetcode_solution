class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(asteroids[i]>=0){st.push(asteroids[i]);continue;}
            while(!st.empty()&&st.top()<abs(asteroids[i])){
                st.pop();
            }
            if(!st.empty()&&st.top()==abs(asteroids[i])){
                st.pop();
            }
            else if(st.empty())
            ans.push_back(asteroids[i]);
        }
        int beforeSize=ans.size();
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin()+beforeSize,ans.end());
        return ans;
    }
};