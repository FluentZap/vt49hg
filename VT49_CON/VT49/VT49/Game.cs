using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OpenTK;
using OpenTK.Graphics.OpenGL;
using System.Drawing;

namespace VT49
{
    class Game : GameWindow
    {

        
        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);
            Title = "VT49";
            GL.ClearColor(Color.CornflowerBlue);
        }


        protected override void OnRenderFrame(FrameEventArgs e)
        {
            base.OnRenderFrame(e);
            GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);

            SwapBuffers();
        }


    }
    
}
