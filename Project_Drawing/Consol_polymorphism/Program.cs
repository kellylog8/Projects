using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Consol_polymorphism
{
    class Program
    {
        static void Main(string[] args)
        {
            Rectangle rect = new Rectangle(20, 10);
            rect.CalcLength();
            rect.CalcArea();

            Square square = new Square(10);
            square.CalcLength();
            square.CalcArea();

            Triangle triangle = new Triangle(10);
            triangle.CalcLength();
            triangle.CalcArea();

            Circle circle = new Circle(10);
            circle.CalcLength();
            circle.CalcArea();

        }
    }
}
