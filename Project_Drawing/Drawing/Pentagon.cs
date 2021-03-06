using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Drawing
{
    class Pentagon : IShape
    {
        Point[] m_points;

        PenStyle m_penStyle;

        public void CalcRect(Point start, Point end)
        {
            int centerX = (end.X + start.X) / 2;
            int centerY = (end.Y + start.Y) / 2;
            double r = Math.Abs(end.X - start.X) / 2.0;

            Point center = new Point(centerX, centerY);

            Point p1, p2, p3, p4, p5;
            CalcPointPosition(center, r, 18, out p1);
            CalcPointPosition(center, r, 90, out p2);
            CalcPointPosition(center, r, 162, out p3);
            CalcPointPosition(center, r, 234, out p4);
            CalcPointPosition(center, r, 306, out p5);

            m_points = new Point[] { p1, p2, p3, p4, p5 };
        }

        void CalcPointPosition(Point center, double radius, double angle, out Point point)
        {
            double radian = Math.PI / 180.0 * angle;

            int x = center.X + (int)(radius * Math.Cos(radian));
            int y = center.Y - (int)(radius * Math.Sin(radian));

            point = new Point(x, y);
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
