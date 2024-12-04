class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
       if(n1>n2)return findMedianSortedArrays(nums2,nums1);
       int n=(n1+n2+1)/2;
       int low=0,high=min(n1,n);
       while(low<=high){
        int mid=(high+low)/2;
        int l1=INT_MIN,r1=INT_MAX;
        int l2=INT_MIN,r2=INT_MAX;
        int mid2=n-mid;
        if(mid2<n2)r2=nums2[mid2];
        if(mid<n1)r1=nums1[mid];
        if(mid-1>=0)l1=nums1[mid-1];
        if(mid2-1>=0)l2=nums2[mid2-1];
        if(l1<=r2&&l2<=r1){
            if((n1+n2)%2==1)
            return max(l1,l2);
            double ans=(max(l1,l2)+min(r1,r2))/2.0;
            return ans;
        }
        if(l1>r2)high=mid-1;
        else  low=mid+1;
       }
       return 0.0;
    }
};