
#include <stdio.h>
#include "linalg.h"


Vector2f Vector2f_plus(const Vector2f lhs, const Vector2f rhs)
{
    return (Vector2f){ .x = (lhs.x + rhs.x), .y = (lhs.y + rhs.y) };
}


Vector2f Vector2f_minus(const Vector2f lhs, const Vector2f rhs)
{
    return (Vector2f) { .x = (lhs.x - rhs.x), .y = (lhs.y - rhs.y) };
}


Vector2f Vector2f_scale(float lhs, const Vector2f rhs)
{
    return (Vector2f){ .x = (lhs * rhs.x), .y = (lhs * rhs.y) };
}


float Vector2f_dot(const Vector2f lhs, const Vector2f rhs)
{
    return (lhs.x * rhs.x) + (lhs.y * rhs.y);
}


int main() {

    #include <assert.h> // static_assert / _Static_assert

    {
        Vector2f const a = { .x = 1.0f, .y = 0.0f };
        Vector2f const b = { .x = 0.0f, .y = 1.0f };
        Vector2f const c = Vector2f_plus(a, b);

        printf("a + b = { x = %f, y = %f }\n", c.x, c.y);

        // static_assert((1.0 == 1.0f, "The v1 + v2 should be 1.0");
    }
    {
        Vector2f const a = { .x = 1.0f, .y = 0.0f };
        Vector2f const b = { .x = 0.0f, .y = 1.0f };
        Vector2f const c = Vector2f_minus(a, b);

        printf("a - b = { x = %f, y = %f }\n", c.x, c.y);
    }
    {
        const float f = 2.0f;
        Vector2f const a = { .x = 1.0f, .y = 0.0f };
        Vector2f const c = Vector2f_scale(f, a);

        printf("f * b = { x = %f, y = %f }\n", c.x, c.y);
    }

    return 0;
}