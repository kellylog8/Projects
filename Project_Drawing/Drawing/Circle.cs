using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Drawing
{
    class Circle : IShape
    {
        public Rectangle GetRect(Point start, Point end)
        {
            Rectangle circle = new Rectangle();

            double radian = Math.PI / 180.0;

            int centerX = (end.X + start.X) / 2;
            int centerY = (end.Y + start.Y) / 2;
            double r = Math.Abs(end.X - start.X) / 2.0;



            return circle;
        }

        void CalcCircle(Point center, double radius, double angle, out Point point)
        {
            double radian = Math.PI / 180.0 * angle;

            int x = center.X + (int)(radius * Math.Cos(radian));
            int y = center.Y - (int)(radius * Math.Sin(radian));

            point = new Point(x, y);
        }

    }

}
