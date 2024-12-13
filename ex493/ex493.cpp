class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<long long> allValues(nums.begin(), nums.end());
        for (long long num : nums) {
            allValues.push_back((long long)num * 2);
        }
        sort(allValues.begin(), allValues.end());
        allValues.erase(unique(allValues.begin(), allValues.end()), allValues.end());
        
        unordered_map<long long, int> valueToIndex;
        for (int i = 0; i < allValues.size(); ++i) {
            valueToIndex[allValues[i]] = i + 1;
        }
        
        int size = allValues.size();
        vector<int> fenwick(size + 1, 0);
        
        auto fenwickUpdate = [&](int index, int delta) {
            for (; index <= size; index += index & -index) {
                fenwick[index] += delta;
            }
        };
        
        auto fenwickQuery = [&](int index) {
            int sum = 0;
            for (; index > 0; index -= index & -index) {
                sum += fenwick[index];
            }
            return sum;
        };
        
        int reversePairsCount = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            // Query for counts where nums[j] <= nums[i] / 2
            int queryIndex = valueToIndex[(long long)nums[i]];
            reversePairsCount += fenwickQuery(queryIndex - 1);
            
            int updateIndex = valueToIndex[(long long)nums[i] * 2];
            fenwickUpdate(updateIndex, 1);
        }
        
        return reversePairsCount;
    }
};
