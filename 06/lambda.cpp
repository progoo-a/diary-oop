#if 0
int add(int a, int b) { return a + b; }
#endif

int main() {
    //int i = add(1,2);
    int k = 42;
    int i = [&](int a, int b){ k += 2; return k * (a + b); }(1,2);
    // [&] Capture le contenu local par référence (modifie la valeur de k)
    // [=] Capture le contenu local par valeur (copie) (ne modifie pas la valeur de k)
    // [ ] Capture rien
}
