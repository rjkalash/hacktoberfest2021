class Twitter {
public:

map<int, unordered_set<int>> following;
list<pair<int, int>> tweets;
Twitter() {
    
}

void postTweet(int userId, int tweetId) {
    tweets.push_front({userId, tweetId});
}

vector<int> getNewsFeed(int userId) {
    int count = 10;
    vector<int> feed;
    for (auto x: tweets){
        if (((x.first == userId)||(following[userId].find(x.first) != following[userId].end())) && count > 0){
            feed.push_back(x.second);
            count -= 1;
        }
    }
    return feed;
}

void follow(int followerId, int followeeId) {
    if (following[followerId].find(followeeId) == following[followerId].end()){
        following[followerId].insert(followeeId);
    }
}
vvvvvvv
void unfollow(int followerId, int followeeId) {
    if (following[followerId].find(followeeId) != following[followerId].end()){
        following[followerId].erase(followeeId);
    }
}
};