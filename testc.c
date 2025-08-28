// gcc -std=c17 -Wall -Wextra -O0 demo_fgets.c -o demo_fgets
#include <stdio.h>
#include <string.h>

int main(void){
    char line[256];
    while (1) {
        fputs("> ", stdout); fflush(stdout);
        char *p = fgets(line, sizeof line, stdin);
        if (!p) { puts("[EOF]"); break; }
        // 개행 유무 표시
        size_t len = strlen(line);
        int has_nl = len && line[len-1] == '\n';
        printf("len=%zu, newline=%s, text=[%s]%s",
               len, has_nl ? "yes" : "no", line, has_nl ? "" : "\n");
    }
}
