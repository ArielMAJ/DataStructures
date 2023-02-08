#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
double points_dist(Point point_one, Point point_two);
int x_sort(Point point);
int y_sort(Point point);

void quicksort(Point *array, int array_length, int (*key)(Point));
void _quicksort(Point *array, int array_length, int left, int right, int (*key)(Point));
int *partition3(Point *array, int left, int right, int (*key)(Point));
void swap(Point *first_value, Point *second_value);

double minimal_distance(Point *points_array, int points_array_size);
double _minimal_distance(Point *points_array, int start, int end);

int main()
{
    int array_length = get_int();
    Point *points_array = get_points_array(array_length);

    double result = minimal_distance(points_array, array_length);
    printf("%.10lf\n", result);

    free(points_array);
    return 0;
}

double minimal_distance(Point *points_array, int points_array_size)
{
    quicksort(points_array, points_array_size, x_sort);
    return sqrt(_minimal_distance(points_array, 0, points_array_size - 1));
}

double _minimal_distance(Point *points_array, int start, int end)
{
    if (start + 1 == end)
        return points_dist(points_array[start], points_array[end]);

    int middle_position = start + (end - start) / 2;

    double left_dist = _minimal_distance(points_array, start, middle_position);
    double right_dist = _minimal_distance(points_array, middle_position, end);

    double lower_dist = right_dist;
    if (left_dist < lower_dist)
        lower_dist = left_dist;

    if (lower_dist < 0.00001)
        return lower_dist;

    int middle_line = points_array[middle_position].x;

    int left_point_pos = middle_position - 1;
    while (left_point_pos > start && middle_line - points_array[left_point_pos].x < lower_dist)
        left_point_pos--;
    if (middle_line - points_array[left_point_pos].x >= lower_dist )
        left_point_pos++;

    int right_point_pos = middle_position + 1;
    while (right_point_pos < end && points_array[right_point_pos].x - middle_line < lower_dist)
        right_point_pos++;
    if (points_array[right_point_pos].x - middle_line >= lower_dist )
        right_point_pos--;

    int y_sorted_size = right_point_pos + 1 - left_point_pos;
    Point y_sorted_points[y_sorted_size];
    for (int i = 0; i < y_sorted_size; ++i)
        y_sorted_points[i] = points_array[left_point_pos + i];

    quicksort(y_sorted_points, y_sorted_size, y_sort);

    for (int i = 0; i < y_sorted_size - 1; ++i)
    {
        for (int j = i + 1; (y_sorted_points[j].y - y_sorted_points[i].y < lower_dist) && (j < y_sorted_size) && (j <= i + 7); ++j)
        {
            double new_dist = points_dist(y_sorted_points[i], y_sorted_points[j]);
            if (new_dist < lower_dist)
            {
                lower_dist = new_dist;
                if (lower_dist < 0.00001)
                    return lower_dist;
            }
        }
    }
    return lower_dist;
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

double points_dist(Point point_one, Point point_two)
{
    return pow(point_two.x - point_one.x, 2) + pow(point_two.y - point_one.y, 2);
}

void quicksort(Point *array, int array_length, int (*key)(Point))
{
    _quicksort(array, array_length, 0, array_length - 1, key);
}

void _quicksort(Point *array, int array_length, int left, int right, int (*key)(Point))
{
    while (left < right)
    {
        int *middle = partition3(array, left, right, key);
        if (middle[LEFT_MOST] - left < right - middle[RIGHT_MOST])
        {
            _quicksort(array, array_length, left, middle[LEFT_MOST] - 1, key);
            left = middle[RIGHT_MOST] + 1;
        }
        else
        {
            _quicksort(array, array_length, middle[RIGHT_MOST] + 1, right, key);
            right = middle[LEFT_MOST] - 1;
        }
        free(middle);
    }
}

int *partition3(Point *array, int left, int right, int (*key)(Point))
{
    int pivot_position = left + (right - left) / 2;
    int pivot = (*key)(array[pivot_position]);
    swap(&array[left], &array[pivot_position]);

    int *middle = (int *) malloc(2 * sizeof(int));

    middle[LEFT_MOST] = left;
    middle[RIGHT_MOST] = left;

    for (int i = left + 1; i <= right; ++i)
    {
        if ((*key)(array[i]) == pivot)
        {
            middle[RIGHT_MOST]++;
            swap(&array[middle[RIGHT_MOST]], &array[i]);
        }
        if ((*key)(array[i]) < pivot)
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

int x_sort(Point point)
{
    return point.x;
}

int y_sort(Point point)
{
    return point.y;
}
