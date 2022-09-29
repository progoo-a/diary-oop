int main() {
    int u = 23;

    {
        int u = 42;
    }
    printf("%d\n", u); 
}