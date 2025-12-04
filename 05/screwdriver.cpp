
class Screwdriver;

struct Bit {
    Screwdriver &sc;
    Bit(Screwdriver &sc);
    int whatIsMyScrewdriverId();
    void use();
};

struct Screwdriver {
    Bit bit;
    int id();
    void use();
};

Bit::Bit(Screwdriver &sc) : sc(sc) {}
int Bit::whatIsMyScrewdriverId() { return sc.id(); }
void Bit::use() {}

void Screwdriver::use() { bit.use(); }
int Screwdriver::id() { return 42; }