#include <stdio.h>
#include <string.h>

#define MAX_N 100000

int a[MAX_N];
int temp[MAX_N];

long long merge_sort(int arr[], int l, int r) {
    if (l >= r) return 0;

    int mid = (l + r) / 2;
    long long inv_count = 0;

    inv_count += merge_sort(arr, l, mid);
    inv_count += merge_sort(arr, mid + 1, r);

    int i = l, j = mid + 1, k = l;

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // 所有左邊剩下的都比它大
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= r)   temp[k++] = arr[j++];

    for (int x = l; x <= r; x++) {
        arr[x] = temp[x];
    }

    return inv_count;
}

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        long long moves = merge_sort(a, 0, n - 1);

        if (moves % 2 == 0) {
            printf("Carlos %lld\n", moves);
        } else {
            printf("Marcelo %lld\n", moves);
        }
    }

    return 0;
}
