class Solution {
public:
    int numWaterBottles(int a, int b) {
        int sum=a;
        while(a>=b){
         
          int d=a/b;
          sum+=d;
          a-=a/b*b;
          a+=d;
        }
        return sum;
    }
};