class Solution {
public:
    int nthUglyNumber(int n) {
        int a=0,b=0,c=0;
        vector<int>v(n);
        v[0]=1;
        for(int i=1;i<n;i++){
           int arr[3]={2*v[a],3*v[b],5*v[c]};
           v[i]=min(arr[0],min(arr[1],arr[2]));
           if(v[i]==arr[0])++a;
           if(v[i]==arr[1])++b;
           if(v[i]==arr[2])++c;
        }
        return v[n-1];
    }
};