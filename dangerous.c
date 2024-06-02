/* Example demonstarting buffer overflow exploits.
Run the program without stack protection to make it simpler to exploit:

```
gcc -fno-stack-protector -z execstack -o dangerous.out dangerous.c
```

Relevant reads:
https://stackoverflow.com/questions/64972041/trying-to-call-a-hidden-function-with-a-buffer-overflow
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerable();
void secret();

int main() {
    vulnerable();
    return 0;
}

void vulnerable() {
    char buffer[64];
    printf("Enter some text:\n");
    gets(buffer);
    printf("You entered: %s\n", buffer);
}

void secret() {
    system("cat secret.txt");
}
