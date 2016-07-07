// http://www.lintcode.com/zh-cn/problem/shape-factory

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/**
 * Your object will be instantiated and called as such:
 * ShapeFactory* sf = new ShapeFactory();
 * Shape* shape = sf->getShape(shapeType);
 * shape->draw();
 */
class Shape {
public:
  virtual void draw() const=0;
};

class Rectangle: public Shape {
  void draw() const {
    cout << " ----" << endl;
    cout << "|    |" << endl;
    cout << " ----" << endl;
  }
};

class Square: public Shape {
  void draw() const {
    cout << " ----" << endl;
    cout << "|    |" << endl;
    cout << "|    |" << endl;
    cout << " ----" << endl;
  }
};

class Triangle: public Shape {
  void draw() const {
    cout << "  /\\" << endl;
    cout << " /  \\" << endl;
    cout << "/____\\" << endl;
  }
};

class ShapeFactory {
public:
  /**
   * @param shapeType a string
   * @return Get object of type Shape
   */
  Shape* getShape(string& shapeType) {
    if (shapeType == "Square") {
      Shape *ret = new Square();
      return ret;
    } else if (shapeType == "Triangle") {
      return new Triangle();
    } else if (shapeType == "Rectangle") {
      return new Rectangle();
    }
    return nullptr;
  }
};

int main(int argc, char *argv[])
{
  ShapeFactory sf;
  string t("Square");
  auto s = sf.getShape(t);
  if (!s)
    return 0;
  s->draw();
  // delete s;
  return 0;
}
