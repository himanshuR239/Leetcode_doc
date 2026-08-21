class Twitter {
public:
    vector<pair<int, int>> posts;
    unordered_map<int, unordered_set<int>> following;

    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        for(int i = posts.size() - 1; i >= 0 && ans.size() < 10; i--){
            int user = posts[i].first;
            int tweet_id = posts[i].second;

            if(user == userId || following[userId].count(user)){
                ans.push_back(tweet_id);
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
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