#include <stdio.h>

void findTwoLargest(int arr[], int n, int result[]) {
    int max1 = 0, max2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } 
        else if (arr[i] > max2) {
            max2 = arr[i];
        }
    }

    result[0] = max1;
    result[1] = max2;
}


void solve() {
    int n;
    scanf("%d", &n);

    int s[n], result[2];
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    findTwoLargest(s, n, result);
    int max1 = result[0], max2 = result[1];

    for (int i = 0; i < n; i++) {
        if (s[i] == max1) {
            printf("%d ", s[i] - max2);
        } else {
            printf("%d ", s[i] - max1);
        }
    }
    printf("\n");
}

int main() {
    int test_cases;
    scanf("%d", &test_cases);

    while (test_cases--) {
        solve();
    }

    return 0;
}
