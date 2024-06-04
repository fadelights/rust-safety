int* bob() {
    int b = -3;
    int* p = (int*) malloc(sizeof(int));
    *p = b;
    return p;
}

int main() {
    int* c = bob(); // All good!
    return 0;
}
