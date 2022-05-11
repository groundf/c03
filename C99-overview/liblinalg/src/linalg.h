#ifndef LINALG_H
#define LINALG_H

/*
 * -------------------------------------------------------------------------
 *
 * Mathematical types and funcctions to work with vector, matrix, quaternion.
 *
 * -------------------------------------------------------------------------
 */

#define GOF_MIN(x, y) ((x) > (y) ? (y) : (x))
#define GOF_MAX(x, y) ((x) < (y) ? (y) : (x))
#define GOF_ABS(x) ((x) > 0 ? (x) : -(x))
#define GOF_SQR(x) ((x) * (x))

/* ------------------------------------------------------------------------- */

typedef union Vector2 {
    struct { float x; float y; };
} Vector2;

#define VECTOR2_STR "Vector2(x = %.2f, y =  %.2f)\n"

Vector2 Vector2_plus(const Vector2 this, const Vector2 that);


Vector2 Vector2_minus(const Vector2 this, const Vector2 that);


Vector2 Vector2_scale(float scalar, const Vector2 vector);


Vector2 Vector2_invert(const Vector2 vector);


float Vector2_dot(const Vector2 this, const Vector2 that);

/* ------------------------------------------------------------------------- */

typedef union Vector3 {
    struct { float x; float y; float z; };
} Vector3;


#define VECTOR3F_STR "Vector3(x = %.2f, y =  %.2f, z = %.2f)\n"


Vector3 Vector3_plus(const Vector3 this, const Vector3 that);


Vector3 Vector3_minus(const Vector3 this, const Vector3 that);


Vector3 Vector3_scale(float scalar, const Vector3 this);


Vector3 Vector3_invert(const Vector3 this);


float Vector3_dot(const Vector3 this, const Vector3 that);


/* ------------------------------------------------------------------------- */

typedef struct Vector4 { float x; float y; float z; float w; } Vector4;
#define VECTOR4F_STR "Vector4(x = %.2f, y =  %.2f, z = %.2f, w = %.2f)\n"

/* ------------------------------------------------------------------------- */

typedef struct Matrix2 {

    float rows[];

} Matrix2;

/* ------------------------------------------------------------------------- */

typedef struct RGB {
    float r, g, b;
} RGB;


typedef struct HSL {
    float h, s, l;
} HSL;


typedef struct HSB {
    float h, s, b;
} HSB;

/* ------------------------------------------------------------------------- */

typedef union Pair {
    struct { float x, y; }; // point
    struct { float w, h; }; // size
    float values[2];
} Pair;


typedef union Triple {
    struct { float x, y, z; }; // point
    struct { float r, g, b; }; // color
    struct { float w, h, d; }; // size
    float values[3];
} Triple;


typedef union Quadruple {
    struct { float x, y, z, w; }; // point
    struct { float r, g, b, a; }; // color
    float values;
} Quadruple;


#endif // LINALG_H