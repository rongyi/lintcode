public class Rectangle {
  private int width;
private int height;

  Rectangle(int i, int j) {
    this.width = i;
    this.height = j;
  }

  int getArea() {
    return this.width * this.height;
  }
}
