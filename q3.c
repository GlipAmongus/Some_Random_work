#include <stdlib.h>
#include <stdio.h>

/*
 * An array has no extreme points if and only if it is sorted is false
 * since there exists a case where the array has no extreme points, and is not sorted:
 * [1, 5, 5, 1].
 * */

/*
 * Although in the case where an array is sorted [1,2,3,4,5] or inversely [5,4,3,2,1]
 * it does not contain any extreme points.
 * Thus, in the absence of extreme points and duplicates the array is sorted.
 * */

void extremePoints(int const PTS[], size_t capacity);

int main(void)
{
    const int N = 256;

    int points[N];

    //Populate array. Duplicate values allowed since not enforced otherwise
    for(int i = 0; i < N; i++)
        points[i] = rand() % N;
    
    //Extreme points
    extremePoints(points, N);

    exit(0);
}

void extremePoints(int const PTS[], size_t capacity)
{
    int count = 0;  //counter of extreme points

    for(int i = 1; i < capacity-1; i++)
    {
        if(((PTS[i-1] < PTS[i]) && (PTS[i] > PTS[i+1])) || ((PTS[i - 1] > PTS[i]) && (PTS[i] < PTS[i + 1])))
        {
            printf("%i, ", PTS[i]);
            count++;
        }
    }

    //Print SORTED when no extreme points are found
    if(count == 0)
        printf("SORTED\n");
}
