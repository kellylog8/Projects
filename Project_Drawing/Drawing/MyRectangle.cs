using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Drawing;
using System.Drawing.Drawing2D;

namespace Drawing
{
    class MyRectangle : IShape
    {
        Rectangle m_rect;

        PenStyle m_penStyle;

        public void CalcRect(Point start, Point end)
        {
            CalcRect(start, end, out m_rect);
        }

        public void Draw(Graphics canvas)
        {
            Pen pen = new Pen(m_penStyle.color, m_penStyle.size);
            pen.DashStyle = m_penStyle.dash;
            canvas.DrawRectangle(pen, m_rect);
        }

        public void SetPenStyle(float size, Color color, DashStyle dash)
        {
            m_penStyle.size = size;
            m_penStyle.color = color;
            m_penStyle.dash = dash;
        }

        void CalcRect(Point startPos, Point endPos, out Rectangle rect)
        {
            int x = 0, y = 0;

            int movementX = endPos.X - startPos.X;
            int movementY = endPos.Y - startPos.Y;

            if (movementX > 0 && movementY > 0)
            {
                x = startPos.X;
                y = startPos.Y;
            }
            else if (movementX < 0 && movementY > 0)
            {
                x = endPos.X;
                y = startPos.Y;
            }
            else if (movementX > 0 && movementY < 0)
            {
                x = startPos.X;
                y = endPos.Y;
            }
            else if (movementX < 0 && movementY < 0)
            {
                x = endPos.X;
                y = endPos.Y;
            }

            int width = Math.Abs(movementX);
            int height = Math.Abs(movementY);

            rect = new Rectangle(x, y, width, height);
        }

    }
}
