//
// Created by vlad on 10/28/23.
//

#define _USE_MATH_DEFINES

#include <uml/Vector3.h>
#include <cmath>
#include <uml/angles.h>

namespace uml
{
    bool Vector3::operator==(const Vector3 &src) const
    {
        return (src.x == x) and (src.y == y) and (src.z == z);
    }

    bool Vector3::operator!=(const Vector3 &src) const
    {
        return (src.x != x) or (src.y != y) or (src.z != z);
    }

    Vector3 &Vector3::operator+=(const Vector3 &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;

        return *this;
    }

    Vector3 &Vector3::operator-=(const Vector3 &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;

        return *this;
    }

    Vector3 &Vector3::operator*=(const float fl)
    {
        x *= fl;
        y *= fl;
        z *= fl;

        return *this;
    }

    Vector3 &Vector3::operator*=(const Vector3 &v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;

        return *this;
    }

    Vector3 &Vector3::operator/=(const Vector3 &v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;

        return *this;
    }

    Vector3 &Vector3::operator+=(const float fl)
    {
        x += fl;
        y += fl;
        z += fl;

        return *this;
    }

    Vector3 &Vector3::operator/=(const float fl)
    {
        x /= fl;
        y /= fl;
        z /= fl;

        return *this;
    }

    Vector3 &Vector3::operator-=(const float fl)
    {
        x -= fl;
        y -= fl;
        z -= fl;

        return *this;
    }

    float Vector3::DistTo(const Vector3 &vOther) const
    {
        Vector3 delta;

        delta.x = x - vOther.x;
        delta.y = y - vOther.y;
        delta.z = z - vOther.z;

        return delta.Length();
    }

    Vector3 &Vector3::Abs()
    {
        x = std::abs(x);
        y = std::abs(y);
        z = std::abs(z);

        return *this;
    }

    float Vector3::DistToSqr(const Vector3 &vOther) const
    {
        Vector3 delta;

        delta.x = x - vOther.x;
        delta.y = y - vOther.y;
        delta.z = z - vOther.z;

        return delta.LengthSqr();
    }

    float Vector3::Dot(const Vector3 &vOther) const
    {
        return (x * vOther.x + y * vOther.y + z * vOther.z);
    }

    float Vector3::Length() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    float Vector3::LengthSqr() const
    {
        return (x * x + y * y + z * z);
    }

    float Vector3::Length2D() const
    {
        return std::sqrt(x * x + y * y);

    }

    Vector3 Vector3::operator-() const
    {
        return {-x, -y, -z};
    }

    Vector3 Vector3::operator+(const Vector3 &v) const
    {
        return {x + v.x, y + v.y, z + v.z};
    }

    Vector3 Vector3::operator-(const Vector3 &v) const
    {
        return {x - v.x, y - v.y, z - v.z};
    }

    Vector3 Vector3::operator*(float fl) const
    {
        return {x * fl, y * fl, z * fl};
    }

    Vector3 Vector3::operator*(const Vector3 &v) const
    {
        return {x * v.x, y * v.y, z * v.z};
    }

    Vector3 Vector3::operator/(const float fl) const
    {
        return {x / fl, y / fl, z / fl};
    }

    Vector3 Vector3::operator/(const Vector3 &v) const
    {
        return {x / v.x, y / v.y, z / v.z};
    }

    Vector3 Vector3::CreateVelocity(const Vector3 &angles, const float length)
    {
        return
        {
            std::cos(angles::DegToRad(angles.y)) * length,
            std::sin(angles::DegToRad(angles.y)) * length,
            std::tan(angles::DegToRad(angles.x)) * length,
        };
    }

    float Vector3::Sum() const
    {
        return x + y + z;
    }

    float Vector3::Sum2D() const
    {
        return x + y;
    }

    Vector3 Vector3::ViewAngleTo(const Vector3 &other) const
    {
        const float distance = DistTo(other);
        const auto delta = other - *this;

        // Make x negative since -89 is top and 89 is bottom
        return
        {
            -angles::RadToDeg(asinf(delta.z / distance)),
            angles::RadToDeg(atan2f(delta.y, delta.x)),
            0.f
        };
    }
}