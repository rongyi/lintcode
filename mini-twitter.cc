// http://www.lintcode.com/zh-cn/problem/mini-twitter
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

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
  MiniTwitter() {
    // initialize your data structure here.
  }

  // @param user_id an integer
  // @param tweet a string
  // return a tweet
  Tweet postTweet(int user_id, string tweet_text) {
    //  Write your code here
  }

  // @param user_id an integer
  // return a list of 10 new feeds recently
  // and sort by timeline
  vector<Tweet> getNewsFeed(int user_id) {
    // Write your code here
  }

  // @param user_id an integer
  // return a list of 10 new posts recently
  // and sort by timeline
  vector<Tweet>  getTimeline(int user_id) {
    // Write your code here
  }

  // @param from_user_id an integer
  // @param to_user_id an integer
  // from user_id follows to_user_id
  void follow(int from_user_id, int to_user_id) {
    // Write your code here
  }

  // @param from_user_id an integer
  // @param to_user_id an integer
  // from user_id unfollows to_user_id
  void unfollow(int from_user_id, int to_user_id) {
    // Write your code here
  }
};
