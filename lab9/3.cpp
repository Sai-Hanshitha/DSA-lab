#include <stdio.h>

int findMin(int a, int b);

void processTestcase() {
    int n, q;
    scanf("%d %d", &n, &q);  

    int arr[n];  

    printf("Enter positions :");
    for (int i = 0; i < n; i++) {  
        scanf("%d", &arr[i]);
    }

    printf("Enter members in row :");
    while (q--) {
        int y;
        scanf("%d", &y);

     
        int result = findMin(arr[0] - 1, y);  
        printf("%d ", result); 
    }
}

int findMin(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}


int main() {
    int cases;
    printf("Enter no of test cases: ");  
    scanf("%d ", &cases);

    while (cases--) {
        processTestcase();
    }

    return 0;
}
