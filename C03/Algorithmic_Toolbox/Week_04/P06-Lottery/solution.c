#include <stdio.h>
#include <stdlib.h>

typedef struct Segment
{
    int start;
    int end;
} Segment;

int LEFT_MOST = 0;
int RIGHT_MOST = 1;

int get_int_from_stdin();
int *get_array_from_stdin(int array_length);
Segment get_segment_from_stdin();
Segment *get_segment_array_from_stdin(int array_length);
void printSegArray(Segment *seg_array, int seg_array_size);
int *naive_count_segments_per_point(Segment *segments, int amount_of_segments, int *points, int amount_of_points);

void quicksort(Segment *array, int array_length);
void _quicksort(Segment *array, int array_length, int left, int right);
int *partition3(Segment *array, int left, int right);
void swap(Segment *first_value, Segment *second_value);

int *count_segments_per_point(Segment *segments, int amount_of_segments, int *points, int amount_of_points);

int main()
{
    int amount_of_segments = get_int_from_stdin();
    int amount_of_points = get_int_from_stdin();

    Segment *segments = get_segment_array_from_stdin(amount_of_segments);
    int *points = get_array_from_stdin(amount_of_points);

    int *segments_per_point = count_segments_per_point(segments, amount_of_segments, points, amount_of_points);

    for (int i = 0; i < amount_of_points; ++i)
        printf("%d ", segments_per_point[i]);
    printf("\n");

    free(segments);
    free(points);
    free(segments_per_point);
    return 0;
}

int *naive_count_segments_per_point(Segment *segments, int amount_of_segments, int *points, int amount_of_points)
{
    int *segments_per_point = (int *) calloc(amount_of_points, sizeof(int));

    for (int i = 0; i < amount_of_points; ++i)
        for (int j = 0; j < amount_of_segments; ++j)
            if (points[i] >= segments[j].start && points[i] <= segments[j].end)
                segments_per_point[i]++;
    return segments_per_point;
}

int *count_segments_per_point(Segment *segments, int amount_of_segments, int *points, int amount_of_points)
{
    amount_of_segments *= 2;
    Segment pts[amount_of_points];
    Segment seg[amount_of_segments];

    for (int i = 0; i < amount_of_points; i++)
    {
        pts[i].start = points[i];
        pts[i].end = i;
    }

    for (int i = 0; i < amount_of_segments; i++, i++)
    {
        seg[i].start = segments[i / 2].start;
        seg[i].end = 1;
        seg[i + 1].start = segments[i / 2].end + 1;
        seg[i + 1].end = -1;
    }

    quicksort(seg, amount_of_segments);
    quicksort(pts, amount_of_points);

    int count = 0;
    int *segments_per_point = (int *) calloc(amount_of_points, sizeof(int));

    Segment *seg_aux = seg;
    for (int i = 0; i < amount_of_points; i++)
    {
        int x = pts[i].start;

        while (amount_of_segments > 0 && seg_aux[0].start <= x)
        {
            count += (seg_aux++)->end;
            amount_of_segments--;
        }
        segments_per_point[pts[i].end] = count;
    }

    return segments_per_point;
}

int get_int_from_stdin()
{
    int value;
    scanf("%d", &value);

    return value;
}

Segment get_segment_from_stdin()
{
    Segment segment;
    scanf("%d", &segment.start);
    scanf("%d", &segment.end);
    return segment;

}

int *get_array_from_stdin(int array_length)
{
    int *array = (int *) malloc(array_length * sizeof(int));
    int *aux = array;
    while (array_length--)
        scanf("%d", aux++);
    return array;
}

Segment *get_segment_array_from_stdin(int array_length)
{
    Segment *segment_array = (Segment *) malloc(array_length * sizeof(Segment));
    Segment *aux = segment_array;
    while (array_length--)
        *(aux++) = get_segment_from_stdin();
    return segment_array;
}

void quicksort(Segment *array, int array_length)
{
    _quicksort(array, array_length, 0, array_length - 1);
}

void _quicksort(Segment *array, int array_length, int left, int right)
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

int *partition3(Segment *array, int left, int right)
{
    int pivot_position = left + (right - left) / 2;
    int pivot = array[pivot_position].start;
    swap(&array[left], &array[pivot_position]);

    int *middle = (int *) malloc(2 * sizeof(int));

    middle[LEFT_MOST] = left;
    middle[RIGHT_MOST] = left;

    for (int i = left + 1; i <= right; ++i)
    {
        if (array[i].start == pivot)
        {
            middle[RIGHT_MOST]++;
            swap(&array[middle[RIGHT_MOST]], &array[i]);
        }
        if (array[i].start < pivot)
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

void swap(Segment *first_value, Segment *second_value)
{
    Segment tmp_value = *first_value;
    *first_value = *second_value;
    *second_value = tmp_value;
}

void printSegArray(Segment *seg_array, int seg_array_size)
{
    for (int i = 0; i < seg_array_size; ++i)
        printf("%d %d\n", seg_array[i].start, seg_array[i].end);
}
