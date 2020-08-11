using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace KSE_Installer
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult result = openFileDialog1.ShowDialog();
            if(result == DialogResult.OK)
            {
                string path = Path.GetDirectoryName(openFileDialog1.FileName);
                string pluginCFGPath = path + "\\Plugins_x64.cfg";

                if (File.Exists(pluginCFGPath))
                {
                    File.WriteAllText(pluginCFGPath, "PluginFolder=.\\\nPlugin = RenderSystem_Direct3D11_x64\nPlugin = Plugin_ParticleUniverse_x64\nPlugin = Plugin_Terrain_x64\nPlugin = KSE_x64");
                    File.Copy(Path.Combine(Environment.CurrentDirectory, "KSE_x64.dll"), Path.Combine(path, "KSE_x64.dll"), true);

                    label2.ForeColor = Color.Green;
                    label2.Text = "Installed KSE to \"" + path + "\"!";

                }
                else
                {
                    label2.ForeColor = Color.Red;
                    label2.Text = "Could not install KSE to \"" + path + "\". Missing \"Plugins_x64.cfg\"!";
                    return;
                }

                
            }
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            DialogResult result = openFileDialog1.ShowDialog();
            if (result == DialogResult.OK)
            {
                string path = Path.GetDirectoryName(openFileDialog1.FileName);
                string pluginCFGPath = path + "\\Plugins_x64.cfg";

                if (File.Exists(pluginCFGPath))
                {
                    File.WriteAllText(pluginCFGPath, "PluginFolder=.\\\nPlugin = RenderSystem_Direct3D11_x64\nPlugin = Plugin_ParticleUniverse_x64\nPlugin = Plugin_Terrain_x64");
                    File.Delete(Path.Combine(path, "KSE_x64.dll"));

                    label2.ForeColor = Color.Green;
                    label2.Text = "Uninstalled KSE from \"" + path + "\"!";

                }
                else
                {
                    label2.ForeColor = Color.Red;
                    label2.Text = "Could not uninstall KSE from \"" + path + "\". Missing \"Plugins_x64.cfg\"!";
                    return;
                }
            }
        }
    }
}
