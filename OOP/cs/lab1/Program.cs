using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ooplab1cs
{
    class Program
    {
        static void Main(string[] args)
        {
            int suma;
            int a = Convert.ToInt32(Console.ReadLine());
            int b = Convert.ToInt32(Console.ReadLine());
            sum(a, b, out suma);
            Console.WriteLine(suma);
            Console.WriteLine(lessThan(a,b));
            Console.ReadLine();
        }
        private static bool checkValue(int a)
        {
            return Convert.ToBoolean(a & (1 << 31));
        }

        private static void sum(int a, int b, out int suma)
        {
            suma = a;
            while (b != 0)
            {
                suma = -~suma;
                b = ~-b;
            }
        }

        private static bool lessThan(int x, int y)
        {
            if (checkValue(x) && !checkValue(y))
                return true;
            else if (!checkValue(x) && checkValue(y))
                return false;
            for (int i = 31; i >= 0; i--)
            {
                int z = 1 << i;
                if ((x & z) != (y & z))
                    if (Convert.ToBoolean(x & z) && !checkValue(x))
                        return false;
                    else
                        return true;
            }
            return false;
        }
    }
}
