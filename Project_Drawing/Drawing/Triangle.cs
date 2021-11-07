using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Drawing
{
    class Triangle : IShape
    {
        PenStyle m_penStyle;

        Point[] m_points;

        public void CalcRect(Point start, Point end)
        {
            //Point p1, p2;
            //CalcRect(start, end, out p1, out p2);
            //
            //m_points = new Point[3];
            //m_points[0] = new Point(p1.X, p2.Y);
            //m_points[1] = new Point(p1.X + Math.Abs(p2.X - p1.X) / 2, p1.Y);
            //m_points[2] = p2;

            Point p1 = new Point(start.X, end.Y);
            Point p2 = new Point((start.X + end.X) / 2, start.Y);
            Point p3 = end;

            m_points = new Point[3] { p1, p2, p3 };
        }

        public void Draw(Graphics canvas, Pen pen)
        {
            pen.Color = m_penStyle.color;
            pen.Width = m_penStyle.size;
            pen.DashStyle = m_penStyle.dash;

            if (m_points == null)
                return;
            canvas.DrawPolygon(pen, m_points);
        }

        public void SetPenStyle(float size, Color color, DashStyle dash)
        {
            m_penStyle.size = size;
            m_penStyle.color = color;
            m_penStyle.dash = dash;
        }

        void CalcRect(Point startPos, Point endPos, out Point p1, out Point p2)
        {
            p1 = new Point();
            p2 = new Point();

            int movementX = endPos.X - startPos.X;
            int movementY = endPos.Y - startPos.Y;

            if (movementX > 0 && movementY > 0)
            {
                p1.X = startPos.X;
                p1.Y = startPos.Y;
                p2.X = endPos.X;
                p2.Y = endPos.Y;
            }
            else if (movementX < 0 && movementY > 0)
            {
                p1.X = endPos.X;
                p1.Y = startPos.Y;
                p2.X = startPos.X;
                p2.Y = endPos.Y;
            }
            else if (movementX > 0 && movementY < 0)
            {
                p1.X = startPos.X;
                p1.Y = endPos.Y;
                p2.X = endPos.X;
                p2.Y = startPos.Y;
            }
            else if (movementX < 0 && movementY < 0)
            {
                p1.X = endPos.X;
                p1.Y = endPos.Y;
                p2.X = startPos.X;
                p2.Y = startPos.Y;
            }

        }
    }
}
