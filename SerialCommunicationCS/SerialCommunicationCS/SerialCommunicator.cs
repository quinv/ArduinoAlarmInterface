using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;
using System.ComponentModel;

namespace SerialCommunicationCS
{
    class SerialCommunicator
    {
        #region initialize serialPort
        IContainer components = null;
        SerialPort serialPort;
        public SerialCommunicator()
        {
            components = new Container();
            serialPort = new SerialPort(components);
            serialPort.PortName = "COM3";
            serialPort.BaudRate = 9600;
        }
        #endregion
        
        /// <summary>
        /// reads serialPort and returns list of serial communications
        /// </summary>
        /// <returns></returns>
        public List<string> ReadSerialPort()
        {
            List<string> serialPortMessage = new List<string>();
            //checks whether serial port is open in another program
            if (!serialPort.IsOpen)
            {
                try
                {
                    serialPort.Open();
                    serialPortMessage.Add(serialPort.ReadLine());
                    serialPort.Close();
                }
                catch(Exception e)
                {
                    Console.WriteLine(e.Message);
                }
            }
            return serialPortMessage;
        }

        /// <summary>
        /// sends serialMessage to the serial port
        /// </summary>
        /// <param name="serialMessage"></param>
        public void WriteSerialPort(string serialMessage)
        {
            //checks whether serial port is open in another program
            if (!serialPort.IsOpen)
            {
                try
                {
                    serialPort.Open();
                    serialPort.WriteLine(serialMessage);
                    serialPort.Close();
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.Message);
                }
            }
        }
    }
}
