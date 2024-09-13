class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        result[0] = leftocc(nums, target);
        result[1] = rightocc(nums, target);
        return result;
    }

private:
    int leftocc(vector<int>& nums, int key) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        int ans = -1;

        while (start <= end) {
            mid = (start + end) / 2;

            if (nums[mid] == key) {
                ans = mid;
                end = mid - 1;
            }
            else if (key > nums[mid]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }

    int rightocc(vector<int>& nums, int key) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        int ans = -1;

        while (start <= end) {
            mid = (start + end) / 2;

            if (nums[mid] == key) {
                ans = mid;
                start = mid + 1;
            }
            else if (key > nums[mid]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
};