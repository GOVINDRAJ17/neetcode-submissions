class Twitter {
public:
    struct Tweet{
        int id;
        int time;
        Tweet(int id,int time){
            this->id=id;
            this->time=time;
        }
    };
    int timestamp;
    unordered_map<int,vector<Tweet>> tweets;
    unordered_map<int,unordered_set<int>> following;



    Twitter() {
        timestamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        timestamp++;
        tweets[userId].push_back(Tweet(tweetId,timestamp));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<Tweet> alltweets;
        for(auto tweet:tweets[userId])
            alltweets.push_back(tweet);
        for(auto follow:following[userId]){
            for(auto tweet:tweets[follow]){
                alltweets.push_back(tweet);
            }
        }
        sort(
            alltweets.begin(),
            alltweets.end(),
            [](const Tweet& a, const Tweet& b){
                return a.time>b.time;
            }
        );
        vector<int>result;
        for(int i=0;i<min(10,(int)alltweets.size());i++){
            result.push_back(alltweets[i].id);
        }
        return result; 
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
