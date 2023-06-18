#pragma once

#include <iostream>

struct Vector2f{
    Vector2f() : x(0.0f), y(0.0f) 
    {}

    Vector2f(float p_x, float p_y) : x(p_x), y(p_y) 
    {}

    Vector2f operator+ (Vector2f const &vect){
        Vector2f result;
        result.x = x + vect.x;
        result.y = y + vect.y;
        return result;
    }
    void operator= (Vector2f const &vect){
        x = vect.x;
        y = vect.y;
    }

    void print(){
        std::cout  << "("<< x << ", " << y << ")" << "\n";
    }
    Vector2f operator*(const double num){
        Vector2f result;
        result.x = x * num;
        result.y = y * num;
        return result;
    }
    float x, y;
};