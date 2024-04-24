
// use special command for compiling 
// g++ -fopenmp filename.cpp -lm


#include <iostream>
#include <omp.h>
void merge(int arr[], int l, int m, int r) {
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
int L[n1], R[n2];
for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++)
R[j] = arr[m + 1 + j];
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
arr[k] = L[i];
i++;
}
else {
arr[k] = R[j];
j++;
}
k++;
}
while (i < n1) {
arr[k] = L[i];
i++;
k++;
}
while (j < n2) {
arr[k] = R[j];
j++;
k++;
}
}
void mergeSort(int arr[], int l, int r) {
if (l < r) {
int m = l + (r - l) / 2;
mergeSort(arr, l, m);
mergeSort(arr, m + 1, r);
merge(arr, l, m, r);

}
}
int main() {
int n;
std::cout << "Enter the number of elements: ";
std::cin >> n;
int arr[n];
std::cout << "Enter " << n << " elements: ";
for (int i = 0; i < n; i++)
std::cin >> arr[i];
std::cout << "Given array is: ";
for (int i = 0; i < n; i++)
std::cout << arr[i] << " ";
std::cout << std::endl;
double start = omp_get_wtime();
mergeSort(arr, 0, n - 1);
double stop = omp_get_wtime();
std::cout << "Sorted array is: ";
for (int i = 0; i < n; i++)
std::cout << arr[i] << " ";
std::cout << std::endl;
std::cout << "Time taken: " << stop - start << " seconds" << std::endl;
return 0;
}
