#include <stdio.h>
#include <assert.h> // static_assert

#include "linalg.h"


int main() {

/* ------------------------------------------------------------------------- */
{
    Vector2 const a = { .x = 1.0f, .y = 0.0f };
    Vector2 const b = { .x = 0.0f, .y = 1.0f };
    Vector2 const c = Vector2_plus(a, b);

    printf("a + b = { x = %f, y = %f }\n", c.x, c.y);

    // static_assert((1.0 == 1.0f, "The v1 + v2 should be 1.0");
}
{
    Vector2 const a = { .x = 1.0f, .y = 0.0f };
    Vector2 const b = { .x = 0.0f, .y = 1.0f };
    Vector2 const c = Vector2_minus(a, b);

    printf("a - b = { x = %f, y = %f }\n", c.x, c.y);
}
{
    const float f = 2.0f;
    Vector2 const a = { .x = 1.0f, .y = 0.0f };
    Vector2 const c = Vector2_scale(f, a);

    printf("f * b = { x = %f, y = %f }\n", c.x, c.y);
}
/* ------------------------------------------------------------------------- */
{
    Pair point = { .x = 1.f, .y = 2.f };
    printf("{ x = %f, y = %f }\n", point.x, point.y);
}
{
    Pair size = { .w = 1.f, .h = 2.f };
    printf("{ w = %f, h = %f }\n", size.w, size.h);
}
{
    // Pair values(1.f, 2.f);
    // printf("{ w = %f, h = %f }\n", values[0], values[1]);
}
/* ------------------------------------------------------------------------- */
{
    Triple point = { .x = 1.f, .y = 2.f, .z = 3.f };
    printf("{ x = %f, y = %f, z = %f }\n", point.x, point.y, point.z);
}
{
    Triple color = { .r = 0.1f, .g = 0.5f, .b = 0.9f };
    printf("{ r = %f, g = %f, b = %f }\n", color.r, color.g, color.b);
}
{
    Triple size = { .w = 1.f, .h = 2.f, .d = 3.f };
    printf("{ w = %f, h = %f, d = %f }\n", size.w, size.h, size.d);

}
/* ------------------------------------------------------------------------- */
{
    Quadruple point = { .x = 1.0, .y = 2.f, .z = 3.f, .w = 1.0f };
    printf("{ x = %f, y = %f, z = %f, w = %f }\n", point.x, point.y, point.z, point.w);
}
{
    Quadruple color = { .r = 1.0, .g = 2.f, .b = 3.f, .a = 1.0f };
    printf("{ r = %f, g = %f, b = %f, a = %f }\n", color.x, color.y, color.z, color.w);
}

    return 0;
}