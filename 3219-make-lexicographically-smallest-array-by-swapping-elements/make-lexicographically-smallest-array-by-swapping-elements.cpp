class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // value + original index
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Values ko sort karo
        sort(arr.begin(), arr.end());

        int start = 0;

        while (start < n) {

            int end = start;

            // Ek group banao
            while (end + 1 < n &&
                   arr[end + 1].first - arr[end].first <= limit) {
                end++;
            }

            // Group ke original indices
            vector<int> indices;

            for (int i = start; i <= end; i++) {
                indices.push_back(arr[i].second);
            }

            // Original indices ko sort karo
            sort(indices.begin(), indices.end());

            // Group ki sorted values ko original positions par rakho
            for (int i = 0; i < indices.size(); i++) {
                nums[indices[i]] = arr[start + i].first;
            }

            start = end + 1;
        }

        return nums;
    }
};