class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int,unordered_set<int>> following;
    priority_queue<vector<int>> pq;
    int t;
    Twitter() {
        t = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        pq.push({t, userId, tweetId});
        t++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<vector<int>> tmp;
        while(pq.size()) {
            auto top = pq.top();
            if(top[1] == userId) {
                ans.push_back(top[2]);
            }
            else if(following[userId].find(top[1]) != following[userId].end()) {
                ans.push_back(top[2]);
            }
            
            pq.pop();
            tmp.push(top);
            if(ans.size() == 10) {
                break;
            }
        }
            
        while(tmp.size()) {
            auto top = tmp.top();
            tmp.pop();
            pq.push(top);
        }


        return ans;

    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */