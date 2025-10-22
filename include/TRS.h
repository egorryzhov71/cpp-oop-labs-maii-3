#include <iostream>
#include <vector>
#include <utility>

class Figure{
    public:
        virtual ~Figure() = default;

        virtual std::pair<double, double> getCenter() const = 0;
        virtual double area() const = 0;

        virtual void printVertices(std::ostream& os) const = 0;
        virtual void readData(std::istream& is) = 0;

        virtual bool operator==(const Figure& other) const = 0;
        virtual Figure& operator=(const Figure& other) = 0;
        virtual Figure& operator=(Figure&& other) = 0;
    
};

std::ostream& operator<<(std::ostream& os, const Figure& fig);
std::istream& operator>>(std::istream& is, Figure& fig);

double operator+(double value, const Figure& fig);

class Square : public Figure {
    private:
        double x, y, side;

    public:
        Square(double x = 0, double y = 0, double side = 1);

        bool operator==(const Figure& other) const override;
        Square& operator=(const Figure& other) override;
        Square& operator=(Figure&& other) override;

        std::pair<double, double> getCenter() const override;
        double area() const override;
        void printVertices(std::ostream& os) const override;
        void readData(std::istream& is) override;
};

class Rectangle : public Figure {
    private:
        double x, y, width, height;

    public:
        Rectangle(double x = 0, double y = 0, double width = 1, double height = 1);

        
        bool operator==(const Figure& other) const override;
        Rectangle& operator=(const Figure& other) override;
        Rectangle& operator=(Figure&& other) override;

        std::pair<double, double> getCenter() const override;
        double area() const override;
        void printVertices(std::ostream& os) const override;
        void readData(std::istream& is) override;

        bool operator==(const Figure& other) const override;

};

class Trapezoid : public Figure {
    private:
        double x, y, base1, base2, height;

    public:
        Trapezoid(double x = 0, double y = 0, double base1 = 1, double base2 = 2, double height = 1);

        
        bool operator==(const Figure& other) const override;
        Trapezoid& operator=(const Figure& other) override;
        Trapezoid& operator=(Figure&& other) override;

        std::pair<double, double> getCenter() const override;
        double area() const override;
        void printVertices(std::ostream& os) const override;
        void readData(std::istream& is) override;

        bool operator==(const Figure& other) const override;


};
