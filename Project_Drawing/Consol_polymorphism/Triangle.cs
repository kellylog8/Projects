using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Consol_polymorphism
{
    class Triangle : IShape
    {
        private double m_length;

        public Triangle(double length)
        {
            m_length = length;
        }
        
        public double CalcLength()
        {
            return (m_length * 3);
        }

        public double CalcArea()
        {
            double h = m_length * Math.Sin(m_length);

            return (m_length * h / 2.0);
        }

    }
}
