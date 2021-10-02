#pragma once
#include <assert.h>

class vec2
{
public:
	float x;
	float y;

public:
	vec2() {}
	vec2(float nxy) { x = nxy; y = nxy; }
	vec2(float nx, float ny) { x = nx; y = ny; }
	//virtual ~vec2() {}

	static const vec2 Right() { return vec2(1.0f, 0.0f); }
	static const vec2 Up() { return vec2(0.0f, 1.0f); }

	inline void Set(float nx, float ny) { x = nx; y = ny; }
	inline float LengthSquared() const { return x * x + y * y; }
	inline float Length() const { return sqrtf(x * x + y * y); }

	inline vec2 GetNormalized() const { vec2 vector2(x, y); vector2.Normalize(); return vector2; }
	inline void Normalize() {
		float length = LengthSquared();
		if (length != 0)
		{
			length = sqrtf(length);
			x /= length;
			y /= length;
		}
	}

	//Returns a vector rotated 90 degrees clockwise
	inline vec2 PerpendicularClockwise() { return vec2(y, -x); }

	//Returns a vector rotated 90 degrees counterclockwise
	inline vec2 PerpendicularCounterClockwise() { return vec2(-y, x); }

	inline void MakeAbsolute() { if (x < 0) x *= -1; if (y < 0) y *= -1; }
	inline vec2 GetAbsolute() const { return vec2(x < 0 ? -x : x, y < 0 ? -y : y); }
	inline float DotProduct(const vec2& o) const { return x * o.x + y * o.y; }
	inline float Distance(const vec2& o) const { return sqrtf(DistanceSquared(o)); }
	inline float DistanceSquared(const vec2& o) const { return (x - o.x) * (x - o.x) + (y - o.y) * (y - o.y); }
	inline vec2 Add(const vec2& o) const { return vec2(this->x + o.x, this->y + o.y); }
	inline vec2 Sub(const vec2& o) const { return vec2(this->x - o.x, this->y - o.y); }
	inline vec2 Scale(const float o) const { return vec2(this->x * o, this->y * o); }

	inline bool operator ==(const vec2& o) const { return x == o.x && y == o.y; }
	inline bool operator !=(const vec2& o) const { return x != o.x || y != o.y; }
	inline bool operator <=(const vec2& o) const { return x <= o.x || y <= o.y; }
	inline bool operator >=(const vec2& o) const { return x >= o.x || y >= o.y; }
	inline bool operator <(const vec2& o) const { return x < o.x || y < o.y; }
	inline bool operator >(const vec2& o) const { return x > o.x || y > o.y; }

	inline vec2 operator -() const { return vec2(-this->x, -this->y); }
	inline vec2 operator *(const float o) const { return vec2(this->x * o, this->y * o); }
	inline vec2 operator /(const float o) const { return vec2(this->x / o, this->y / o); }
	inline vec2 operator +(const float o) const { return vec2(this->x + o, this->y + o); }
	inline vec2 operator -(const float o) const { return vec2(this->x - o, this->y - o); }
	inline vec2 operator *(const vec2& o) const { return vec2(this->x * o.x, this->y * o.y); }
	inline vec2 operator /(const vec2& o) const { return vec2(this->x / o.x, this->y / o.y); }
	inline vec2 operator +(const vec2& o) const { return vec2(this->x + o.x, this->y + o.y); }
	inline vec2 operator -(const vec2& o) const { return vec2(this->x - o.x, this->y - o.y); }

	inline vec2 operator *=(const float o) { this->x *= o; this->y *= o; return *this; }
	inline vec2 operator /=(const float o) { this->x /= o; this->y /= o; return *this; }
	inline vec2 operator +=(const float o) { this->x += o; this->y += o; return *this; }
	inline vec2 operator -=(const float o) { this->x -= o; this->y -= o; return *this; }
	inline vec2 operator *=(const vec2& o) { this->x *= o.x; this->y *= o.y; return *this; }
	inline vec2 operator /=(const vec2& o) { this->x /= o.x; this->y /= o.y; return *this; }
	inline vec2 operator +=(const vec2& o) { this->x += o.x; this->y += o.y; return *this; }
	inline vec2 operator -=(const vec2& o) { this->x -= o.x; this->y -= o.y; return *this; }
};

inline vec2 operator *(float scalar, const vec2& vec) { return vec2(scalar * vec.x, scalar * vec.y); }
inline vec2 operator /(float scalar, const vec2& vec) { return vec2(scalar / vec.x, scalar / vec.y); }
inline vec2 operator +(float scalar, const vec2& vec) { return vec2(scalar + vec.x, scalar + vec.y); }
inline vec2 operator -(float scalar, const vec2& vec) { return vec2(scalar - vec.x, scalar - vec.y); }

class ivec2
{
public:
	int x;
	int y;

public:
	ivec2() {}
	ivec2(int nx, int ny) { x = nx; y = ny; }
	ivec2(vec2 o) { x = (int)o.x; y = (int)o.y; }
	//virtual ~ivec2() {}

	inline void Set(int nx, int ny) { x = nx; y = ny; }
	inline float LengthSquared() const { return (float)x * x + y * y; }
	inline float Length() const { return sqrtf((float)x * x + y * y); }
	inline float DistanceFrom(const ivec2 o) const { return sqrtf(((float)x - o.x) * (x - o.x) + (y - o.y) * (y - o.y)); }

	//inline ivec2 Normalize() const {float len = Length(); if( fequal(len,0) ) return ivec2(x,y); len = 1.0f/len; return ivec2(x*len, y*len);}

	inline ivec2 WithX(int x) const { return ivec2(x, this->y); }
	inline ivec2 WithY(int y) const { return ivec2(this->x, y); }

	inline bool operator ==(const ivec2& o) const { return this->x == o.x && this->y == o.y; }
	inline bool operator !=(const ivec2& o) const { return this->x != o.x || this->y != o.y; }

	inline ivec2 operator -() const { return ivec2(-this->x, -this->y); }
	inline vec2 operator *(const float o) const { return vec2(this->x * o, this->y * o); }
	inline vec2 operator /(const float o) const { return vec2(this->x / o, this->y / o); }
	inline vec2 operator +(const float o) const { return vec2(this->x + o, this->y + o); }
	inline vec2 operator -(const float o) const { return vec2(this->x - o, this->y - o); }
	inline ivec2 operator *(const int o) const { return ivec2(this->x * o, this->y * o); }
	inline ivec2 operator /(const int o) const { return ivec2(this->x / o, this->y / o); }
	inline ivec2 operator +(const int o) const { return ivec2(this->x + o, this->y + o); }
	inline ivec2 operator -(const int o) const { return ivec2(this->x - o, this->y - o); }
	inline vec2 operator *(const vec2& o) const { return vec2(this->x * o.x, this->y * o.y); }
	inline vec2 operator /(const vec2& o) const { return vec2(this->x / o.x, this->y / o.y); }
	inline vec2 operator +(const vec2& o) const { return vec2(this->x + o.x, this->y + o.y); }
	inline vec2 operator -(const vec2& o) const { return vec2(this->x - o.x, this->y - o.y); }
	inline ivec2 operator *(const ivec2& o) const { return ivec2(this->x * o.x, this->y * o.y); }
	inline ivec2 operator /(const ivec2& o) const { return ivec2(this->x / o.x, this->y / o.y); }
	inline ivec2 operator +(const ivec2& o) const { return ivec2(this->x + o.x, this->y + o.y); }
	inline ivec2 operator -(const ivec2& o) const { return ivec2(this->x - o.x, this->y - o.y); }

	inline ivec2 operator *=(const int o) { this->x *= o; this->y *= o; return *this; }
	inline ivec2 operator /=(const int o) { this->x /= o; this->y /= o; return *this; }
	inline ivec2 operator +=(const int o) { this->x += o; this->y += o; return *this; }
	inline ivec2 operator -=(const int o) { this->x -= o; this->y -= o; return *this; }
	inline ivec2 operator *=(const ivec2& o) { this->x *= o.x; this->y *= o.y; return *this; }
	inline ivec2 operator /=(const ivec2& o) { this->x /= o.x; this->y /= o.y; return *this; }
	inline ivec2 operator +=(const ivec2& o) { this->x += o.x; this->y += o.y; return *this; }
	inline ivec2 operator -=(const ivec2& o) { this->x -= o.x; this->y -= o.y; return *this; }

	int& operator[] (int i) { assert(i >= 0 && i < 2); return *(&x + i); }
};

inline ivec2 operator *(int scalar, const ivec2& vec) { return ivec2(scalar * vec.x, scalar * vec.y); }
inline ivec2 operator /(int scalar, const ivec2& vec) { return ivec2(scalar / vec.x, scalar / vec.y); }
inline ivec2 operator +(int scalar, const ivec2& vec) { return ivec2(scalar + vec.x, scalar + vec.y); }
inline ivec2 operator -(int scalar, const ivec2& vec) { return ivec2(scalar - vec.x, scalar - vec.y); }