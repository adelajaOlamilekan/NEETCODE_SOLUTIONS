#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int maximum = 0;
        int area = 0;

        while(i < j){
            area = (j-i) * min(height[i], height[j]);

            maximum = max(area, maximum);

            if( height[i] <= height[j] ){
                ++i;
            }
            else{
                --j;
            }
        }

        return maximum;
        
    }
};