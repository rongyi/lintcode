#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
/**
 * Your object will be instantiated and called as such:
 * ToyFactory* tf = new ToyFactory();
 * Toy* toy = tf->getToy(type);
 * toy->talk();
 */
class Toy {
public:
  virtual void talk() const=0;
};

class Dog: public Toy {
  void talk() const {
    cout << "Wow" << std::endl;
  }
};

class Cat: public Toy {
  void talk() const {
    cout << "Meow" << std::endl;
  }
};

class ToyFactory {
public:
  /**
   * @param type a string
   * @return Get object of the type
   */
  Toy* getToy(string& type) {
    if (type == "Dog") {
      return new Dog();
    } else if (type == "Cat") {
      return new Cat();
    }
    return nullptr;
  }
};

int main(int argc, char *argv[])
{
  ToyFactory tf;
  string t("Dog");
  auto e = tf.getToy(t);
  e->talk();

  return 0;
}
