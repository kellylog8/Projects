using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Drawing.Drawing2D;

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

        List<IShape> m_list = new List<IShape>();
        int m_count = 0;

        Pen m_pen;

        Color m_color;
        float m_penSize;
        DashStyle m_dashStyle;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            m_graphics = CreateGraphics();

            m_penSize = 1.0f;
            m_color = Color.Black;
            m_dashStyle = DashStyle.Solid;

            m_pen = new Pen(m_color, m_penSize);
            m_pen.DashStyle = m_dashStyle;
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
                        rectangle.CalcRect(m_start, m_end);

                        rectangle.SetPenStyle(m_penSize, m_color, m_dashStyle);
                        rectangle.Draw(m_graphics);

                        m_list.RemoveRange(m_count, m_list.Count - m_count);
                        m_list.Add(rectangle);
                        m_count++;
                        break;
                    }
                case MODE.SQUARE:
                    {
                        Square square = new Square();
                        square.CalcRect(m_start, m_end);

                        square.SetPenStyle(m_penSize, m_color, m_dashStyle);
                        square.Draw(m_graphics);

                        m_list.RemoveRange(m_count, m_list.Count - m_count);
                        m_list.Add(square);
                        m_count++;
                        break;
                    }
                case MODE.TRIANGLE:
                    break;
                case MODE.CIRCLE:
                    {
                        Circle circle = new Circle();
                        circle.CalcRect(m_start, m_end);

                        circle.SetPenStyle(m_penSize, m_color, m_dashStyle);
                        circle.Draw(m_graphics);

                        m_list.RemoveRange(m_count, m_list.Count - m_count);
                        m_list.Add(circle);
                        m_count++;
                        break;
                    }
            }

            Console.WriteLine("list count : " + m_list.Count);

            m_isClicked = false;
        }



        private void Form1_Resize(object sender, EventArgs e)
        {
            Control control = (Control)sender;

            panel_shape.SetBounds(10, 10, 55, control.ClientSize.Height-20);

            if (m_graphics != null)
            {
                m_graphics.Dispose();
                m_graphics = CreateGraphics();
                ReDraw();
            }
            
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



        private void ReDraw(bool isClear = true)
        {
            if (isClear)
                m_graphics.Clear(BackColor);

            for (int i = 0; i < m_count; i++)
            {
                m_list[i].Draw(m_graphics);
            }
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.R)
            {
                Console.WriteLine("R key");
                m_graphics.Clear(BackColor);
            }
            else if (e.KeyCode == Keys.T)
            {
                ReDraw(false);
            }
            else if (e.Control && e.Shift && e.KeyCode == Keys.Z)
            {
                Console.WriteLine("Redo : Ctrl + Shift + Z key");

                m_count++;
                if (m_count > m_list.Count)
                    m_count = m_list.Count;

                ReDraw();
            }
            else if (e.Control && e.KeyCode == Keys.Z)
            {
                Console.WriteLine("Undo : Ctrl + Z key");

                m_count--;
                if (m_count < 0)
                    m_count = 0;

                ReDraw();
            }

        }



        private void btn_solidPen_Click(object sender, EventArgs e)
        {
            m_dashStyle = DashStyle.Solid;

            //m_pen.Color = m_color;
            //m_pen.Width = m_penSize;
            //m_pen.DashStyle = m_dashStyle;
        }

        private void btn_dotPen_Click(object sender, EventArgs e)
        {
            m_dashStyle = DashStyle.Dot;

            //m_pen.Color = m_color;
            //m_pen.Width = m_penSize;
            //m_pen.DashStyle = m_dashStyle;
        }

        private void btn_dashdotPen_Click(object sender, EventArgs e)
        {
            m_dashStyle = DashStyle.DashDot;

            //m_pen.Color = m_color;
            //m_pen.Width = m_penSize;
            //m_pen.DashStyle = m_dashStyle;
        }

        private void textBox_penSize_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                float penSize = float.Parse(textBox_penSize.Text);
                if (penSize < 0.0f)
                    penSize = 0.0f;

                m_penSize = penSize;

                m_pen.Width = m_penSize;
            }
        }

        private void btn_brushColor_Click(object sender, EventArgs e)
        {
            DialogResult result = colorDialog1.ShowDialog();

            if (result == DialogResult.OK)
            {
                btn_brushColor.BackColor = colorDialog1.Color;

                m_color = colorDialog1.Color;
                m_pen.Color = m_color;
            }

        }

    }
}
