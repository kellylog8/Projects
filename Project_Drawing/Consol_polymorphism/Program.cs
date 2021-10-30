﻿using System;
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
            Console.WriteLine("Rectangle Length = " + rect.CalcLength());
            Console.WriteLine("Rectangle Area   = " + rect.CalcArea());

            Square square = new Square(10);
            Console.WriteLine("Square Length = " + square.CalcLength());
            Console.WriteLine("Square Area   = " + square.CalcArea());

            Triangle triangle = new Triangle(10);
            Console.WriteLine("Triangle Length = " + triangle.CalcLength());
            Console.WriteLine("Triangle Area   = " + triangle.CalcArea());

            Circle circle = new Circle(10);
            Console.WriteLine("Circle Length = " + circle.CalcLength());
            Console.WriteLine("Circle Area   = " + circle.CalcArea());

        }
    }
}
