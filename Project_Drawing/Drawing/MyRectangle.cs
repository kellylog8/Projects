using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Drawing;

namespace Drawing
{
    class MyRectangle : IShape
    {
        public Rectangle GetRect(Point start, Point end)
        {
            Rectangle rect;
            CalcRect(start, end, out rect);

            return rect;
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
