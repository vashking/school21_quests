#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_valid_input(char *input) {
    for (int i = 0; i < strlen(input); ++i) {
        if (!isdigit(input[i])) {
            return 0;
        }
    }
    
    int n = atoi(input);
    return n > 0;
}

void generate_spiral_matrix(int n, int matrix[n][n]) {
    int dx = 0, dy = 1;  // Initial direction (right)
    int x = 0, y = 0;    // Starting point

    for (int i = 0; i < n * n; i++) {
        matrix[x][y] = i;
        // Compute the next cell
        int nx = x + dx, ny = y + dy;
        // Change direction if we hit the boundary or a filled cell
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || matrix[nx][ny] != 0) {
            int temp = dx;
            dx = dy;
            dy = -temp;  // Turn counterclockwise
            nx = x + dx;
            ny = y + dy;
        }
        // Move to the next cell
        x = nx;
        y = ny;
    }
}

void print_matrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", matrix[i][j]);
        }
        if (i < n - 1) {
            printf("\n");
        }
    }
}

int main() {
    char input[20];
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("n/ a");
        return 0;
    }
    
    input[strcspn(input, "\n")] = 0;

    if (!is_valid_input(input)) {
        printf("n/ a");
        return 0;
    }

    int n = atoi(input);
    int matrix[n][n];
    memset(matrix, 0, sizeof(matrix));

    generate_spiral_matrix(n, matrix);
    print_matrix(n, matrix);

    return 0;
}
