//
//  ContentView.swift
//  lab6_3
//
//  Created by student on 04/04/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    @State private var wybierzAutora: Bool = false
    @State var autor: String = ""
    var ksiazki = [
        Book(autor: "Sienkiewicz", tytul: "Potop", iloscEgzemplarzy: 5),
        Book(autor: "Mickiewicz", tytul: "Pan Tadeusz", iloscEgzemplarzy: 2)
    ]
    var body: some View {
        VStack {
            Button(action: {
                self.wybierzAutora.toggle()
            }, label: {
                Text("Wybierz autora")
            })
            .sheet(isPresented: $wybierzAutora) {
                SecondView(autor: self.$autor)
            }
            Text("Dostepne ksiazki:")
            ForEach(self.ksiazki, id:\.self) { ksiazka in
                VStack {
                    if(ksiazka.autor == self.autor)
                    {
                        Text("\(ksiazka.autor) \(ksiazka.tytul) - \(ksiazka.iloscEgzemplarzy)")
                    }
                }
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
