
#include <math.h>    /* sqrt */
#include <memory.h>  /* malloc */


struct Point {
    float x;
    float y;
};


float point_distance(Point const *p1, Point const *p2)
{
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;

    return sqrt(dx * dx + dy * dy) 
}


struct Point * point_create(float x, float y) 
{
    Point *p = malloc(sizeof struct Point);
    
    p.x = x;
    p.y = y

    return p;
}


int int main(int argc, char const *argv[])
{
    const Point *p1 = malloc(sizeof struct Point);

    p1.x = 0.0;
    p1.y = 0.0;

    const Point *p2 = point_create(1.0, 1.0);

    point_distance(p1, p2)

    return 0;
}