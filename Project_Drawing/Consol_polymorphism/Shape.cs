using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Consol_polymorphism
{
    class Shape
    {
        public virtual double CalcLength()
        {
            Console.WriteLine("[Shape] : length");
            return 0.0;
        }

        public virtual double CalcArea()
        {
            Console.WriteLine("[Shape] : area");
            return 0.0;
        }

    }
}
