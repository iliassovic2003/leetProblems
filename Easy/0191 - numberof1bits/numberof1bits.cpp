class Solution {
    public:
        int hammingWeight(int n) {
            int ans = 0;

            while (n /= 2) {
                if (n % 2)
                    ans++;
                n /= 2;
            }
            return ans;
        }
};
