#include <iostream>
#include "/workspaces/C++/include/TRS.h"
#include <utility>

std::ostream& operator<<(std::ostream& os, const Figure& fig){
    fig.printVertices(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& fig){
    fig.readData(is);
    return is;
}

Square::Square(double x, double y, double side) : x(x), y(y), side(side){}
std::pair<double, double> Square::getCenter() const {
    return {x, y};
}

double Square::area() const{
    return side * side;
}

void Square::printVertices(std::ostream& os) const{
    double half = side / 2;
    os << "Square vertices: (" << x - half << ", " << y - half << "), "
    << "(" << x + half << ", " << y - half << "), "
    << "(" << x + half << ", " << y + half << "), "
    << "(" << x - half << ", " << y + half << ")";

}

void Square::readData(std::istream& is){
    std::cout << "Enter Square (center_x center y side) :";
    is >> x >> y >> side;
}

Square& Square::operator=(const Figure& other){
    const Square* otherSquare = dynamic_cast<const Square*>(&other);
    if (otherSquare != nullptr){
        x = otherSquare -> x;
        y = otherSquare -> y;
        side = otherSquare -> side;
    }
    return *this;
}

Square& Square::operator=(Figure&& other){
    Square* otherSquare = dynamic_cast<Square*>(&other);
    if (otherSquare != nullptr){
        x = std::exchange(otherSquare -> x, 0);
        y = std::exchange(otherSquare -> y, 0);
        side = std::exchange(otherSquare -> side, 0);
    }
    return *this;
}

bool Square::operator==(const Figure& other) const {
    const Square* otherSquare = dynamic_cast<const Square*>(&other);
    if (otherSquare == nullptr){
        return false;
    }
    return (x == otherSquare -> x) && (y == otherSquare -> y) && (side == otherSquare -> side);
}

Trapezoid::Trapezoid(double x, double y, double base1, double base2, double height) : 
    x(x), y(y), base1(base1), base2(base2), height(height){}


std::pair<double, double> Square::getCenter() const {
    return {x, y};
}

double Trapezoid::area() const{
    return (base1 + base2) * height / 2;
}

void Trapezoid::printVertices(std::ostream& os) const{
    double offset1 = base1 / 2;
    double offset2 = base2 / 2;
    double half_h = height / 2;
    os << "Trapezoid vertices: (" << x - offset2 << ", " << y - half_h << "), "
       << "(" << x + offset2 << ", " << y - half_h << "), "
       << "(" << x + offset1 << ", " << y + half_h << "), "
       << "(" << x - offset1 << ", " << y + half_h << ")";
}

void Trapezoid::readData(std::istream& is){
    std::cout << "Enter Square (center_x center y side) :";
    is >> x >> y >> base1 >> base2 >> height;
}

Trapezoid& Trapezoid::operator=(const Figure& other){
    const Trapezoid* otherTrapezoid = dynamic_cast<const Trapezoid*>(&other);
    if (otherTrapezoid != nullptr){
        x = otherTrapezoid -> x;
        y = otherTrapezoid -> y;
        base1 = otherTrapezoid -> base1;
        base2 = otherTrapezoid -> base2;
        height = otherTrapezoid -> height;

    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Figure&& other){
    Trapezoid* other_Trapezoid = dynamic_cast<Trapezoid*>(&other);
    if (other_Trapezoid != nullptr){
        x = std::exchange(other_Trapezoid -> x, 0);
        y = std::exchange(other_Trapezoid -> y, 0);
        base1 = std::exchange(other_Trapezoid -> base1, 0);
        base2 = std::exchange(other_Trapezoid -> base2, 0);
        height = std::exchange(other_Trapezoid -> height, 0);
    }
    return *this;
}

bool Trapezoid::operator==(const Figure& other) const {
    const Trapezoid* other_Trapezoid = dynamic_cast<const Trapezoid*>(&other);
    if (other_Trapezoid == nullptr){
        return false;
    }
    return (x == other_Trapezoid -> x) && (y == other_Trapezoid -> y) && (base1 == other_Trapezoid -> base2) &&
    (base2 == other_Trapezoid -> base2) && (height == other_Trapezoid -> height);
}

Rectangle::Rectangle(double x, double y, double width, double height) 
    : x(x), y(y), width(width), height(height) {}

std::pair<double, double> Rectangle::getCenter() const {
    return {x, y};
}

double Rectangle::area() const {
    return width * height;
}

void Rectangle::printVertices(std::ostream& os) const {
    double half_w = width / 2;
    double half_h = height / 2;
    os << "Rectangle vertices: (" << x - half_w << ", " << y - half_h << "), "
       << "(" << x + half_w << ", " << y - half_h << "), "
       << "(" << x + half_w << ", " << y + half_h << "), "
       << "(" << x - half_w << ", " << y + half_h << ")";
}

void Rectangle::readData(std::istream& is) {
    std::cout << "Enter rectangle data (center_x center_y width height): ";
    is >> x >> y >> width >> height;
}

Rectangle& Rectangle::operator=(const Figure& other) {
    const Rectangle* otherRect = dynamic_cast<const Rectangle*>(&other);
    if (otherRect != nullptr) {
        x = otherRect->x;
        y = otherRect->y;
        width = otherRect->width;
        height = otherRect->height;
    }
    return *this;
}

Rectangle& Rectangle::operator=(Figure&& other) {
    Rectangle* otherRect = dynamic_cast<Rectangle*>(&other);
    if (otherRect != nullptr) {
        x = std::exchange(otherRect->x, 0);
        y = std::exchange(otherRect->y, 0);
        width = std::exchange(otherRect->width, 0);
        height = std::exchange(otherRect->height, 0);
    }
    return *this;
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* otherRect = dynamic_cast<const Rectangle*>(&other);
    if (otherRect == nullptr) {
        return false;
    }
    return (x == otherRect->x) && 
           (y == otherRect->y) && 
           (width == otherRect->width) && 
           (height == otherRect->height);
}