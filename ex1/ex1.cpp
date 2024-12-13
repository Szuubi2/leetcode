class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        std::map<int, vector<int>> value2index;
        for (int i = 0; i < nums.size(); i++) {
            value2index[nums[i]].push_back(i);
        }

        mergeSort(nums, 0, nums.size() - 1);

        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int currentSum = nums[left] + nums[right];
            if (currentSum == target) {
                return { value2index[nums[left]].front(), value2index[nums[right]].back()};
            } else if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};
        
    }


    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;
        int i = left;
        int j = mid+1;

        while(i <= mid && j <= right) {
            if(nums[i] > nums[j]) {
                temp.push_back(nums[j]);
                j++;
            }
            else {
                temp.push_back(nums[i]);
                i++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int k = left; k <= right; k++) {
            nums[k] = temp[k - left];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
        
    }
};
