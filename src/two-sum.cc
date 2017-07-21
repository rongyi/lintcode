// http://www.lintcode.com/zh-cn/problem/two-sum

class Solution {
public:
  /*
   * @param numbers : An array of Integer
   * @param target : target = numbers[index1] + numbers[index2]
   * @return : [index1+1, index2+1] (index1 < index2)
   */
  vector<int> twoSum(vector<int> &num, int target) {
    vector<int> ret;
    map<int, int> num_index_map;

    for (int i = 0; i < num.size(); i++) {
      // return with start index as 1
      num_index_map[num[i]] = i + 1;
    }

    for (int i = 0; i < num.size(); i++) {
      auto gap = target - num[i];
      if (num_index_map.find(gap) != num_index_map.end() && num_index_map[gap] - 1 > i) {
        ret.push_back(i + 1);
        ret.push_back(num_index_map[gap]);
        break;
      }
    }

    return ret;
  }
};
