using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Drawing
{
    class Square : IShape
    {
        Rectangle m_rect;

        public Pen Pen { get; set; }

        public void Draw(Graphics canvas)
        {
            canvas.DrawRectangle(Pen, m_rect);
        }

        public void CalcRect(Point start, Point end)
        {
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

            //Rectangle square = new Rectangle();
            //square.Location = p1;
            //square.Size = new Size(Math.Abs(p2.X - p1.X), Math.Abs(p2.Y - p1.Y));
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
