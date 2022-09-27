

int add(int a, int b) {
    return a + b;
}

float add(float a, float b=42) { // valeur par défaut
    return a + b;
}

float add(float a) {
    return a * 42;
}

int main() {
    int a = 1;
    int b = 2;
    int c = add(a, b);  // int add(int, int)
    float d = add(a); // Ambiguïté
    return 0;
}