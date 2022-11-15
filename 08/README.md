# Semaine 8/16

## Objet et attribut

```cpp
class Class {
    int attribute;
};

int main() {
    Class class; // objet;
}
```

## Template

```cpp

class Point {
    int x, y;
    public:
    Point(int x, int y) : x{x}, y{y} {}
    int get_x() { return x; }
    int get_y() { return y; }
};

int main() {
    Point p{3.14, 2.71};
}
```


## Operator

