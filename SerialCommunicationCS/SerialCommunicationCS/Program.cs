using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

//upload SerialCommunicationArduino.ino before starting

namespace SerialCommunicationCS
{
    class Program
    {
        static bool endProgram = false;
        static void Main(string[] args)
        {
            SerialCommunicator serialCommunicator = new SerialCommunicator();
            string command;
            List <string> serialCommandList = new List<string>();
            while (!endProgram)
            {
                command = "";
                Console.WriteLine("turn led on or off: led,<state>;");
                Console.WriteLine("pulse led: pulse,<frequency>,<repetitions>;");
                Console.WriteLine("play tone: play,<frequency>,<durationMS>;");
                Console.WriteLine("exit: exit || end || stop");
                command = Console.ReadLine();
                command = command.ToLower();
                if (command == "end" || command == "stop" || command == "exit")
                {
                    endProgram = true;
                }
                else if(command.Contains("led") || command.Contains("play") || command.Contains("pulse"))
                {
                    serialCommunicator.WriteSerialPort(command);
                }
                else
                {
                    continue;
                }
                Thread.Sleep(10);
                Console.WriteLine("executing command...");

                for(;;)
                {
                    serialCommandList = serialCommunicator.ReadSerialPort();
                    if (serialCommandList.Count > 0) {
                        if (!serialCommandList[0].Contains("1"))
                        {
                            Console.WriteLine(serialCommandList[0]);
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                serialCommandList = new List<string>();
                Console.WriteLine("ready for next command");
                Thread.Sleep(10);
            }
        }
    }
}
