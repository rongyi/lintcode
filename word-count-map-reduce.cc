// http://www.lintcode.com/zh-cn/problem/word-count-map-reduce
// http://www.lintcode.com/zh-cn/problem/word-count-map-reduce
/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done();
 *         // Returns true if the iteration has no elements.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 */
namespace detail{

/* like python split
 */
inline void split(const char delim, const std::string &input, std::vector<std::string> &output) {
  if (input.empty())
    return;

  output.clear();
  size_t token_start_pos = 0;
  size_t token_size = 0;

  for (size_t i = 0; i <= input.size() - 1; ++i) {
    if (input[i] == delim) {
      if (token_size > 0) {
        output.push_back(std::string(input, token_start_pos, token_size));
      }
      token_start_pos = i + 1;
      token_size = 0;
    } else {
      ++token_size;
    }
  }

  // the last one
  token_size = input.size() - token_start_pos;
  if (token_size > 0) {
    output.push_back(std::string(input, token_start_pos, token_size));
  }
}
} // namespace detail

class WordCountMapper: public Mapper {
public:
  void Map(Input<string>* input) {
    // Write your code here
    // Please directly use func 'output' to
    // output the results into output buffer.
    // void output(string &key, int value);
    while (!input->done()) {
      string cur = input->value();
      vector<string> vec;
      detail::split(' ', cur, vec);
      for (auto s : vec) {
        output(s, 1);
      }
      input->next();
    }
  }
};


class WordCountReducer: public Reducer {
public:
  void Reduce(string &key, Input<int>* input) {
    // Write your code here
    // Please directly use func 'output' to
    // output the results into output buffer.
    // void output(string &key, int value);
    int sum = 0;
    while (!input->done()) {
      sum += input->value();
      input->next();
    }
    output(key, sum);
  }
};
