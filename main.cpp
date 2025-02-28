#include <iostream>

// ������� ��� ������� ���� ��������������� ��������
void merge(int* arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // ������� ��������� �������
    int* L = new int[n1];
    int* R = new int[n2];

    // �������� ������ �� ��������� �������
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    // ������� ��������� �������� ������� � arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // �������� ���������� �������� L[], ���� ��� ����
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // �������� ���������� �������� R[], ���� ��� ����
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // ����������� ������
    delete[] L;
    delete[] R;
}

// ����������� ������� ��� ���������� ��������
void merge_sort(int* arr, int left, int right)
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        // ��������� ������ � ������ ��������
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // ������� ��������������� ��������
        merge(arr, left, mid, right);
    }
}

// �������� ������� ��� ���������� ��������
void merge_sort(int* arr, int size)
{
    merge_sort(arr, 0, size - 1);
}

// ������� ��� ������ ������� �� �����
void print_array(int* arr, int size)
{
    for (int i = 0; i < size; i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    setlocale(LC_ALL, "rus");
    // �������� �������
    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    // ������� ��������
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    // ���������� � ����� �����������
    std::cout << "�������� ������ 1: ";
    print_array(arr1, size1);
    merge_sort(arr1, size1);
    std::cout << "��������������� ������ 1: ";
    print_array(arr1, size1);
    std::cout << std::endl;
    
    std::cout << "�������� ������ 2: ";
    print_array(arr2, size2);
    merge_sort(arr2, size2);
    std::cout << "��������������� ������ 2: ";
    print_array(arr2, size2);
    std::cout << std::endl;

    std::cout << "�������� ������ 3: ";
    print_array(arr3, size3);
    merge_sort(arr3, size3);
    std::cout << "��������������� ������ 3: ";
    print_array(arr3, size3);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}