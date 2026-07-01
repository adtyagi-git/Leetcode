class Solution {
private:
    vector<int> findpresmall(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[i] < nums[st.top()])
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findnextsmall(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] <= nums[st.top()])
                st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumofminimums(vector<int>& nums) {
        vector<int> presmall = findpresmall(nums);
        vector<int> nextsmall = findnextsmall(nums);
        long long total = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long left = i - presmall[i];
            long long right = nextsmall[i] - i;
            total += left * right * 1LL * nums[i];
        }
        return total;
    }
    vector<int> findprebig(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[i] > nums[st.top()])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findnextbig(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= nums[st.top()])
                st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumofmaximums(vector<int>& nums) {
        vector<int> prebig = findprebig(nums);
        vector<int> nextbig = findnextbig(nums);
        long long total = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long left = i - prebig[i];
            long long right = nextbig[i] - i;

            total += left * right * 1LL * nums[i];
        }
        return total;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return sumofmaximums(nums) - sumofminimums(nums);
    }
};