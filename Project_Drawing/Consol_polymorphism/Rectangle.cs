using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Consol_polymorphism
{
    class Rectangle : IShape
    {
        public double CalcLength()
        {
            Console.WriteLine("[Rectangle] : length");
            return 0.0;
        }

        public double CalcArea()
        {
            Console.WriteLine("[Rectangle] : area");
            return 0.0;
        }

    }
}
