#include <stdio.h>
#include <omp.h>

int main() {

    int n, i;
    int sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    #pragma omp parallel num_threads(2)
    {
        int local_sum = 0;
        int thread_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();

        for(i = thread_id; i < n; i += total_threads) {
            local_sum += arr[i];
        }

        printf("Thread %d partial sum = %d\n", thread_id, local_sum);

        #pragma omp atomic
        sum += local_sum;
    }

    printf("Final Sum = %d\n", sum);

    return 0;
}
