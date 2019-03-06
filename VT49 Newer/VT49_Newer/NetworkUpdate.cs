using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using Xenko.Core.Mathematics;
using Xenko.Input;
using Xenko.Engine;

namespace VT49_Newer
{
    public class NetworkUpdate : SyncScript
    {
        // Declared public member fields and properties will show in the game studio        
        private TcpClient client;
        private NetworkStream stream;
        public Entity Ship { get; set; } = null;

        public override void Start()
        {
            /*
            IPAddress localAdd = IPAddress.Parse("127.0.0.1");
            TcpListener listener = new TcpListener(localAdd, 4949);
            listener.Start();

            TcpClient client = listener.AcceptTcpClient();
            NetworkStream nwStream = client.GetStream();
            byte[] buffer = new byte[client.ReceiveBufferSize];

            int bytesRead = nwStream.Read(buffer, 0, client.ReceiveBufferSize);

            //---convert the data received into a string---
            string dataReceived = Encoding.ASCII.GetString(buffer, 0, bytesRead);
            Console.WriteLine("Received : " + dataReceived);

            //---write back the text to the client---
            Console.WriteLine("Sending back : " + dataReceived);
            nwStream.Write(buffer, 0, bytesRead);
            client.Close();
            listener.Stop();
            Console.ReadLine();
            */

        }

        public override void Update()
        {
            if (Input.IsKeyPressed(Keys.Escape))
                client = null;

            if (Input.IsKeyPressed(Keys.Tab))
            {
                try
                {

                    client = new TcpClient("127.0.0.1", 4949);
                    stream = client.GetStream();
                }
                catch (ArgumentException e)
                {
                    DebugText.Print("Could not connect" + e.Message, new Int2(0, 0));
                    Console.WriteLine("Could not connect" + e.Message);
                }
            }




            // Do stuff every new frame
            if (client != null)
            {
                while (client.Available > 0)
                {
                    byte[] b = new byte[sizeof(float) * 3];
                    stream.Read(b, 0, sizeof(float) * 3);
                    Vector3 pos = new Vector3();
                    pos.X = BitConverter.ToSingle(b, sizeof(float) * 0);
                    pos.Y = BitConverter.ToSingle(b, sizeof(float) * 1);
                    pos.Z = BitConverter.ToSingle(b, sizeof(float) * 2);

                    Ship.Transform.Position = pos;

                    DebugText.Print(BitConverter.ToSingle(b, sizeof(float) * 1).ToString(), new Int2(20, 20), Color4.White);
                }
            }
        }
    }
}
