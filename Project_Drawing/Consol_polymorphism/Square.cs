using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Consol_polymorphism
{
    class Square : IShape
    {
        private double m_width;

        public Square(double width)
        {
            m_width = width;
        }

        public double CalcLength()
        {
            return (m_width * 4.0);
        }

        public double CalcArea()
        {
            return (m_width * m_width);
        }

    }
}
