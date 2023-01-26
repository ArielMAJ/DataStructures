#include <stdio.h>
#include <stdlib.h>

typedef struct Segment
{
    int start;
    int end;
} Segment;


int get_int_from_stdin();
int *get_array_from_stdin(int array_length);
Segment get_segment_from_stdin();
Segment *get_segment_array_from_stdin(int array_length);
int *naive_count_segments_per_point(Segment *segments, int amount_of_segments, int *points, int amount_of_points);

int main()
{
    int amount_of_segments = get_int_from_stdin();
    int amount_of_points = get_int_from_stdin();

    Segment *segments = get_segment_array_from_stdin(amount_of_segments);
    int *points = get_array_from_stdin(amount_of_points);

    int *segments_per_point = naive_count_segments_per_point(segments, amount_of_segments, points, amount_of_points);

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