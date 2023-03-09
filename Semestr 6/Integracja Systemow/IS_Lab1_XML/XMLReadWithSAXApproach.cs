using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace IS_Lab1_XML
{
    internal class XMLReadWithSAXApproach
    {
        internal static void IlePreparatowRoznaPostac(List<(string, string)> preparaty)
        {
            HashSet<(string, string)> unikatowePreparaty = new HashSet<(string, string)>();
            Dictionary<string, int> liczbaPostaciPreparatow = new Dictionary<string, int>();
            foreach (var preparat in preparaty)
            {
                unikatowePreparaty.Add(preparat);
            }
            foreach (var unikat in unikatowePreparaty)
            {
                if (!liczbaPostaciPreparatow.TryAdd(unikat.Item1, 1))
                    liczbaPostaciPreparatow[unikat.Item1]++;
            }
            Console.WriteLine("Liczba preparatów leczniczych o takiej samej nazwie powszechnej, pod różnymi postaciami {0}", liczbaPostaciPreparatow.Count(x => x.Value > 1));
        }

        internal static void NajwiekszyProducent(string postac, List<(string, string)> podmioty)
        {
            Dictionary<string, int> liczbaProduktow = new Dictionary<string, int>();
            foreach (var podmiot in podmioty)
            {
                if (podmiot.Item2 == postac && !liczbaProduktow.TryAdd(podmiot.Item1, 1))
                    liczbaProduktow[podmiot.Item1]++;
            }
            Console.WriteLine("Najwiecej \"{0}\" produkuje {1}", postac, liczbaProduktow.First(x => x.Value == liczbaProduktow.Max(x => x.Value)).Key);
        }

        internal static void TrzechNajwiekszych(string postac, List<(string, string)> podmioty)
        {
            Dictionary<string, int> liczbaProduktow = new Dictionary<string, int>();
            foreach (var podmiot in podmioty)
            {
                if (podmiot.Item2 == postac && !liczbaProduktow.TryAdd(podmiot.Item1, 1))
                    liczbaProduktow[podmiot.Item1]++;
            }
            var trzech = liczbaProduktow.OrderByDescending(x => x.Value).Take(3);
            Console.WriteLine($"Trzech produkujących najwięcej \"{postac}\"");
            foreach (var item in trzech)
            {
                Console.WriteLine(item.Key + ": " + item.Value);
            }
        }

        internal static void Read(string filepath)
        {
            // konfiguracja początkowa dla XmlReadera
            XmlReaderSettings settings = new XmlReaderSettings();
            settings.IgnoreComments = true;
            settings.IgnoreProcessingInstructions = true;
            settings.IgnoreWhitespace = true;
            // odczyt zawartości dokumentu
            XmlReader reader = XmlReader.Create(filepath, settings);
            // zmienne pomocnicze
            int count = 0;
            string postac = "";
            string sc = "";
            string podmiot = "";
            List<(string, string)> preparaty = new List<(string, string)>();
            List<(string, string)> podmioty = new List<(string, string)>();
            reader.MoveToContent();
            // analiza każdego z węzłów dokumentu
            while (reader.Read())
            {
                if (reader.NodeType == XmlNodeType.Element && reader.Name == "produktLeczniczy")
                {
                    postac = reader.GetAttribute("postac");
                    sc = reader.GetAttribute("nazwaPowszechnieStosowana");
                    if (postac == "Krem" && sc == "Mometasoni furoas")
                        count++;

                    preparaty.Add((sc, postac));

                    podmiot = reader.GetAttribute("podmiotOdpowiedzialny");
                    podmioty.Add((podmiot, postac));
                }
            }
            Console.WriteLine("Liczba produktów leczniczych w postaci kremu, których jedyną substancją czynną jest Mometasoni furoas {0}", count);
            IlePreparatowRoznaPostac(preparaty);
            NajwiekszyProducent("Krem", podmioty);
            NajwiekszyProducent("Tabletki", podmioty);
            TrzechNajwiekszych("Krem", podmioty);
        }
    }
}
