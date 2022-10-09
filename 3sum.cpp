#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> ans;

        int n = nums.size();

        if( n < 3 ){
            return ans;
        }
        
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-2; ++i){
            //Stop loop once the first number is greater than zero.
            //The sum can never be equal to zero it can only get larger
            //because the list is sorted.
            if(nums[i] > 0){
                break;
            }
            //skip scanned number
            if( i > 0 && nums[i-1] == nums[i] ){
                continue;
            }

            int j = i+1;
            int k = n-1;

            while( j < k ){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum > 0){
                    --k;
                }
                else if( sum < 0 ){
                    ++j;
                }
                else{
                    ans.push_back({ nums[i], nums[j], nums[k] });
                    while( j < k && nums[j] == nums[j+1] ){
                        ++j;
                    }
                    while( j < k && nums[k] == nums[k-1]){
                        --k;
                    }
                    ++j;
                    --k;
                }
            }

        }

        return ans;
    }
};