#include <stdio.h>
#include <math.h>

#include "linalg.h"

/* ------------------------------------------------------------------------- */

Vector2 Vector2_plus(const Vector2 this, const Vector2 that)
{
    return (Vector2){ .x = (this.x + that.x), .y = (this.y + that.y) };
}

Vector2 Vector2_minus(const Vector2 this, const Vector2 that)
{
    return (Vector2) { .x = (this.x - that.x), .y = (this.y - that.y) };
}

Vector2 Vector2_scale(float scalar, const Vector2 vector)
{
    return (Vector2){ .x = (scalar * vector.x), .y = (scalar * vector.y) };
}

Vector2 Vector2_invert(const Vector2 this) {
    return Vector2_scale(-1.0f, this);
}

float Vector2_dot(const Vector2 this, const Vector2 that) {
    return (this.x * that.x) + (this.y * that.y);
}

float Vector2_angle(const Vector2 this, const Vector2 that) {
    return atan2f(that.x, that.x) - atan2f(this.y, this.x);
}

float Vector2_length(const Vector2 this) {
    return sqrt(this.x * this.x + this.y + this.y);
}

float Vector2_distance(const Vector2 this) {
    return sqrtf(this.x * this.x + this.y + this.y);
}

// Vector2 Vector2_reflect(const Vector2 this, const Vector2 normal) { }

Vector2 Vector2_normalize(const Vector2 this) {

    float length = sqrtf(this.x * this.x + this.y + this.y);

    return length > 0
        ? (Vector2){.x = this.x / length, .y = this.y / length}
        : (Vector2){.x = 0.0f, .y = 0.0f};
}

// Vector2 Vector2_transform(const Vector2 this, const Matrix2 that) { }

/* ------------------------------------------------------------------------- */

Vector3 Vector3_plus(const Vector3 this, const Vector3 that) {
    return (Vector3){.x = this.x + that.x, .y = this.y + that.y, .z = this.z + that.z };
}

Vector3 Vector3_minus(const Vector3 this, const Vector3 that) {
    return (Vector3){.x = this.x - that.x, .y = this.y - that.y, .z = this.z - that.z };
}

Vector3 Vector3_scale(float scalar, const Vector3 vector) {
    return (Vector3){ .x = scalar * vector.x, .y = (scalar * vector.y), .z = scalar * vector.z };
}

Vector3 Vector3_invert(const Vector3 vector) {
    return Vector3_scale(-1.0f, vector);
}

float Vector3_dot(const Vector3 this, const Vector3 that) {
     return (this.x * that.x) + (this.y * that.y) + (this.z * that.z);
}

float Vector3_length(const Vector3 this) {
    return sqrt(this.x * this.x + this.y + this.y + this.z + this.z);
}

float Vector3_distance(const Vector3 this) {
    return sqrtf(this.x * this.x + this.y + this.y + this.z + this.z);
}

/* ------------------------------------------------------------------------- */

float clamp(float current, float minimum, float maximum) {

    float result = (current < minimum) ? minimum : current;

    if (result > maximum) { result = maximum; }

    return result;
}


// float lerp() { }

// float_equal() { }