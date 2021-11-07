using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Drawing
{
    class Circle : IShape
    {
        Rectangle m_rect;

        PenStyle m_penStyle;

        public void CalcRect(Point start, Point end)
        {
            //double radian = Math.PI / 180.0;
            //
            //int centerX = (end.X + start.X) / 2;
            //int centerY = (end.Y + start.Y) / 2;
            //double r = Math.Abs(end.X - start.X) / 2.0;

            Point p1, p2;
            CalcRect(start, end, out p1, out p2);


            int width = Math.Abs(p2.X - p1.X);
            int height = Math.Abs(p2.Y - p1.Y);

            int length = width;

            if (width < height)
            {
                length = width;
            }
            else if (width > height)
            {
                length = height;
            }

            m_rect = new Rectangle(p1.X, p1.Y, length, length);
        }

        public void Draw(Graphics canvas, Pen pen)
        {
            pen.Color = m_penStyle.color;
            pen.Width = m_penStyle.size;
            pen.DashStyle = m_penStyle.dash;

            canvas.DrawArc(pen, m_rect, 0.0f, 360.0f);
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
