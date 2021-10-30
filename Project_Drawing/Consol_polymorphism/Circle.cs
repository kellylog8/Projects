using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Consol_polymorphism
{
    class Circle : IShape
    {
        private double m_radius;

        public Circle(double radius)
        {
            m_radius = radius;
        }

        public double CalcLength()
        {
            return (2.0 * Math.PI * m_radius);
        }

        public double CalcArea()
        {
            return (Math.PI * m_radius * m_radius);
            //return (Math.PI * Math.Pow(m_radius, 2));
        }

    }
}
