class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& arr) {
        
        priority_queue<int>pq;
        sort(arr.begin(), arr.end(), comp);
        int time=0;
        for(int i=0;i<arr.size();i++){
            
            if(time+arr[i][0] <= arr[i][1]){
                time+=arr[i][0]; 
                pq.push(arr[i][0]);
            }
            
            else{
                
                if(!pq.empty() && arr[i][0] < pq.top()){
                    time-=pq.top();
                    time+=arr[i][0];
                    pq.pop();
                    pq.push(arr[i][0]);
                }
            }
        }
        
        if(pq.size()==0)
            return 0;
        return pq.size();
    }
};