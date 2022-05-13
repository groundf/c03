#include <stdio.h>


struct Vector2f { float x; float y; };

#define VECTOR2F_FMT "Vector2f(x = %.2f, y =  %.2f)\n"

// struct Vector3f { float x; float y; float z; };

#define VECTOR3F_FMT "Vector3f(x = %.2f, y =  %.2f, z = %.2f)\n"

// typedef struct Vector3f Vector3f;

// Také můžeme alias provést takto:
typedef struct Vector3f { float x; float y; float z; } Vector3f;
//     ^^^^^^^^ structure name                 ^^^^^^^^ structure alias


int main() {
    // [1]
    struct Vector2f v1;
    v1.x = 1.0f;
    v1.y = 0.0f;
    printf(VECTOR2F_FMT, v1.x, v1.y);

    // [2]
    struct Vector2f v2 = { .x = 1.0f, .y = 0.0f };
    printf(VECTOR2F_FMT, v2.x, v2.y);

    // [3]
    struct Vector2f v3 = { .x = 1.0f };
    printf(VECTOR2F_FMT, v3.x, v3.y);

    // [4]
    struct Vector2f v4 = { .x = 1.0f };
    printf(VECTOR2F_FMT, v4.x, v4.y);

    // [5]
    struct Vector3f v5 = { .x = 10.0f, .y = 20.0f};
    printf(VECTOR3F_FMT, v5.x, v5.y, v5.z);

    // Můžeme prohodit pořadí pojmenovaných atributů.
    struct Vector3f v6 = { .z = 3.0f, .y = 2.0f, .x = 1.0f };
    printf(VECTOR3F_FMT, v6.x, v6.y, v6.z);

    // Můžeme jakýkoli pojmenovaný atribut vynechat.
    struct Vector3f v7 = { .z = 1.0f, };
    printf(VECTOR3F_FMT, v7.x, v7.y, v7.z);

    /* END */

    return 0;
}
