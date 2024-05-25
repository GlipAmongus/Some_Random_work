#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void extremePoints(int const PTS[], size_t capacity);

int main(void)
{
    const int N = 4;

    //unique seed value
    srand(time(NULL));

    int points[N];

    //Populate array. Duplicate values allowed since not enforced otherwise
    for(int i = 0; i < N; i++)
        points[i] = rand() % 10;
    
    //Extreme points
    extremePoints(points, N);

    exit(0);
}

void extremePoints(int const PTS[], size_t capacity)
{
    int count = 0;  //counter of extreme points

    printf("Array:\n");
    for(int i = 0; i < capacity; i++)
        printf("%d, ", PTS[i]);

    for(int i = 1; i < capacity-1; i++)
    {
        if(((PTS[i-1] < PTS[i]) && (PTS[i] > PTS[i+1])) || ((PTS[i - 1] > PTS[i]) && (PTS[i] < PTS[i + 1])))
        {
            if(count == 0)
                printf("\n\nExtreme points:\n");

            printf("%i, ", PTS[i]);
            count++;
        }
    }

    //Print SORTED when no extreme points are found
    if(count == 0)
        printf("\n\nSORTED\n");
}
