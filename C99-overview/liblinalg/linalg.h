#ifndef LINALG_H
#define LINALG_H


typedef struct Vector2f { float x; float y; } Vector2f;

#define VECTOR2F_STR "Vector2f(x = %.2f, y =  %.2f)\n"


typedef struct Vector3f { float x; float y; float z; } Vector3f;

#define VECTOR3F_STR "Vector3f(x = %.2f, y =  %.2f, z = %.2f)\n"


typedef struct Vector4f { float x; float y; float z; float w; } Vector4f;
#define VECTOR4F_STR "Vector4f(x = %.2f, y =  %.2f, z = %.2f, w = %.2f)\n"


Vector2f Vector2f_plus(const Vector2f lhs, const Vector2f rhs);


Vector2f Vector2f_minus(const Vector2f lhs, const Vector2f rhs);


Vector2f Vector2f_scale(float lhs, const Vector2f rhs);


float Vector2f_dot(const Vector2f lhs, const Vector2f rhs);


#endif // LINALG_H