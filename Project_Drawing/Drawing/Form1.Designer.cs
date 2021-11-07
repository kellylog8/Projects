
namespace Drawing
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.panel_shape = new System.Windows.Forms.FlowLayoutPanel();
            this.btn_default = new System.Windows.Forms.Button();
            this.panel_style = new System.Windows.Forms.FlowLayoutPanel();
            this.textBox_penSize = new System.Windows.Forms.TextBox();
            this.btn_brushColor = new System.Windows.Forms.Button();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.btn_solidPen = new System.Windows.Forms.Button();
            this.btn_dotPen = new System.Windows.Forms.Button();
            this.btn_dashdotPen = new System.Windows.Forms.Button();
            this.btn_rectangle = new System.Windows.Forms.Button();
            this.btn_square = new System.Windows.Forms.Button();
            this.btn_triangle = new System.Windows.Forms.Button();
            this.btn_circle = new System.Windows.Forms.Button();
            this.panel_shape.SuspendLayout();
            this.panel_style.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel_shape
            // 
            this.panel_shape.BackColor = System.Drawing.Color.Silver;
            this.panel_shape.Controls.Add(this.btn_default);
            this.panel_shape.Controls.Add(this.btn_rectangle);
            this.panel_shape.Controls.Add(this.btn_square);
            this.panel_shape.Controls.Add(this.btn_triangle);
            this.panel_shape.Controls.Add(this.btn_circle);
            this.panel_shape.Location = new System.Drawing.Point(12, 12);
            this.panel_shape.Name = "panel_shape";
            this.panel_shape.Size = new System.Drawing.Size(56, 426);
            this.panel_shape.TabIndex = 0;
            // 
            // btn_default
            // 
            this.btn_default.Location = new System.Drawing.Point(3, 3);
            this.btn_default.Name = "btn_default";
            this.btn_default.Size = new System.Drawing.Size(50, 50);
            this.btn_default.TabIndex = 0;
            this.btn_default.UseVisualStyleBackColor = true;
            this.btn_default.Click += new System.EventHandler(this.btn_default_Click);
            // 
            // panel_style
            // 
            this.panel_style.BackColor = System.Drawing.Color.Silver;
            this.panel_style.Controls.Add(this.btn_solidPen);
            this.panel_style.Controls.Add(this.btn_dotPen);
            this.panel_style.Controls.Add(this.btn_dashdotPen);
            this.panel_style.Controls.Add(this.textBox_penSize);
            this.panel_style.Controls.Add(this.btn_brushColor);
            this.panel_style.Location = new System.Drawing.Point(732, 12);
            this.panel_style.Name = "panel_style";
            this.panel_style.Size = new System.Drawing.Size(56, 426);
            this.panel_style.TabIndex = 1;
            // 
            // textBox_penSize
            // 
            this.textBox_penSize.Location = new System.Drawing.Point(3, 171);
            this.textBox_penSize.Name = "textBox_penSize";
            this.textBox_penSize.Size = new System.Drawing.Size(50, 21);
            this.textBox_penSize.TabIndex = 1;
            this.textBox_penSize.KeyDown += new System.Windows.Forms.KeyEventHandler(this.textBox_penSize_KeyDown);
            // 
            // btn_brushColor
            // 
            this.btn_brushColor.BackColor = System.Drawing.Color.Black;
            this.btn_brushColor.Location = new System.Drawing.Point(3, 198);
            this.btn_brushColor.Name = "btn_brushColor";
            this.btn_brushColor.Size = new System.Drawing.Size(50, 50);
            this.btn_brushColor.TabIndex = 0;
            this.btn_brushColor.UseVisualStyleBackColor = false;
            this.btn_brushColor.Click += new System.EventHandler(this.btn_brushColor_Click);
            // 
            // btn_solidPen
            // 
            this.btn_solidPen.BackgroundImage = global::Drawing.Properties.Resources.solidline_2;
            this.btn_solidPen.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btn_solidPen.Location = new System.Drawing.Point(3, 3);
            this.btn_solidPen.Name = "btn_solidPen";
            this.btn_solidPen.Size = new System.Drawing.Size(50, 50);
            this.btn_solidPen.TabIndex = 0;
            this.btn_solidPen.UseVisualStyleBackColor = true;
            this.btn_solidPen.Click += new System.EventHandler(this.btn_solidPen_Click);
            // 
            // btn_dotPen
            // 
            this.btn_dotPen.BackgroundImage = global::Drawing.Properties.Resources.dotline_2;
            this.btn_dotPen.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btn_dotPen.Location = new System.Drawing.Point(3, 59);
            this.btn_dotPen.Name = "btn_dotPen";
            this.btn_dotPen.Size = new System.Drawing.Size(50, 50);
            this.btn_dotPen.TabIndex = 0;
            this.btn_dotPen.UseVisualStyleBackColor = true;
            this.btn_dotPen.Click += new System.EventHandler(this.btn_dotPen_Click);
            // 
            // btn_dashdotPen
            // 
            this.btn_dashdotPen.BackgroundImage = global::Drawing.Properties.Resources.dashdotline_2;
            this.btn_dashdotPen.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btn_dashdotPen.Location = new System.Drawing.Point(3, 115);
            this.btn_dashdotPen.Name = "btn_dashdotPen";
            this.btn_dashdotPen.Size = new System.Drawing.Size(50, 50);
            this.btn_dashdotPen.TabIndex = 0;
            this.btn_dashdotPen.UseVisualStyleBackColor = true;
            this.btn_dashdotPen.Click += new System.EventHandler(this.btn_dashdotPen_Click);
            // 
            // btn_rectangle
            // 
            this.btn_rectangle.BackgroundImage = global::Drawing.Properties.Resources.rectangle;
            this.btn_rectangle.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btn_rectangle.Location = new System.Drawing.Point(3, 59);
            this.btn_rectangle.Name = "btn_rectangle";
            this.btn_rectangle.Size = new System.Drawing.Size(50, 50);
            this.btn_rectangle.TabIndex = 0;
            this.btn_rectangle.UseVisualStyleBackColor = true;
            this.btn_rectangle.Click += new System.EventHandler(this.btn_rectangle_Click);
            // 
            // btn_square
            // 
            this.btn_square.BackgroundImage = global::Drawing.Properties.Resources.square;
            this.btn_square.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btn_square.Location = new System.Drawing.Point(3, 115);
            this.btn_square.Name = "btn_square";
            this.btn_square.Size = new System.Drawing.Size(50, 50);
            this.btn_square.TabIndex = 0;
            this.btn_square.UseVisualStyleBackColor = true;
            this.btn_square.Click += new System.EventHandler(this.btn_square_Click);
            // 
            // btn_triangle
            // 
            this.btn_triangle.BackgroundImage = global::Drawing.Properties.Resources.triangle;
            this.btn_triangle.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btn_triangle.Location = new System.Drawing.Point(3, 171);
            this.btn_triangle.Name = "btn_triangle";
            this.btn_triangle.Size = new System.Drawing.Size(50, 50);
            this.btn_triangle.TabIndex = 0;
            this.btn_triangle.UseVisualStyleBackColor = true;
            this.btn_triangle.Click += new System.EventHandler(this.btn_triangle_Click);
            // 
            // btn_circle
            // 
            this.btn_circle.BackgroundImage = global::Drawing.Properties.Resources.circle;
            this.btn_circle.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btn_circle.Location = new System.Drawing.Point(3, 227);
            this.btn_circle.Name = "btn_circle";
            this.btn_circle.Size = new System.Drawing.Size(50, 50);
            this.btn_circle.TabIndex = 0;
            this.btn_circle.UseVisualStyleBackColor = true;
            this.btn_circle.Click += new System.EventHandler(this.btn_circle_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.panel_style);
            this.Controls.Add(this.panel_shape);
            this.KeyPreview = true;
            this.Name = "Form1";
            this.Text = "Painter";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseMove);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseUp);
            this.Resize += new System.EventHandler(this.Form1_Resize);
            this.panel_shape.ResumeLayout(false);
            this.panel_style.ResumeLayout(false);
            this.panel_style.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.FlowLayoutPanel panel_shape;
        private System.Windows.Forms.Button btn_default;
        private System.Windows.Forms.Button btn_rectangle;
        private System.Windows.Forms.Button btn_square;
        private System.Windows.Forms.Button btn_triangle;
        private System.Windows.Forms.Button btn_circle;
        private System.Windows.Forms.FlowLayoutPanel panel_style;
        private System.Windows.Forms.Button btn_solidPen;
        private System.Windows.Forms.Button btn_dotPen;
        private System.Windows.Forms.Button btn_dashdotPen;
        private System.Windows.Forms.TextBox textBox_penSize;
        private System.Windows.Forms.Button btn_brushColor;
        private System.Windows.Forms.ColorDialog colorDialog1;
    }
}

