using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Drawing
{
    interface IShape
    {
        Rectangle GetRect(Point start, Point end);
    }
}
