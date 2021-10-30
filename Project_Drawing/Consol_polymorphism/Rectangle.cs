using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Consol_polymorphism
{
    class Rectangle : Shape
    {
        public override double CalcLength()
        {
            Console.WriteLine("[Rectangle] : length");
            return 0.0;
        }

        public override double CalcArea()
        {
            Console.WriteLine("[Rectangle] : area");
            return 0.0;
        }

    }
}
