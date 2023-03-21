//
//  ContentView.swift
//  Lab3_2
//
//  Created by student on 21/03/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    @State var wybranyRozmiar: Int = 0
    @State var wybranyProducent: Int = 0
    @State var wybranaIlosc: String = ""
    var magazyn = [[5,10,15], [1,2,3], [10,20,30]]
    var body: some View {
        VStack {
            Picker("Producent", selection: $wybranyProducent) {
                Text("Producent 1").tag(0)
                Text("Producent 2").tag(1)
                Text("Producent 3").tag(2)
            }
            Picker("Rozmiar", selection: $wybranyRozmiar) {
                Text("18").tag(0)
                Text("19").tag(1)
                Text("20").tag(2)
            }
            TextField("Wpisz ilosc opon", text: $wybranaIlosc)
            if(wybranaIlosc != "")
            {
                if(magazyn[wybranyProducent][wybranyRozmiar] >= Int(wybranaIlosc)!)
                {
                    Text("Wybrana ilosc opon jest dostepna")
                }
                else
                {
                    Text("Wybrana ilosc opon nie jest dostepna")
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
