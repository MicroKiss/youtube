using System;
using System.Linq;
using System.Collections.Generic;

namespace final
{
    /*
5 CRO
BEL BUL 3 0
HUN CRO 2 2
CRO MOR 3 2
LUX ITA 0 5
USA BEL 1 5
    */
    class Game
    {
        public string first;
        public string second;
        public int firstGoals;
        public int secondGoals;

        public Game (string first, string second, int firstGoals, int secondGoals)
        {
            this.first = first;
            this.second = second;
            this.firstGoals = firstGoals;
            this.secondGoals = secondGoals;
        }
    }

    internal class Program
    {
        static (string, Game[]) Read ()
        {
            string[] line = Console.ReadLine().Split(" ");
            int gamesCount = int.Parse(line[0]);
            string param = line[1];
            Game[] games = new Game[gamesCount];

            for (int i = 0; i < gamesCount; i++) {
                line = Console.ReadLine().Split(" ");
                games[i] = new Game(line[0], line[1], int.Parse(line[2]), int.Parse(line[3]));
            }

            return (param, games);
        }

        static void B (Game[] games)
        {
            List<string> list = new List<string>();
            foreach (var g in games) {
                if (g.firstGoals > g.secondGoals) {
                    list.Add(g.first);
                } else if (g.firstGoals < g.secondGoals) {
                    list.Add(g.second);
                }
            }

            Console.WriteLine("#");
            Console.Write(list.Distinct().Count() + " ");
            Console.WriteLine(string.Join(" ", list.Distinct()));
        }

        static void A (Game[] games)
        {
            int maxValue = -1;
            string team = "";
            foreach (var g in games) {
                if (g.firstGoals > maxValue) {
                    maxValue = g.firstGoals;
                    team = g.first;
                }
                if (g.secondGoals > maxValue) {
                    maxValue = g.secondGoals;
                    team = g.second;
                }
            }

            Console.WriteLine("#");
            Console.WriteLine(team);
        }

        static void C (Game[] games)
        {
            HashSet<string> teams = new HashSet<string>();
            foreach (var g in games) {
                teams.Add(g.first);
                teams.Add(g.second);
            }

            Console.WriteLine("#");
            Console.WriteLine(teams.Count());
        }

        static void D (Game[] games, string param)
        {
            int given = 0;
            int got = 0;
            int score = 0;

            foreach (var g in games) {
                if (g.first == param) {
                    given += g.firstGoals;
                    got += g.secondGoals;
                    if (g.firstGoals > g.secondGoals)
                        score += 3;
                    else if (g.firstGoals == g.secondGoals)
                        score++;
                } else if (g.second == param) {
                    given += g.secondGoals;
                    got += g.firstGoals;
                    if (g.firstGoals < g.secondGoals)
                        score += 3;
                    else if (g.firstGoals == g.secondGoals)
                        score++;
                }
            }

            Console.WriteLine("#");
            Console.WriteLine(given + " " + got + " " + score);
        }

        static void E (Game[] games)
        {
            int c = 0;
            string[] teams = new string[games.Length * 2];
            int[] teamsCount = new int[games.Length * 2];

            for (int i = 0; i < games.Length; i++) {
                bool foundFirst = false;
                bool foundSecond = false;
                for (int j = 0; j < c; j++) {
                    if (teams[j] == games[i].first) {
                        foundFirst = true;
                        teamsCount[j]++;
                    } else if (teams[j] == games[i].second) {
                        foundSecond = true;
                        teamsCount[j]++;
                    }
                }
                if (!foundFirst) {
                    teams[c] = games[i].first;
                    teamsCount[c]++;
                    c++;
                }
                if (!foundSecond) {
                    teams[c] = games[i].second;
                    teamsCount[c]++;
                    c++;
                }
            }

            Console.WriteLine("#");
            for (int i = 0; i < c; i++) {
                Console.WriteLine(teams[i] + " " + teamsCount[i]);
            }
        }

        static void Main (string[] args)
        {
            (string param, Game[] games) = Read();
            A(games);
            B(games);
            C(games);
            D(games, param);
            E(games);
        }
    }
}