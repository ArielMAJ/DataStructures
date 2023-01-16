#include <stdio.h>
#include <stdlib.h>

typedef struct Segment
{
    int start;
    int end;
} Segment;


void read_from_stdin(int *value);
void populate_array(Segment *segments, int amount_of_segments);
void alloc_space(Segment **segments, int amount_of_segments);

void swap(Segment *first_value, Segment *second_value);
void selection_sort(Segment *segments, int amount_of_segments);

int *optimal_points(Segment *sorted_segments, int amount_of_segments, int *amount_of_points);

int main()
{
    int amount_of_segments;
    read_from_stdin(&amount_of_segments);

    Segment *segments = NULL;
    alloc_space(&segments, amount_of_segments);
    populate_array(segments, amount_of_segments);

    selection_sort(segments, amount_of_segments);

    int amount_of_points = 0;
    int *points = optimal_points(segments, amount_of_segments, &amount_of_points);

    printf("%d\n", amount_of_points);
    for (int i = 0; i < amount_of_points; ++i)
        printf("%d ", points[i]);

    if (segments != NULL)
        free(segments);
    if (points != NULL)
        free(points);
    return 0;
}

int *optimal_points(Segment *sorted_segments, int amount_of_segments, int *amount_of_points)
{

    int *points = (int *) calloc(amount_of_segments, sizeof(int));
    int last_point = sorted_segments[0].end;
    points[0] = last_point;
    (*amount_of_points)++;

    for (int i = 0; i < amount_of_segments; ++i)
    {
        if (sorted_segments[i].start > last_point)
        {
            last_point = sorted_segments[i].end;
            points[*amount_of_points] = last_point;
            (*amount_of_points)++;
        }
    }
    return points;
}

void read_from_stdin(int *value)
{
    scanf("%d", value);
}

void populate_array(Segment *segments, int amount_of_segments)
{
    for (int i = 0; i < amount_of_segments; i++)
        scanf("%d %d", &(segments[i].start), &(segments[i].end));
}

void alloc_space(Segment **segments, int amount_of_segments)
{
    if (amount_of_segments > 0)
    {
        *segments = (Segment *) malloc(amount_of_segments * sizeof(Segment));

        if (*segments == NULL)
        {
            printf("Failed to alloc space.\n");
            exit(1);
        }
    }
}

void selection_sort(Segment *segments, int amount_of_segments)
{
    for (int i_left_pos = 0; i_left_pos < amount_of_segments - 1; ++i_left_pos)
    {
        int min_index = i_left_pos;
        for (int j_right_pos = i_left_pos + 1; j_right_pos < amount_of_segments; ++j_right_pos)
            if (segments[j_right_pos].end < segments[min_index].end)
                min_index = j_right_pos;
        swap(&segments[i_left_pos], &segments[min_index]);
    }
}

void swap(Segment *first_value, Segment *second_value)
{
    Segment temp_var = *first_value;
    *first_value = *second_value;
    *second_value = temp_var;
}
