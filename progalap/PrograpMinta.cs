using System;

//ELTE IK
//Programozási alapismeretek EA+GY (IK-19fszPAEG)
//2022 I. félév

/*
 Név asd
NK asd

3
10 10
12 11
4 0
 */

class Measurement
{
    public int total;
    public int positive;
}


namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Measurement[] measurements = ReadInput();

            int v1 = A(measurements);
            
            if (v1 == -1)
                Console.WriteLine("a) Még nem történt ilyen.");
            else
                Console.WriteLine("a) " + (v1 + 1) + "-adik/edik nap volt az első ilyen.");


            double v2 = B(measurements);
            Console.WriteLine("b) " +v2 +"% -a ferzőzött az embereknek.");

            double v3 = C(measurements);
            if (v3 == -1)
                Console.WriteLine("c) Még nem kezdődött el a felmérés.");
            else
                Console.WriteLine("c) " + (v3 + 1) + "-adik/edik nap volt a kiemelkedő.");
        }


        static Measurement[] ReadInput()
        {
            int N;
            string line = Console.ReadLine();
            N = int.Parse(line);

            Measurement[] measurements = new Measurement[N];

            for (int i = 0; i < N; i++)
            {
                line = Console.ReadLine();
                string[] fields = line.Split(" ");
                measurements[i] = new Measurement();
                measurements[i].total = int.Parse(fields[0]);
                measurements[i].positive = int.Parse(fields[1]);
            }

            return measurements;
        }

        static int A(Measurement[] measurements)
        {
            int i = 0;
            while (i < measurements.Length && measurements[i].positive <= 10)
            {
                i = i + 1;
            }
            if (i < measurements.Length)
                return i;
            else
                return -1;
        }

        static double B(Measurement[] measurements)
        {
            int i;
            int x = 0;
            int y = 0;
            for (i = 0; i < measurements.Length; i++)
            {
                x = x + measurements[i].positive;
                y = y + measurements[i].total;
            }

            return Convert.ToDouble(x) / y * 100.0;
        }

        static int C(Measurement[] measurements)
        {
            int i;
            int v;
            if (measurements.Length > 0)
            {
                v = 0;
                for (i = 1; i < measurements.Length; i++)
                {
                    if (measurements[i].positive > measurements[v].positive)
                        v = i;
                }
            }
            else
            {
                v = -1;
            }
            return v;
        }
    }
}