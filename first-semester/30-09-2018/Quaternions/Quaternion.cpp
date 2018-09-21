//
// Created by yuna on 20.09.18.
//

#include "Quaternion.h"
#include <cmath>


//region Additional functions

Quaternion const &invertQuat(Quaternion const &a) {
    return Quaternion(-a.x, -a.y, -a.z, -a.scal);
}

//region Overriding of binary  as functions

Quaternion const &operator*(Quaternion const &a, double scale) {
    return Quaternion(a.getX() * scale, a.getY() * scale, a.getZ() * scale, a.getScalar() * scale);
}

Quaternion const &operator/(Quaternion const &a, double scale) {
    return Quaternion(a.getX() / scale, a.getY() / scale, a.getZ() / scale, a.getScalar() / scale);
}

Quaternion const &operator+(Quaternion const &a, Quaternion const &b) {
    return Quaternion(a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ(), a.getScalar() + b.getScalar());
}

Quaternion const &operator-(Quaternion const &a, Quaternion const &b) {
    return Quaternion(a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ(), a.getScalar() - b.getScalar());
}

Quaternion const &operator*(Quaternion const &a, Quaternion const &b) {

    return Quaternion(a.scal * b.x + a.x * b.scal + a.y * b.z - a.z * b.y,
                      a.scal * b.y - a.x * b.z + a.y * b.scal + a.z * b.x,
                      a.scal * b.z + a.x * b.y - a.y * b.x + a.z * b.scal,
                      a.scal * b.scal - a.x * b.x - a.y * b.y - a.z * b.z);
}

Quaternion const &operator/(Quaternion const &a, Quaternion const &b) {
    return a * invertQuat(b);
}

//endregion

//endregion


Quaternion::Quaternion(double x, double y, double z, double scalar) : x(x), y(y), z(z), scal(scalar) {}

Quaternion::Quaternion(Quaternion const &other) : x(other.x), y(other.y), z(other.z), scal(other.scal) {}

//region Setters-Getters

void Quaternion::setX(double newX) {
    x = newX;
}

void Quaternion::setY(double newY) {
    y = newY;
}

void Quaternion::setZ(double newZ) {
    z = newZ;
}

void Quaternion::setScalar(double newScalar) {
    scal = newScalar;
}

double Quaternion::getX() const {
    return x;
}

double Quaternion::getY() const {
    return y;
}

double Quaternion::getZ() const {
    return z;
}

double Quaternion::getScalar() const {
    return scal;
}
//endregion

//region Overriding operators as methods

Quaternion &Quaternion::operator=(Quaternion const &other) {
    x = other.x;
    y = other.y;
    z = other.z;
    scal = other.scal;
    return *this;
}

bool Quaternion::operator==(Quaternion const &other) const {
    return x == other.x && y == other.y && z == other.z && scal == other.scal;
}

bool Quaternion::operator!=(Quaternion const &other) const {
    return !(x == other.x && y == other.y && z == other.z && scal == other.scal);
}

Quaternion &Quaternion::operator*=(double scale) {
    x *= scale;
    y *= scale;
    z *= scale;
    scal *= scale;
    return *this;
}

Quaternion &Quaternion::operator/=(double scale) {
    x /= scale;
    y /= scale;
    z /= scale;
    scal /= scale;
    return *this;
}

Quaternion &Quaternion::operator+=(Quaternion const &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    scal += other.scal;
    return *this;
}

Quaternion &Quaternion::operator-=(Quaternion const &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    scal -= other.scal;
    return *this;
}


Quaternion &Quaternion::operator*=(Quaternion const &other) {
    double tx = x;
    double ty = y;
    double tz = z;
    double tscal = scal;
    x = tscal * other.x + tx * other.scal + ty * other.z - tz * other.y;
    y = tscal * other.y - tx * other.z + ty * other.scal + tz * other.x;
    z = tscal * other.z + tx * other.y - ty * other.x + tz * other.scal;
    scal = tscal * other.scal - tx * other.x - ty * other.y - tz * other.z;
    return *this;
}

//TODO: understand wtf
Quaternion &Quaternion::operator/=(Quaternion const &other) {
    //this *= invertQuat(other);
    return *this;
}

//endregion

double Quaternion::magnitude() {
    return sqrt(x * x + y * y + z * z);
}

void Quaternion::normalize() {
    double tmagnitude = magnitude();
    if (tmagnitude) {
        x /= tmagnitude;
        y /= tmagnitude;
        z /= tmagnitude;
    }
}

void Quaternion::invert() {
    x = -x;
    y = -y;
    z = -z;
}




























