// ADT Abstract Data Type

// Library
struct vector {
    int capacity;
    int size;
    int *data;
}

// Header
typedef struct vector Vector;

void vector_init(Vector **vector);
void vector_push_back(Vector *vector, int value);

// Main
int main() {
    Vector *v;
    vector_init(&v);
    vector_push_back(v, 42);
}