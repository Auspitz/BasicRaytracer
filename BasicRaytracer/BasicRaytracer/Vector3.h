#pragma once

#include <math.h>

class Vector3
{
public:
	double e[3];

	Vector3() {};
	~Vector3() {};
	Vector3(double e0, double e1, double e2) { e[0] = e0; e[1] = e1; e[2] = e2; }

	inline double x() const { return e[0]; }
	inline double y() const { return e[1]; }
	inline double z() const { return e[2]; }
	inline double r() const { return e[0]; }
	inline double g() const { return e[1]; }
	inline double b() const { return e[2]; }

	inline const Vector3& operator+() const { return *this; }
	inline Vector3 operator-() const { return Vector3(-e[0], -e[1], -e[2]); }
	inline double operator[](int i) const { return e[i]; }
	inline double& operator[](int i) { return e[i]; }

	inline Vector3& operator+=(const Vector3 &v2);
	inline Vector3& operator-=(const Vector3 &v2);
	inline Vector3& operator*=(const Vector3 &v2);
	inline Vector3& operator/=(const Vector3 &v2);
	inline Vector3& operator*=(const double t);
	inline Vector3& operator/=(const double t);

	inline double length() const {
		return sqrt(x() * x() + y() * y() + z() * z());
	}

	inline double squared_length() const {
		return x() * x() + y() * y() + z() * z();
	}

	inline void make_unit_vector();


};

inline Vector3 operator*(double t, const Vector3 &v)
{
	return Vector3(t * v.x(), t * v.y(), t * v.z());
}

inline Vector3 operator+(const Vector3 &v1, const Vector3 &v2)
{
	return Vector3(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}

inline Vector3 operator/(const Vector3 &v1, const Vector3 &v2) {
	return Vector3(v1.x() / v2.x(), v1.y() / v2.y(), v1.z() / v2.z());
}

inline Vector3 operator/(Vector3 v, double t) {
	return Vector3(v.x() / t, v.y() / t, v.z() / t);
}

inline Vector3 cross(const Vector3 &v1, const Vector3 &v2) {
	return Vector3(
		(v1.y() * v2.z() - v1.z() * v2.y()),
		(-(v1.x() * v2.z() - v1.z() * v2.x())),
		(v1.x() * v2.y() - v1.y() * v2.x())
	);
}

// AKA Normalized vector
inline Vector3 unit_vector(Vector3 v) {
	return v / v.length();
}
