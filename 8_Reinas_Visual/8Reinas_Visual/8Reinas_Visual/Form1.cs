using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;



namespace _8Reinas_Visual
{
    
    
    public partial class frmMain : Form
    {

        private int TAMANIO_TABLERO;
  

   
        public frmMain()
        {
            InitializeComponent();
            TAMANIO_TABLERO = 8;
            txtTamanio.Text = TAMANIO_TABLERO.ToString();
        }


        private void ImprimeVector(int[] pSolucion) {
            String output="{";
            output=output+pSolucion[0];
            for (int i=1; i<TAMANIO_TABLERO; i++) {
                output = output+","+pSolucion[i].ToString();
            }
            listResultados.Items.Add(output+"}");
        
        }


        private bool IsValid(int[] pSolucion, int pFila, int pColumna)
        {
            if (pSolucion[pFila] == -1)
            {
                for (int i = 0; i < TAMANIO_TABLERO; i++)
                {
                    if (pSolucion[i] == pColumna) return false;
                    if (pSolucion[i] != -1 && (Math.Abs(pFila - i) == Math.Abs(pColumna - pSolucion[i]))) return false;
                }
                return true;

            }
            else return false;        
        }


        private void OchoReinas (int[] pSolucion , int pFila) {
            if (pFila == TAMANIO_TABLERO)
            {
                ImprimeVector(pSolucion);
                return;
            }
            else
            {
                for (int i = 0; i < TAMANIO_TABLERO; i++)
                {
                    if (IsValid(pSolucion, pFila, i))
                    {
                        pSolucion[pFila] = i;
                        OchoReinas(pSolucion, pFila + 1);
                        pSolucion[pFila] = -1;
                    }
                }
            }
        }



        private void btnIniciar_Click(object sender, EventArgs e)
        {
            listResultados.Items.Clear();
            TAMANIO_TABLERO = Convert.ToInt32(txtTamanio.Text);
            
            int[] solucion = new int[8]; //Crea un array de 8
            
            for (int i = 0; i < TAMANIO_TABLERO; i++) {
                solucion[i]=-1;
            }
            OchoReinas(solucion, 0);
        }

        private void listResultados_SelectedIndexChanged(object sender, EventArgs e)
        {
            string temp_sol = listResultados.Items[listResultados.SelectedIndex].ToString();
            temp_sol=temp_sol.Substring(1,TAMANIO_TABLERO*2-1);
            string[] arr = temp_sol.Split(',');

                System.Windows.Forms.PictureBox imgReina;
                imgReina = new System.Windows.Forms.PictureBox();
                imgReina.Image = Image.FromFile(Application.StartupPath + "\\reina.png");
                Bitmap imgTransparente = new Bitmap(imgReina.Image);
                imgTransparente.MakeTransparent(imgTransparente.GetPixel(1, 1));
            
                
            Graphics g = imgTablero.CreateGraphics();
            g.DrawImage(imgTablero.Image, 0, 0, imgTablero.Width, imgTablero.Height);
            for (int i = 0; i < TAMANIO_TABLERO; i++) {
                g.DrawImage(imgTransparente, i * 50, Convert.ToInt32(arr[i]) * 50, 50, 50);
            }
       

        }


    }
}
