using ServiceReference1;

namespace IS_Lab5_SOAPCS
{
    internal class Program
    {
        static async Task Main(string[] args)
        {
            Console.WriteLine("My First SOAP Client!");
            
            MyFirstSOAPInterfaceClient client = new MyFirstSOAPInterfaceClient();
            
            string text = await
            client.getHelloWorldAsStringAsync("Karol");
            Console.WriteLine(text);
            
            long days = await
            client.getDaysBetweenDatesAsync("10 04 2023", "12 04 2023");
            Console.WriteLine(days);
        }
    }
}