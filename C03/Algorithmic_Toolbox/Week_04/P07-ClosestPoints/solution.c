#include <stdio.h>
#include <stdlib.h>

typedef struct Point
{
    int x;
    int y;
} Point;

int LEFT_MOST = 0;
int RIGHT_MOST = 1;

int get_int();
Point get_point();
Point *get_points_array(int array_length);
void print_points_array(Point *points_array, int points_array_size);

void quicksort(Point *array, int array_length);
void _quicksort(Point *array, int array_length, int left, int right);
int *partition3(Point *array, int left, int right);
void swap(Point *first_value, Point *second_value);

double minimal_distance(Point *points_array, int points_array_size);

int main()
{
    int amount_of_points = get_int();
    Point *points = get_points_array(amount_of_points);

    printf("---------------\n");
    print_points_array(points, amount_of_points);
    printf("---------------\n");
    quicksort(points, amount_of_points);
    print_points_array(points, amount_of_points);
    printf("---------------\n");

    free(points);
    return 0;
}

double minimal_distance(Point *points_array, int points_array_size)
{
    // TODO
}

int get_int()
{
    int value;
    scanf("%d", &value);

    return value;
}

Point get_point()
{
    Point point;
    scanf("%d", &point.x);
    scanf("%d", &point.y);
    return point;

}

Point *get_points_array(int array_length)
{
    Point *point_array = (Point *) malloc(array_length * sizeof(Point));
    Point *aux = point_array;
    while (array_length--)
        *(aux++) = get_point();
    return point_array;
}

void print_points_array(Point *points_array, int points_array_size)
{
    for (int i = 0; i < points_array_size; ++i)
        printf("%d %d\n", points_array[i].x, points_array[i].y);
}

void quicksort(Point *array, int array_length)
{
    _quicksort(array, array_length, 0, array_length - 1);
}

void _quicksort(Point *array, int array_length, int left, int right)
{
    while (left < right)
    {
        int *middle = partition3(array, left, right);
        if (middle[LEFT_MOST] - left < right - middle[RIGHT_MOST])
        {
            _quicksort(array, array_length, left, middle[LEFT_MOST] - 1);
            left = middle[RIGHT_MOST] + 1;
        }
        else
        {
            _quicksort(array, array_length, middle[RIGHT_MOST] + 1, right);
            right = middle[LEFT_MOST] - 1;
        }
        free(middle);
    }
}

int *partition3(Point *array, int left, int right)
{
    int pivot_position = left + (right - left) / 2;
    int pivot = array[pivot_position].x;
    swap(&array[left], &array[pivot_position]);

    int *middle = (int *) malloc(2 * sizeof(int));

    middle[LEFT_MOST] = left;
    middle[RIGHT_MOST] = left;

    for (int i = left + 1; i <= right; ++i)
    {
        if (array[i].x == pivot)
        {
            middle[RIGHT_MOST]++;
            swap(&array[middle[RIGHT_MOST]], &array[i]);
        }
        if (array[i].x < pivot)
        {
            middle[LEFT_MOST]++;
            middle[RIGHT_MOST]++;
            swap(&array[middle[RIGHT_MOST]], &array[i]);
            swap(&array[middle[LEFT_MOST]], &array[middle[RIGHT_MOST]]);
        }
    }
    swap(&array[left], &array[middle[LEFT_MOST]]);
    return middle;
}

void swap(Point *first_value, Point *second_value)
{
    Point tmp_value = *first_value;
    *first_value = *second_value;
    *second_value = tmp_value;
}
