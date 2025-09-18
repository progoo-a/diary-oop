

struct Pokemon {
    char name[42];
    unsigned int life;
    unsigned int attack;
    unsigned int defense;

    void attack(Pokemon other) {
        other.life -= attack - other.defense;
    }
};

int main() {
    Pokemon pikachu = {"Pikachu", 100, 30, 32};
    Pokemon salameche = {"Salameche", 90, 29, 35};

    pikachu.attack(salameche);
}