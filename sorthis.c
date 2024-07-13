#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// The number of sorting ways
#define WAYS 3

// Function prototypes
void selection_sort(int array[], int length);
void bubble_sort(int array[], int length);
void merge_sort(int array[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);

int main(int argc, string argv[])
{
    // The index array - ***change what you want to sort here***
    int index[] = {5, 7, 2, 9, 1, 4, 3, 6, 8};

    // Calculates the length of the index array
    int index_count = sizeof(index) / sizeof(index[0]);

    // Creating necessary parameters
    string sorting_type = argv[1];
    string sorting_type_storage[WAYS] = {"selection", "bubble", "merge"};

    // Check for invalid usage
    // Check if user inputs more than one parameter
    if (argc > 2)
    {
        printf("Usage: ./sort method(can use only one type of sorting)\n");
        return 1;
    }
    else if (argc < 2)
    {
        printf("Usage: ./sort method(type: selection/bubble/merge)\n");
        return 2;
    }
    // Check for invalid usage
    // Check if user inputs in upper cases
    for (int i = 0; sorting_type[i] != '\0'; i++)
    {
        if (isupper(sorting_type[i]))
        {
            printf("Usage: ./sort method(write only in lower cases)\n");
            return 3;
        }
    }
    // Check for invalid usage
    // Check if user inputs something that is not one of the sorting methods
    for (int i = 0; i < WAYS; i++)
    {
        if (strcmp(sorting_type, sorting_type_storage[i]) == 0)
        {
            break;
        }
        else if (i == WAYS - 1)
        {
            printf("Usage: ./sort method(selection/bubble/merge)\n");
            return 4;
        }
    }

    // Solving the index based on the user's input of method
    if (strcmp(sorting_type, "selection") == 0)
    {
        selection_sort(index, index_count);
    }
    else if (strcmp(sorting_type, "bubble") == 0)
    {
        bubble_sort(index, index_count);
    }
    else if (strcmp(sorting_type, "merge") == 0)
    {
        merge_sort(index, index_count);
    }

    // Prints the index array
    for (int i = 0; i < index_count; i++)
    {
        if (i == index_count - 1)
        {
            printf("%i", index[i]);
        }
        else
        {
            printf("%i, ", index[i]);
        }
    }
    printf("\n");
    return 0;
}

// Sorting index by selection sort
void selection_sort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int min_position = i;
        for (int j = i + 1; j < length; j++)
        {
            if (array[min_position] > array[j])
            {
                min_position = j;
            }
        }
        if (min_position != i)
        {
            int store_trmp = array[i];
            array[i] = array[min_position];
            array[min_position] = store_trmp;
        }
    }
    return;
}

// Sorting index by bubble sort
void bubble_sort(int array[], int length)
{
    int swap_count = 1;
    while (swap_count != 0)
    {
        swap_count = 0;
        for (int i = 0; i < length - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                int store_trmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = store_trmp;
                swap_count++;
            }
        }
        length--;
    }
    return;
}

// I used this article to solve this - https://www.geeksforgeeks.org/c-program-for-merge-sort/
// Sorting index by merge sort
// Determines what's the left and right of index
void merge_sort(int array[], int length)
{
    merge_sort_recursion(array, 0, length - 1);
    return;
}

// Sorting index by bubble sort
// Divides in the middle and creates more arrays till it's one parameter
void merge_sort_recursion(int a[], int l, int r)
{
    if (l != r)
    {
        int m = l + (r - l) / 2;

        merge_sort_recursion(a, l, m);
        merge_sort_recursion(a, m + 1, r);

        merge_sorted_arrays(a, l, m, r);
    }
    return;
}

// Sorting index by bubble sort
// Merge the two arrays
void merge_sorted_arrays(int a[], int l, int m, int r)
{
    int left_length = m - l + 1;
    int right_length = r - m;
    int i, j, k;

    int temp_left[left_length];
    int temp_right[right_length];

    for (i = 0; i < left_length; i++)
    {
        temp_left[i] = a[l + i];
    }
    for (j = 0; j < right_length; j++)
    {
        temp_right[j] = a[m + 1 + j];
    }

    i = 0, j = 0, k = l;

    while (i < left_length && j < right_length)
    {
        if (temp_left[i] <= temp_right[j])
        {
            a[k] = temp_left[i];
            i++;
        }
        else
        {
            a[k] = temp_right[j];
            j++;
        }
        k++;
    }

    while (i < left_length)
    {
        a[k] = temp_left[i];
        i++;
        k++;
    }
    while (j < right_length)
    {
        a[k] = temp_right[j];
        j++;
        k++;
    }
    return;
}
