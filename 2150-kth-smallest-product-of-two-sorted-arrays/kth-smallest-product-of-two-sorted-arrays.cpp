#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long negLessNo(vector<long long>& neg1,
                        vector<long long>& neg2,
                        vector<long long>& pos1,
                        vector<long long>& pos2,
                        long long mid) {
        long long sizeNeg1 = neg1.size();
        long long sizeNeg2 = neg2.size();
        long long sizePos1 = pos1.size();
        long long sizePos2 = pos2.size();

        // If mid >= 0, then all negative×positive and positive×negative pairs
        // will be <= mid. Count = (neg1.size()*pos2.size() + neg2.size()*pos1.size())
        if (mid >= 0) {
            return sizeNeg1 * sizePos2 + sizeNeg2 * sizePos1;
        }

        // Otherwise mid < 0: count how many neg×pos products <= mid.
        long long numLesserEle = 0;

        // For neg1×pos2: neg1[i] = |nums1[i]|, pos2[j] > 0.
        // We want (–neg1[i] * pos2[j]) <= mid  <=>  neg1[i] * pos2[j] >= -mid
        // So pos2[j] >= ceil((-mid)/neg1[i]). Count those j’s.
        for (long long i = 0; i < sizeNeg1; i++) {
            long long a = neg1[i]; // absolute value of a negative from nums1
            long long need = ((-mid) + a - 1) / a; // ceil((-mid)/a)
            auto it = lower_bound(pos2.begin(), pos2.end(), need);
            long long count = pos2.end() - it;
            numLesserEle += count;
        }

        // For neg2×pos1:
        for (long long i = 0; i < sizeNeg2; i++) {
            long long b = neg2[i]; // absolute value of a negative from nums2
            long long need = ((-mid) + b - 1) / b;
            auto it = lower_bound(pos1.begin(), pos1.end(), need);
            long long count = pos1.end() - it;
            numLesserEle += count;
        }

        return numLesserEle;
    }

    long long posLessNo(vector<long long>& neg1,
                        vector<long long>& neg2,
                        vector<long long>& pos1,
                        vector<long long>& pos2,
                        long long mid) {
        long long sizeNeg1 = neg1.size();
        long long sizeNeg2 = neg2.size();
        long long sizePos1 = pos1.size();
        long long sizePos2 = pos2.size();

        // If mid <= 0, no positive product can be <= mid.
        if (mid <= 0) {
            return 0LL;
        }

        long long numLesserEle = 0;

        // Count neg1×neg2 => both are stored as absolute values.
        // Actual product = (–neg1[i])*(–neg2[j]) = +neg1[i]*neg2[j] <= mid
        // So neg2[j] <= floor(mid/neg1[i])
        for (long long i = 0; i < sizeNeg1; i++) {
            long long a = neg1[i];
            long long limit = mid / a; // floor division since mid>0, a>0
            auto it = upper_bound(neg2.begin(), neg2.end(), limit);
            long long count = it - neg2.begin();
            numLesserEle += count;
        }

        // Count pos1×pos2 => both positive
        for (long long i = 0; i < sizePos1; i++) {
            long long a = pos1[i];
            long long limit = mid / a;
            auto it = upper_bound(pos2.begin(), pos2.end(), limit);
            long long count = it - pos2.begin();
            numLesserEle += count;
        }

        return numLesserEle;
    }

    long long kthSmallestProduct(vector<int>& nums1,
                                 vector<int>& nums2,
                                 long long k) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<long long> neg1, pos1, neg2, pos2;
        long long c1 = 0, c2 = 0; // counts of zeros in nums1 and nums2

        // Separate nums1 into negatives (store abs), zeros, positives
        for (int i = 0; i < n1; i++) {
            if (nums1[i] < 0) {
                neg1.push_back(llabs(nums1[i])); 
            } else if (nums1[i] == 0) {
                c1++;
            } else {
                pos1.push_back(nums1[i]);
            }
        }

        // Separate nums2
        for (int i = 0; i < n2; i++) {
            if (nums2[i] < 0) {
                neg2.push_back(llabs(nums2[i]));
            } else if (nums2[i] == 0) {
                c2++;
            } else {
                pos2.push_back(nums2[i]);
            }
        }

        // Sort all four arrays in ascending order of their values
        sort(neg1.begin(), neg1.end());
        sort(neg2.begin(), neg2.end());
        sort(pos1.begin(), pos1.end());
        sort(pos2.begin(), pos2.end());

        // Count total zero-product pairs (only contribute if mid >= 0)
        long long totalZero = c1 * ( (long long)neg2.size() + (long long)pos2.size() )
                            + c2 * ( (long long)neg1.size() + (long long)pos1.size() );

        // Binary search over possible product value range
        long long low = -10000000000LL;
        long long high =  10000000000LL;
        long long ans = 0;

        while (low <= high) {
            long long mid = low + ( (high - low) >> 1 );

            // 1) Count how many products <= mid
            long long count = 0;
            // a) Negative products <= mid
            count += negLessNo(neg1, neg2, pos1, pos2, mid);

            // b) Zero products if mid >= 0
            if (mid >= 0) {
                count += totalZero;
            }

            // c) Positive products <= mid if mid >= 0
            if (mid > 0) {
                count += posLessNo(neg1, neg2, pos1, pos2, mid);
            }

            if (count >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
