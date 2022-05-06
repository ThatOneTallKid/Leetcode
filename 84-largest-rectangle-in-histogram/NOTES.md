For 2 pass solution :
​
we use two arrays left and right which store the next smaller element to the left and right respectively.
then for every index we calculate area as heights[i] * (right[i] - left[i] + 1)