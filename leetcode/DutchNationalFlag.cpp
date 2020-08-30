/*
Given an array with n objects colored red, white or blue,
sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int nz= 0;
        int nt= n-1;
        int i= 0;
        while(i <= nt){
            if(nums[i]== 0){
                int temp= nums[i];
                nums[i]= nums[nz];
                nums[nz]= temp;
                i++;
                nz++;
            }
            else if(nums[i]== 2){
                int temp= nums[i];
                nums[i]= nums[nt];
                nums[nt]= temp;
                nt--;
            }
            else{
                i++;
            }
        }
    }
};
