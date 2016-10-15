using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace SerialReader
{
    class Program
    {
        static void Main(string[] args)
        {
            System.IO.Ports.SerialPort serialPort;
            System.ComponentModel.IContainer components = null;
            components = new System.ComponentModel.Container();
            serialPort = new System.IO.Ports.SerialPort(components);
            serialPort.PortName = "COM3";
            for (;;)
            {
                if (!serialPort.IsOpen)
                    try
                    {
                        serialPort.Open();
                        Console.WriteLine(serialPort.ReadLine());
                        serialPort.Close();
                    }
                    catch(Exception e)
                    {
                        Console.WriteLine(e.Message);
                    }
                Thread.Sleep(100);
            }
        }
    }
}
