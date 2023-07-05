using System.Text;

namespace PasswordGeneratorCS
{
    class Program
    {
        static List<char> chars = new List<char>();

        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("\nWhich other symbols would you like to include? (1=special, 2=numbers, 3=special + numbers)");
                string other = Console.ReadLine();

                addChars(ref chars, other);

                Console.WriteLine("How long would you like your password to be? (1-30)");
                int len = 0;

                if (int.TryParse(Console.ReadLine(), out len))
                {
                    Console.WriteLine($"\n\nHere's your new password: {generatePassword(len)}");
                }
            }
        }

        static string generatePassword(int length)
        {
            StringBuilder sb = new StringBuilder();
            Random rnd = new Random();
            int j = 0;

            while (j < length)
            {
                sb.Append(chars[rnd.Next(0, chars.Count)]);
                j++;
            }

            return sb.ToString();
        }

        static void addChars(ref List<char> chars, string additionals)
        {
            for (char c = 'a'; c <= 'z'; c++)
            {
                chars.Add(c);
            }

            for (char c = 'A'; c <= 'Z'; c++)
            {
                chars.Add(c);
            }

            switch (additionals)
            {
                case "1":
                    for (char c = '!'; c <= '?'; c++)
                    {
                        chars.Add(c);
                    }
                    break;
                case "2":
                    for (char c = '0'; c <= '9'; c++)
                    {
                        chars.Add(c);
                    }
                    break;
                case "3":
                    for (char c = '!'; c <= '?'; c++)
                    {
                        chars.Add(c);
                    }
                    for (char c = '0'; c <= '9'; c++)
                    {
                        chars.Add(c);
                    }
                    break;
                default:
                    Console.WriteLine("\nYour choice didn't meet any of the given choices so I didn't add any special/numberic characters");
                    break;
            }
        }
    }
}