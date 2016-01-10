using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Threading;
using System.Speech.Synthesis;

namespace Alice
{
    class Program
    {
        //
        // Main Function for the the Alice Program
        //
        static void Main(string[] args)
        {
            // Alice greets the new User
            SpeechSynthesizer synth = new SpeechSynthesizer();
            synth.SelectVoiceByHints(VoiceGender.Female);            
            synth.Speak("Hello, my name is Alice. It is a pleasure to meet you");
            Thread.Sleep(400);
            synth.Speak("What can I do for you today?");

            #region My Performance Counters
            // This will pull the current CPU load in percentage
            PerformanceCounter perfCpuCount = new PerformanceCounter("Processor Information", "% Processor Time", "_Total");
            perfCpuCount.NextValue();

            // This will pull the current available Memory
            PerformanceCounter perfMemCount = new PerformanceCounter("Memory", "Available MBytes");
            perfMemCount.NextValue();

            // This will give us the system uptime
            PerformanceCounter perfUptimeCount = new PerformanceCounter("System", "System Up Time");
            perfUptimeCount.NextValue();
            #endregion

            // This will give us the System uptime (in seconds)
            TimeSpan uptimeSpan = TimeSpan.FromSeconds(perfUptimeCount.NextValue());
            string systemUpTimeMessage = string.Format("THe current system up time is {0} days {1} hours {2} minutes {3} seconds", 
                (int)uptimeSpan.TotalDays,
                (int)uptimeSpan.Hours,
                (int)uptimeSpan.Minutes,
                (int)uptimeSpan.Seconds                
                );

            // Tell the user the current system uptime
            synth.Speak(systemUpTimeMessage);

            #region
            // Infinite While Loop
            while(true)
            {
                // Save the current performance values
                int currentCpuPercentage = (int)perfCpuCount.NextValue();
                int currentAvailablMemory = (int)perfMemCount.NextValue();

                // Every 1 second print the CPU load in percentage to the screen
                Console.WriteLine("Cpu Load:    {0}%", currentCpuPercentage);
                Console.WriteLine("Memory Load: {0}MB", currentAvailablMemory);

                // Only speak when the CPU load or Memory load reaches a threshold
                if (currentCpuPercentage > 20)
                {
                    if (currentAvailablMemory > 90)
                    {
                        // Have Alice give a special warning when the CPU load passes 90%
                        string cpuLoadVocalMessage = String.Format("Warning, your current CPU load is {0} percent", currentCpuPercentage);
                        synth.Speak(cpuLoadVocalMessage);
                    }
                    else
                    {
                        // Have Alice Update the user on current CPU Load
                        string cpuLoadVocalMessage = String.Format("The current CPU load is {0} percent", currentCpuPercentage);
                        synth.Speak(cpuLoadVocalMessage);
                    }                    
                } 

                if (currentAvailablMemory < 4096)
                {
                    // Have Alice Update the user on current Memory Available
                    string memLoadVocalMessage = String.Format("The current Memory available is {0} megabytes", currentAvailablMemory / 1024);
                    synth.Speak(memLoadVocalMessage);
                }
                
                // Sleep for 1 second after loading values
                Thread.Sleep(1000);
            } // end of while loop
            #endregion
        }        
    }
}
