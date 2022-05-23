#include <stdio.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }
    int flag = 0;
    for (int col = 0; col < strlen(strs[0]); col++) {
        for (int row = 1; row < strsSize; row++) {
            if (strs[0][col] != strs[row][col]) {
                strs[0][col] = '\0';
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
    }
    return strs[0];
}

int main(int argc, char const *argv[]) {
    return 0;
}
