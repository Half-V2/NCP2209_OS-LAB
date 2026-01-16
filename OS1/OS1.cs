using System;
using System.Diagnostics;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine($"Process ID is: {Process.GetCurrentProcess().Id}");

        var process = new Process
        {
            StartInfo = new ProcessStartInfo
            {
                FileName = "whoami",
                UseShellExecute = false,
            }
        };

        process.Start();
        process.WaitForExit();
    }
}
