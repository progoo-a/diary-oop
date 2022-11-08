

class Prout {
    int value;
    public:
    Prout(int value) : value{value} {}
    Prout operator+(Prout &other) {
        return Prout(value + other.value);
    }
};


int main() {
    Prout a{1}, b{2};
    Prout c = a + b;
}

