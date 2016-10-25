// http://www.lintcode.com/zh-cn/problem/mini-twitter
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::unordered_set;

/**
 * Definition of Tweet:
 * class Tweet {
 * public:
 *     int id;
 *     int user_id;
 *     String text;
 *     static Tweet create(int user_id, string tweet_text) {
 *         // This will create a new tweet object,
 *         // and auto fill id
 *     }
 * }
 */

class Tweet {
public:
  int id;
  int user_id;
  string text;
  static Tweet create(int user_id, string tweet_text) {
    // This will create a new tweet object,
    // and auto fill id
  }
};

class MiniTwitter {
public:
  struct TweetWithTimeline {
    class Tweet t_;
    unsigned long long timeline_;
    TweetWithTimeline(const Tweet &t, unsigned long long timeline) {
      t_ = t;
      timeline_ = timeline;
    }
  };

  MiniTwitter() :
    timeline_(0) {
  }

  // @param user_id an integer
  // @param tweet a string
  // return a tweet
  Tweet postTweet(int user_id, string tweet_text) {
    auto t = Tweet::create(user_id, tweet_text);
    auto tw = TweetWithTimeline(t, timeline_);

    // for next twits
    ++timeline_;
    if (user_twits_.find(user_id) == user_twits_.end()) {
      user_twits_[user_id] = vector<TweetWithTimeline>{};
    }
    // NOTE: the implicit order is: latest element is at the tail of this list
    user_twits_[user_id].push_back(tw);

    return t;
  }

  // @param user_id an integer
  // return a list of 10 new feeds recently
  // and sort by timeline
  vector<Tweet> getNewsFeed(int user_id) {
    vector<TweetWithTimeline> tw;
    // initial value to
    if (user_twits_.find(user_id) != user_twits_.end()) {
      tw = lastn(user_twits_[user_id]);
    }
    if (follow_dict_.find(user_id) != follow_dict_.end()) {
      auto follower_lst = follow_dict_[user_id];
      for (auto user : follower_lst) {
        if (user_twits_.find(user) == user_twits_.end())
          continue;
        auto cur_tw = lastn(user_twits_[user]);
        tw.insert(tw.end(), cur_tw.begin(), cur_tw.end());
      }
    }
    std::sort(tw.begin(), tw.end(),
              [](const TweetWithTimeline &l, const TweetWithTimeline &r) {
                return l.timeline_ < r.timeline_;
              });
    tw = lastn(tw);
    vector<Tweet> ret;

    // reverse order push
    for (auto iter = tw.rbegin(); iter != tw.rend(); iter++) {
      ret.push_back(iter->t_);
    }
    return ret;
  }

  // @param user_id an integer
  // return a list of 10 new posts recently
  // and sort by timeline
  vector<Tweet>  getTimeline(int user_id) {
    vector<Tweet> ret;
    if (user_twits_.find(user_id) == user_twits_.end())
      return ret;
    auto tw = user_twits_[user_id];
    auto tw10 = lastn(tw);

    // reverse order push
    for (auto iter = tw10.rbegin(); iter != tw10.rend(); iter++) {
      ret.push_back(iter->t_);
    }

    return ret;
  }

  // @param from_user_id an integer
  // @param to_user_id an integer
  // from user_id follows to_user_id
  void follow(int from_user_id, int to_user_id) {
    if (follow_dict_.find(from_user_id) == follow_dict_.end()) {
      follow_dict_.insert(std::make_pair(from_user_id, std::unordered_set<int>()));
    }

    follow_dict_[from_user_id].insert(to_user_id);
  }

  // @param from_user_id an integer
  // @param to_user_id an integer
  // from user_id unfollows to_user_id
  void unfollow(int from_user_id, int to_user_id) {
    // not regist yet
    if (follow_dict_.find(from_user_id) == follow_dict_.end())
      return;

    // If the key is not present in the set, 0 is returned indicating that no element was removed.
    follow_dict_[from_user_id].erase(to_user_id);
  }
private:
  vector<TweetWithTimeline> lastn(vector<TweetWithTimeline> &input, int n=10) {
    const int m = input.size();
    int len = std::min(n, m);

    return vector<TweetWithTimeline>(input.end() - len, input.end());
  }
private:
  unordered_map<int, unordered_set<int>> follow_dict_;
  unordered_map<int, vector<TweetWithTimeline>> user_twits_;

  unsigned long long timeline_;
};
