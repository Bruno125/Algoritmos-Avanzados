namespace _8Reinas_Visual
{
    partial class frmMain
    {
        /// <summary>
        /// Variable del diseñador requerida.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén utilizando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben eliminar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido del método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMain));
            this.label1 = new System.Windows.Forms.Label();
            this.txtTamanio = new System.Windows.Forms.TextBox();
            this.btnIniciar = new System.Windows.Forms.Button();
            this.imgTablero = new System.Windows.Forms.PictureBox();
            this.listResultados = new System.Windows.Forms.ListBox();
            ((System.ComponentModel.ISupportInitialize)(this.imgTablero)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(96, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Tamaño de tablero";
            // 
            // txtTamanio
            // 
            this.txtTamanio.Location = new System.Drawing.Point(128, 6);
            this.txtTamanio.Name = "txtTamanio";
            this.txtTamanio.Size = new System.Drawing.Size(48, 20);
            this.txtTamanio.TabIndex = 1;
            // 
            // btnIniciar
            // 
            this.btnIniciar.Location = new System.Drawing.Point(182, 4);
            this.btnIniciar.Name = "btnIniciar";
            this.btnIniciar.Size = new System.Drawing.Size(75, 23);
            this.btnIniciar.TabIndex = 2;
            this.btnIniciar.Text = "Iniciar";
            this.btnIniciar.UseVisualStyleBackColor = true;
            this.btnIniciar.Click += new System.EventHandler(this.btnIniciar_Click);
            // 
            // imgTablero
            // 
            this.imgTablero.Image = ((System.Drawing.Image)(resources.GetObject("imgTablero.Image")));
            this.imgTablero.Location = new System.Drawing.Point(182, 44);
            this.imgTablero.Name = "imgTablero";
            this.imgTablero.Size = new System.Drawing.Size(400, 400);
            this.imgTablero.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.imgTablero.TabIndex = 3;
            this.imgTablero.TabStop = false;
            // 
            // listResultados
            // 
            this.listResultados.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.listResultados.FormattingEnabled = true;
            this.listResultados.ItemHeight = 14;
            this.listResultados.Location = new System.Drawing.Point(15, 44);
            this.listResultados.Name = "listResultados";
            this.listResultados.Size = new System.Drawing.Size(161, 396);
            this.listResultados.TabIndex = 5;
            this.listResultados.SelectedIndexChanged += new System.EventHandler(this.listResultados_SelectedIndexChanged);
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(601, 456);
            this.Controls.Add(this.listResultados);
            this.Controls.Add(this.btnIniciar);
            this.Controls.Add(this.txtTamanio);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.imgTablero);
            this.Name = "frmMain";
            this.Text = "8 Reinas";
            ((System.ComponentModel.ISupportInitialize)(this.imgTablero)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtTamanio;
        private System.Windows.Forms.Button btnIniciar;
        private System.Windows.Forms.PictureBox imgTablero;
        private System.Windows.Forms.ListBox listResultados;
    }
}

