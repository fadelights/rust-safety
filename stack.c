int bob() {
    int a = 100;
    return a;
}

int main() {
    int a;
    int b = -3;
    int* p = &b;
    int c = bob();
    return 0;
}
