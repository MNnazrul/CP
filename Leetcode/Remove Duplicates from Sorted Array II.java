class Solution {
    public int removeDuplicates(int[] nums) {
        int l = 1, cn = 1;
        for (int i = 1; i < nums.length; i++) {
            if(nums[i] == nums[i - 1]) {
                cn++;
            } else cn = 1;
            if(cn <= 2) {
                nums[l] = nums[i];
                l++;
            }
        }
        return l;
    }
}
