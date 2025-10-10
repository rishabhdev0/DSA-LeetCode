// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> result(n, 0);  // ✅ 1D vector initialized to 0
//         int zeroCount = 0;
//         int productWithoutZero = 1;
//         // Step 1: Count zeros and compute product of non-zero numbers
//         for (int num : nums) {
//             if (num == 0)
//                 zeroCount++;
//             else
//                 productWithoutZero *= num;
//         }

//         // Step 2: Fill the result
//         for (int i = 0; i < n; i++) {
//             if (zeroCount > 1) {
//                 // More than one zero → all elements = 0
//                 result[i] = 0;
//             } else if (zeroCount == 1) {
//                 // Exactly one zero → only that index gets the product
//                 result[i] = (nums[i] == 0) ? productWithoutZero : 0;
//             } else {
//                 // No zeros
//                 result[i] = productWithoutZero / nums[i];
//             }
//         }

//         return result;
//     }
// };

// 2nd method -> without divsion

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        // result[i] will hold the product of all elements to the left of i
        int leftProd = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = leftProd;
            leftProd *= nums[i];
        }

        // 2) Multiply by product of all elements to the right of i
        int rightProd = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= rightProd;
            rightProd *= nums[i];
        }

        return result;
    }
};

