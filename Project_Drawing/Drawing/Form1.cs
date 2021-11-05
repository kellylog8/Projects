using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Drawing
{
    public partial class Form1 : Form
    {
        enum MODE { DEFAULT, RECTANGLE, SQUARE, TRIANGLE, CIRCLE };
        MODE m_mode = MODE.DEFAULT;

        bool m_isClicked = false;

        Point m_start;
        Point m_end;

        Graphics m_graphics;

        List<MyRectangle> m_rectangle = new List<MyRectangle>();
        List<Square> m_square = new List<Square>();
        List<Circle> m_circle = new List<Circle>();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            m_graphics = CreateGraphics();
        }



        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            if (m_mode == MODE.DEFAULT)
                return;

            m_start = e.Location;

            m_isClicked = true;
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (m_mode == MODE.DEFAULT)
                return;

            m_end = e.Location;

            if (m_isClicked)
            {

            }
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            if (m_mode == MODE.DEFAULT)
                return;

            m_end = e.Location;

            switch (m_mode)
            {
                case MODE.RECTANGLE:
                    {
                        MyRectangle rectangle = new MyRectangle();
                        m_rectangle.Add(rectangle);
                        Rectangle rect = rectangle.GetRect(m_start, m_end);
                        m_graphics.DrawRectangle(Pens.Black, rect);
                        break;
                    }
                case MODE.SQUARE:
                    {
                        Square square = new Square();
                        m_square.Add(square);
                        Rectangle rect = square.GetRect(m_start, m_end);
                        m_graphics.DrawRectangle(Pens.Black, rect);
                        break;
                    }
                case MODE.TRIANGLE:
                    break;
                case MODE.CIRCLE:
                    {
                        Circle circle = new Circle();
                        m_circle.Add(circle);
                        Rectangle rect = circle.GetRect(m_start, m_end);
                        m_graphics.DrawPolygon(Pens.Black, );
                    }
                    break;
            }
            

            m_isClicked = false;
        }



        private void Form1_Resize(object sender, EventArgs e)
        {
            Control control = (Control)sender;

            panel_shape.SetBounds(10, 10, 55, control.ClientSize.Height-20);
        }



        private void btn_default_Click(object sender, EventArgs e)
        {
            m_mode = MODE.DEFAULT;
        }

        private void btn_rectangle_Click(object sender, EventArgs e)
        {
            m_mode = MODE.RECTANGLE;
        }

        private void btn_square_Click(object sender, EventArgs e)
        {
            m_mode = MODE.SQUARE;
        }

        private void btn_triangle_Click(object sender, EventArgs e)
        {
            m_mode = MODE.TRIANGLE;
        }

        private void btn_circle_Click(object sender, EventArgs e)
        {
            m_mode = MODE.CIRCLE;
        }

    }
}
