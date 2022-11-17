using System;

/*
3,0 2
600000 600000 HUF
-860,4 -100 THB
*/
namespace zh
{
    class Transaction
    {
        public double forintValue;
        public double originalValue;
        public string currency;

        public Transaction(double forintValue, double originalValue, string currency)
        {
            this.forintValue = forintValue;
            this.originalValue = originalValue;
            this.currency = currency;
        }
    }

    internal class Program
    {
        static Transaction[] transactions;
        static double K;

        static void Main(string[] args)
        {
            Read();
            while (true)
            {
                Console.Write("melyik részfeladat [1,2,3,exit] ?: ");
                string input = Console.ReadLine();
                switch (input)
                {
                    case "1":
                        bool v1 = Van(K);
                        if (v1)
                            Console.WriteLine("volt ilyen időszsak;");
                        else
                            Console.WriteLine("nem volt ilyen időszak");
                        break;

                    case "2":
                        Console.WriteLine("milyen pénznem?: ");
                        input = Console.ReadLine();
                        double v2 = ezFt(input);
                        Console.WriteLine("ennyi történt: " + v2);
                        break;
                    case "3":
                        double v3 = AvgTHB();
                        Console.WriteLine("átlagos THB árfolyam: " + v3);
                        break;
                    case "exit":
                        return;
                        break;
                    default:
                        Console.WriteLine("nincs ilyen menüpont");
                        break;
                }
            }
        }
        static void Read()
        {
            string line = Console.ReadLine();
            string[] splitLine = line.Split(" ");
            K = double.Parse(splitLine[0].Replace(",", "."));
            int N = int.Parse(splitLine[1]);

            transactions = new Transaction[N];

            for (int i = 0; i < N; i++)
            {
                line = Console.ReadLine();
                splitLine = line.Split(" ");
                double f = double.Parse(splitLine[0].Replace(",", "."));
                double o = double.Parse(splitLine[1].Replace(",", "."));
                string c = splitLine[2];
                transactions[i] = new Transaction(f, o, c);
            }
        }

        static bool Van(double K)
        {
            int i;
            double Egyenleg;
            i = 0;
            Egyenleg = K;
            while (i < transactions.Length && Egyenleg >=0)
            {
                Egyenleg = Egyenleg + transactions[i].forintValue;
                i = i + 1;
            }
            return Egyenleg < 0;
        }

        static double ezFt(string x)
        {
            int i;
            double szum;
            szum = 0;
            for (i = 0; i < transactions.Length; i++)
            {
                if (transactions[i].currency == x && transactions[i].forintValue < 0)
                {
                    szum = szum + transactions[i].forintValue;
                }
            }
            return -szum;
        }

        static double AvgTHB()
        {
            int i;
            double shuf;
            double sthb;
            shuf = 0;
            sthb = 0;
            for (i = 0; i < transactions.Length; i++)
            {
                if (transactions[i].currency == "THB")
                {
                    shuf = shuf + transactions[i].forintValue;
                    sthb = sthb + transactions[i].originalValue;
                }
            }
            return shuf / sthb;
        }
    }
}