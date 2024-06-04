int* bob() {
    int b = -3;
    int* p = &b;
    return p;
}

int main() {
    int a;
    int* c = bob(); // Uh oh ...
    return 0;
}
