class ProductOfNumbers {
public:
    vector<long long> nums;

    ProductOfNumbers() {
        nums.clear();
    }

    void add(int num) {
        if(num == 0) {
            nums.clear();
            return;
        }

        if(!nums.empty()) {
            nums.push_back(nums.back() * num);
        } else {
            nums.push_back(num);
        }
    }

    int getProduct(int k) {
        int n = nums.size();

        if(k > n) {
            return 0;
        }

        if(k == n) {
            return nums.back();
        }

        return nums.back() / nums[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */