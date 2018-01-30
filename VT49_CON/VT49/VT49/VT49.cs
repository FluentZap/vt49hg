using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;

namespace VT49
{
    class VT49
    {
        static void Main(string[] args)
        {

            //Application.Exit();
            //Assembly resolve. Loads assemblys from resource files
            AppDomain.CurrentDomain.AssemblyResolve += (sender, arg) =>
            {
                String resourceName = new AssemblyName(Assembly.GetExecutingAssembly().FullName).Name + "." + new AssemblyName(arg.Name).Name + ".dll";
                using (var stream = Assembly.GetExecutingAssembly().GetManifestResourceStream(resourceName))
                {
                    Byte[] assemblyData = new Byte[stream.Length];
                    stream.Read(assemblyData, 0, assemblyData.Length);
                    return Assembly.Load(assemblyData);
                }
            };



            using (Game game = new Game())            
            {
                game.Run(30.0);

            }





        }
    }
}
