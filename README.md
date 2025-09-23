
int toto = 42; // Objet 
int tata = 23;

int unsigned int, long, unsigned long, long long, unsigned long long
char, unsigned char, short, unsigned short, float, double, long double
bool 

typedef struct person {
    char name[50];
    int age;
    int height;
} Person;

Person john = {"John Doe", 30, 175};

typedef struct circle {
    float radius;
    char color[20];

    Circle operator+(Circle other) {
        float area1 = 3.14 * radius * radius;
        float area2 = 3.14 * other.radius * other.radius;
        float totalArea = area1 + area2;
        float newRadius = sqrt(totalArea / 3.14);
        return Circle{newRadius, "mixed"};
    }
} Circle;

Circle a = {5.5, "red"};
Circle b = {3.2, "blue"};

Circle c = a + b;
Circle d = b + a;

toto + tata;



a = 2;
a := 2;
a == 2;
