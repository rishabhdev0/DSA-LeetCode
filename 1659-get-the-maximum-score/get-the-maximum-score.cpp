class Solution {
public:
    const long long mod = 1e9 + 7;

    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        long long sum_path_1 = 0;
        long long sum_path_2 = 0;
        long long max_sum_path = 0;

        int i = 0;
        int j = 0;

        while(i < n && j < m) {

            if(nums1[i] < nums2[j]) {
                sum_path_1 += nums1[i];
                i++;
            }
            else if(nums1[i] > nums2[j]) {
                sum_path_2 += nums2[j];
                j++;
            }
            else {
                // meeting condition
                max_sum_path = (max_sum_path
                                + max(sum_path_1, sum_path_2)
                                + nums1[i]) % mod;

                sum_path_1 = 0;
                sum_path_2 = 0;

                i++;
                j++;
            }
        }

        while(i < n) {
            sum_path_1 += nums1[i];
            i++;
        }

        while(j < m) {
            sum_path_2 += nums2[j];
            j++;
        }

        max_sum_path = (max_sum_path + max(sum_path_1, sum_path_2)) % mod;

        return max_sum_path;
    }
};