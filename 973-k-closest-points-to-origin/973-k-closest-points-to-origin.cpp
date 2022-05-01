class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq(points.begin(), points.end());
        vector<vector<int>> ans;
        for (int i = 0; i < K; i++) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
private:
    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
        }
    };
};



/*

O(N) quick select

    vector<vector<int>> kClosest(vector<vector<int>>& A, int K) {
        nth_element(A.begin(), A.begin() + K, A.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        return vector<vector<int>>(A.begin(), A.begin() + K);
    }

*/