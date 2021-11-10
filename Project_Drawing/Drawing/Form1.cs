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
        enum MODE { DEFAULT, RECTANGLE, SQUARE, TRIANGLE, CIRCLE, LINE, PENTAGON, STAR };
        MODE m_mode = MODE.DEFAULT;

        bool m_isClicked = false;

        Point m_start;
        Point m_end;

        List<IShape> m_list = new List<IShape>();
        int m_count = 0;

        Pen m_pen;

        float m_penSize;
        Color m_color;
        DashStyle m_dashStyle;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            m_penSize = 1.0f;
            m_color = Color.Black;
            m_dashStyle = DashStyle.Solid;

            m_pen = new Pen(m_color, m_penSize);
            m_pen.DashStyle = m_dashStyle;

            textBox_penSize.Text = m_penSize.ToString();
            DoubleBuffered = true;
        }


        private void canvas_Paint(object sender, PaintEventArgs e)
        {
            if (m_isClicked)
            {
                //Console.WriteLine("---PAINT---");

                ReDraw(e.Graphics);
                
                if (m_mode == MODE.LINE)
                {
                    Line line = new Line();
                    line.CalcRect(m_start, m_end);

                    line.SetPenStyle(2.0f, Color.LightGray, DashStyle.Dot);
                    line.Draw(e.Graphics, m_pen);
                }
                if (m_mode == MODE.PENTAGON)
                {
                    Pentagon pentagon = new Pentagon();
                    //pentagon.CalcRect(m_start, m_end);

                    pentagon.SetPenStyle(2.0f, Color.LightGray, DashStyle.Dot);
                    //pentagon.Draw(e.Graphics, m_pen);
                }
                if (m_mode == MODE.STAR)
                {
                    Star star = new Star();
                    star.CalcRect(m_start, m_end);

                    star.SetPenStyle(2.0f, Color.LightGray, DashStyle.Dot);
                    star.Draw(e.Graphics, m_pen);
                }
                else
                {
                    MyRectangle rectangle = new MyRectangle();
                    rectangle.CalcRect(m_start, m_end);

                    rectangle.SetPenStyle(2.0f, Color.LightGray, DashStyle.Dot);
                    rectangle.Draw(e.Graphics, m_pen);
                }

                return;
            }

            ReDraw(e.Graphics);

        }

        private void canvas_MouseDown(object sender, MouseEventArgs e)
        {
            if (m_mode == MODE.DEFAULT)
                return;

            m_start = e.Location;

            m_isClicked = true;
        }

        private void canvas_MouseMove(object sender, MouseEventArgs e)
        {
            if (m_mode == MODE.DEFAULT)
                return;

            m_end = e.Location;

            if (m_isClicked)
            {
                canvas.Refresh();
            }

        }

        private void canvas_MouseUp(object sender, MouseEventArgs e)
        {
            if (m_mode == MODE.DEFAULT)
                return;

            m_end = e.Location;

            IShape temp;

            switch (m_mode)
            {
                case MODE.LINE:
                    temp = new Line();
                    break;
                case MODE.RECTANGLE:
                    temp = new MyRectangle();
                    break;
                case MODE.SQUARE:
                    temp = new Square();
                    break;
                case MODE.TRIANGLE:
                    temp = new Triangle();
                    break;
                case MODE.CIRCLE:
                    temp = new Circle();
                    break;
                case MODE.PENTAGON:
                    temp = new Pentagon();
                    break;
                case MODE.STAR:
                    temp = new Star();
                    break;
                default:
                    return;
            }

            temp.CalcRect(m_start, m_end);

            temp.SetPenStyle(m_penSize, m_color, m_dashStyle);

            m_list.RemoveRange(m_count, m_list.Count - m_count);
            m_list.Add(temp);
            m_count++;


            Console.WriteLine("list count : " + m_list.Count);

            m_isClicked = false;
            canvas.Refresh();
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            Control control = (Control)sender;

            int marginX = 10;
            int marginY = 10;
            int panelWidth = 55;

            panel_shape.SetBounds(marginX, marginY, panelWidth, control.ClientSize.Height - marginY * 2);
            panel_style.SetBounds(ClientSize.Width - marginX - panelWidth, marginY, panelWidth, ClientSize.Height - 20);

            int canvasMarginX = marginX + panelWidth + marginX;
            canvas.SetBounds(canvasMarginX, marginY, ClientSize.Width - canvasMarginX * 2, ClientSize.Height - marginY * 2);

            canvas.Refresh();
        }



        private void btn_default_Click(object sender, EventArgs e)
        {
            m_mode = MODE.DEFAULT;
        }

        private void btn_line_Click(object sender, EventArgs e)
        {
            m_mode = MODE.LINE;
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

        private void btn_pentagon_Click(object sender, EventArgs e)
        {
            m_mode = MODE.PENTAGON;
        }

        private void btn_star_Click(object sender, EventArgs e)
        {
            m_mode = MODE.STAR;
        }



        private void ReDraw(Graphics graphics, bool isClear = true)
        {
            if (isClear)
                graphics.Clear(BackColor);

            for (int i = 0; i < m_count; i++)
            {
                m_list[i].Draw(graphics, m_pen);
            }

        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.R)
            {
                Console.WriteLine("R key");

                canvas.CreateGraphics().Clear(BackColor);
            }
            else if (e.KeyCode == Keys.T)
            {
                //ReDraw(false);
                canvas.Refresh();
            }
            else if (e.Control && e.Shift && e.KeyCode == Keys.Z)
            {
                Console.WriteLine("Redo : Ctrl + Shift + Z key");

                m_count++;
                if (m_count > m_list.Count)
                    m_count = m_list.Count;

                //ReDraw();
                canvas.Refresh();
            }
            else if (e.Control && e.KeyCode == Keys.Z)
            {
                Console.WriteLine("Undo : Ctrl + Z key");

                m_count--;
                if (m_count < 0)
                    m_count = 0;

                //ReDraw();
                canvas.Refresh();
            }

        }


        private void btn_solidPen_Click(object sender, EventArgs e)
        {
            m_dashStyle = DashStyle.Solid;
        }

        private void btn_dotPen_Click(object sender, EventArgs e)
        {
            m_dashStyle = DashStyle.Dot;
        }

        private void btn_dashdotPen_Click(object sender, EventArgs e)
        {
            m_dashStyle = DashStyle.DashDot;
        }


        private void textBox_penSize_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                float penSize = 1.0f;
                bool isNumber = float.TryParse(textBox_penSize.Text, out penSize);

                if (!isNumber)
                {
                    textBox_penSize.Text = m_penSize.ToString();
                    return;
                }

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
