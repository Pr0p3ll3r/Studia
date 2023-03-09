using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Reflection.PortableExecutable;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Linq;
using System.Xml.XPath;

namespace IS_Lab1_XML
{
    internal class XMLReadWithXLSTDOM
    {
        internal static void NajwiekszyProducent(string postac, XPathNavigator navigator, XmlNamespaceManager manager)
        {
            Dictionary<string, int> liczbaProduktow = new Dictionary<string, int>();
            XPathExpression query2 = navigator.Compile("/x:produktyLecznicze/x:produktLeczniczy[@postac = '" + postac + "']");
            query2.SetContext(manager);
            XPathNodeIterator NodeIter = navigator.Select(query2);
            while (NodeIter.MoveNext())
            {
                XPathNavigator node = NodeIter.Current;
                string podmiot = node.GetAttribute("podmiotOdpowiedzialny", "");
                if (!liczbaProduktow.TryAdd(podmiot, 1))
                    liczbaProduktow[podmiot]++;
            };
            Console.WriteLine("Najwiecej \"{0}\" produkuje {1}", postac, liczbaProduktow.First(x => x.Value == liczbaProduktow.Max(x => x.Value)).Key);
        }

        internal static void TrzechNajwiekszych(string postac, XPathNavigator navigator, XmlNamespaceManager manager)
        {
            Dictionary<string, int> liczbaProduktow = new Dictionary<string, int>();
            XPathExpression query2 = navigator.Compile("/x:produktyLecznicze/x:produktLeczniczy[@postac = '" + postac + "']");
            query2.SetContext(manager);
            XPathNodeIterator NodeIter = navigator.Select(query2);
            while (NodeIter.MoveNext())
            {
                XPathNavigator node = NodeIter.Current;
                string podmiot = node.GetAttribute("podmiotOdpowiedzialny", "");
                if (!liczbaProduktow.TryAdd(podmiot, 1))
                    liczbaProduktow[podmiot]++;
            };
            var trzech = liczbaProduktow.OrderByDescending(x => x.Value).Take(3);
            Console.WriteLine($"Trzech produkujących najwięcej \"{postac}\"");
            foreach (var item in trzech)
            {
                Console.WriteLine(item.Key + ": " + item.Value);
            }
        }

        internal static void Read(string filepath)
        {
            XPathDocument document = new XPathDocument(filepath);
            XPathNavigator navigator = document.CreateNavigator();
            XmlNamespaceManager manager = new XmlNamespaceManager(navigator.NameTable);
            manager.AddNamespace("x","http://rejestrymedyczne.ezdrowie.gov.pl/rpl/eksport-danych-v1.0");
            XPathExpression query = navigator.Compile("/x:produktyLecznicze/x:produktLeczniczy[@postac = 'Krem' and @nazwaPowszechnieStosowana = 'Mometasoni furoas']");
            query.SetContext(manager);
            int count = navigator.Select(query).Count;
            Console.WriteLine("Liczba produktów leczniczych w postaci kremu, których jedyną substancją czynną jest Mometasoni furoas {0}", count);
            NajwiekszyProducent("Krem", navigator, manager);
            NajwiekszyProducent("Tabletki", navigator, manager);
            TrzechNajwiekszych("Krem", navigator, manager);
        }
    }
}
