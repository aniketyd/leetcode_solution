class Solution {
public:
  vector<int> sieve(int n) {
    // Step 1: Create a boolean array and initialize all entries as true
    std::vector<bool> isPrime(n + 1, true);
    
    // Step 2: 0 and 1 are not prime numbers
    isPrime[0] = isPrime[1] = false;

    // Step 3: Mark multiples of each prime number
    for (int p = 2; p * p <= n; p++) {
        // If p is a prime
        if (isPrime[p]) {
            // Mark all multiples of p as not prime
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
vector<int>ans;
    // Step 4: Print all prime numbers
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            ans.push_back(i);
        }
    }
    return ans;
}
    bool primeSubOperation(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>v=sieve(1010);
        int prev=0;
        for(int i=0;i<n;i++){
            auto indx=lower_bound(v.begin(),v.end(),nums[i]-prev)-v.begin();
            if(indx!=0)
          {  indx--;
            nums[i]=nums[i]-v[indx];}
            if(prev>=nums[i])return 0;
            prev=nums[i];
          
        }
        return 1;
    }
};