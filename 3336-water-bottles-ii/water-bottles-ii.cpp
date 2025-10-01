class Solution {
public:
    int maxBottlesDrunk(int a, int b) {
       int sum=a;
        while(a>=b){
            a-=b;
            b++;
            sum++;
            a+=1;
        }
        return sum;
    }
};