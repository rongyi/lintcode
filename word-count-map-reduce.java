/**
 * Definition of OutputCollector:
 * class OutputCollector<K, V> {
 *     public void collect(K key, V value);
 *         // Adds a key/value pair to the output buffer
 * }
 */
public class WordCount {

  public static class Map {
    public void map(String key, String value, OutputCollector<String, Integer> output) {
      // Write your code here
      // Output the results into output buffer.
      // Ps. output.collect(String key, int value);
      String[] arr = value.split(" ");
      for (int i = 0; i < arr.length; i++) {
        output.collect(arr[i], 1);
      }
    }
  }

  public static class Reduce {
    public void reduce(String key, Iterator<Integer> values,
                       OutputCollector<String, Integer> output) {
      // Write your code here
      // Output the results into output buffer.
      // Ps. output.collect(String key, int value);
      int sum = 0;
      while (values.hasNext()) {
        sum += values.next().intValue();
      }
      output.collect(key, sum);
    }
  }
}
