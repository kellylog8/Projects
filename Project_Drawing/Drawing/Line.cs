using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Drawing
{
    class Line : IShape
    {
        PenStyle m_penStyle;

        Point m_p1, m_p2;

        public void CalcRect(Point start, Point end)
        {
            m_p1 = start;
            m_p2 = end;
        }

        public void Draw(Graphics canvas, Pen pen)
        {
            pen.Color = m_penStyle.color;
            pen.Width = m_penStyle.size;
            pen.DashStyle = m_penStyle.dash;

            canvas.DrawLine(pen, m_p1, m_p2);
        }

        public void SetPenStyle(float size, Color color, DashStyle dash)
        {
            m_penStyle.size = size;
            m_penStyle.color = color;
            m_penStyle.dash = dash;
        }
    }
}
