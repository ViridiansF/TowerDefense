#pragma once
#include <math.h>
#include <iostream> 
#include <raylib.h>  

namespace myMath
{
    //const float PI = 3.141592653589793;

    inline float sqrt(float x)
    {
        float result = x / 4;
        for(int i = 0; i < 6; i++)
        {
            result = (result + x / result) / 2;
        }
        return result;
    }

    inline float pow (float x, int p)
    {
        float result = 1;
        for (int i = 0; i < p; i++)
        {
            result *= x;
        }
        return result;
    }

    template<typename T>
    inline T Min(T a, T b)
    {
        return a < b ? a : b;
    }

    template<typename T>
    inline T Max(T a, T b)
    {
        return a > b ? a : b;
    }

    template<typename T>
    inline T Abs(T a)
    {
        return a < 0 ? -a : a;
    }

    class Vec2
    {
        public : 
            float x;
            float y;

            Vec2(float _x = 0, float _y = 0)
            {
                x = _x; y = _y;
            }

            Vec2(int _x, int _y)
            {
                x = (float)_x; y = (float)_y;
            }

            Vec2(Vector2 _vec)
            {
                x = (float)_vec.x; y = (float)_vec.y;
            }

            ~Vec2() {};

            float GetNorm()
            {
                return sqrt(pow(x, 2) + pow(y, 2));
            }

            inline Vec2 operator+(Vec2 b)
            {
                return (Vec2){this->x + b.x, this->y + b.y};
            }

            inline Vec2 operator-(Vec2 b)
            {
                return (Vec2){this->x - b.x, this->y - b.y};
            }

            inline Vec2 operator*(float b)
            {
                return (Vec2){x * b, y * b};
            }

            inline Vec2 operator/(float b)
            {
                return (Vec2){this->x / b, this->y / b};
            }

            inline float operator*(Vec2 b)
            {
                return (float){this->x * b.x + this->y * b.y};
            }

            friend std::ostream& operator << (std::ostream& stream, const Vec2& a)
            {
                return stream << "(" << a.x << ", " << a.y << ")";
            }

            inline Vec2 Normalized()
            {
                float norm = GetNorm();
                return (Vec2){x / norm, y / norm};
            }

            inline float operator^(Vec2 b)
            {
                return this->x * b.y - this->y * b.x;
            }

            inline bool operator==(Vec2 b)
            {
                return (this->x == b.x && this->y == b.y);
            }

            inline Vec2 Rotate(Vec2 origin, float angle)
            {
                Vec2 op = *this - origin;
                Vec2 opP;
                opP.x = cos(angle) * op.x - sin(angle) * op.y;
                opP.y = sin(angle) * op.x + cos(angle) * op.y; 
                return opP + origin;
            }

            inline static Vec2 Vec2Zero()
            {
                return (Vec2){0, 0};
            }

            inline Vec2 Projection (Vec2 b, Vec2 c)
            {
                Vec2 axis = c - b;
                Vec2 point = *this - b;

                return axis * ((point * axis) / (axis * axis)) + b;
            }

            inline Vector2 toVector2()
            {
                return {x, y};
            }

            inline Vec2 floor(int i)
            {
                return {(int)x - ((int)x % i), (int)y - ((int)y % i)};
            }

            inline Vec2 Abs()
            {
                return {abs(x), abs(y)};
            }

            explicit operator Vector2() 
            {
                return toVector2();
            }
    };
    inline Vec2 toVec2(const Vector2 v)
    {
        return {v.x, v.y};
    }

    inline float Distance (Vec2 a, Vec2 b)
    {
        return ((b - a).GetNorm());
    }
}

namespace collision
{
    using namespace myMath;
    class Box
    {
        public :
            Vec2 min;
            Vec2 max;

            Box(){};

            Box(const Vec2 _min,const Vec2 _max)
            {
                min = _min; max = _max;
            }

            Box(const int x,const int y,const int width,const int height)
            {
                min = (Vec2){x, y};
                max = (Vec2){x + width, y + height};
            }

            Rectangle toRec()
            {
                return (Rectangle){min.x, min.y, max.x - min.x, max.y - min.y};
            }
    };

    inline bool Collision(Box box, Vec2 point)
    {
        return (point.x > box.min.x && point.x < box.max.x &&
                point.y > box.min.y && point.y < box.max.x);
    }

    //Collision circle/circle
    inline bool Collision(Vec2 centerCircle1,const float radiusCircle1, Vec2 centerCircle2,const float radiusCircle2)
    {
        return CheckCollisionCircles((Vector2)centerCircle1,radiusCircle1,(Vector2)centerCircle2,radiusCircle2);
/*
        float distanceBetweenCenters = myMath::sqrt( 
            (myMath::pow(centerCircle2.x,2)-myMath::pow(centerCircle1.x,2)) 
            +
            (myMath::pow(centerCircle2.y,2)-myMath::pow(centerCircle1.y,2)) 
        );

        if(distanceBetweenCenters<0)
            distanceBetweenCenters*=-1;


        if(distanceBetweenCenters>(radiusCircle1+radiusCircle2))
            return false;
        else
            return true;
    */
    }
}