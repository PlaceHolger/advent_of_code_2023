namespace Day2_CS
{
    using System;

    internal class Program
    {
        static void Main(string[] args)
        {
            var inputData = Data.s_Data;

            int sumInvalid = 0;
            int sumAll = 0;
            for (var index = 0; index < inputData.Length; index++)
            {
                sumAll += index + 1;
                var currentLine = inputData[index];
                var drawStrings = currentLine.Split(new char[] { ',', ';' });
                foreach (var currentDraw in drawStrings)
                {
                    var numberAndColor = currentDraw.Split(' ', StringSplitOptions.RemoveEmptyEntries);
                    int number = int.Parse(numberAndColor[0]);
                    string color = numberAndColor[1];
                    if (color == "red")
                        number += 2;
                    else if (color == "green")
                        number += 1;
                    if (number > 14)
                    {
                        Console.WriteLine("Invalid number in row: " + (index + 1));
                        sumInvalid += index + 1;
                        break;
                    }
                }
            }

            Console.WriteLine("Day 1 Sum: " + (sumAll - sumInvalid));

            int sumPowers = 0;

            for (var index = 0; index < inputData.Length; index++)
            {
                int[] maxCubes = new int[3];
                var currentLine = inputData[index];
                var drawStrings = currentLine.Split(new char[] { ',', ';' });
                foreach (var currentDraw in drawStrings)
                {
                    var numberAndColor = currentDraw.Split(' ', StringSplitOptions.RemoveEmptyEntries);
                    int number = int.Parse(numberAndColor[0]);
                    string color = numberAndColor[1];
                    if (color == "red")
                        maxCubes[0] = Math.Max(maxCubes[0], number);
                    else if (color == "green")
                        maxCubes[1] = Math.Max(maxCubes[1], number);
                    else if (color == "blue")
                        maxCubes[2] = Math.Max(maxCubes[2], number);
                }
                sumPowers += maxCubes[0] * maxCubes[1] * maxCubes[2];
            }
            Console.WriteLine("Day 2 Sum: " + (sumPowers));
        }
    }
}
