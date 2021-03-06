using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Consol_polymorphism
{
    class Rectangle : IShape
    {
        private double m_width;
        private double m_height;

        public Rectangle(double width, double height)
        {
            m_width = width;
            m_height = height;
        }

        public double CalcLength()
        {
            return ((m_width + m_height) * 2);
        }

        public double CalcArea()
        {
            return (m_width * m_height);
        }

    }
}
