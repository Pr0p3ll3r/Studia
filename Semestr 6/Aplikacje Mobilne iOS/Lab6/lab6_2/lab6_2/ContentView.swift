//
//  ContentView.swift
//  lab6_2
//
//  Created by student on 04/04/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    @State private var smakPrzejdz: Bool = false
    @State private var rodzajPrzejdz: Bool = false
    @State var smak: String = ""
    @State var rodzaj: String = ""
    var body: some View {
        VStack {
            Text("Informacje o zamowieniu")
            Text("Smak soku: \(smak)")
            Text("Rodzaj kawy: \(rodzaj)")
            Button(action: {
                self.smakPrzejdz.toggle()
            }, label: {
                Text("Wybierz smak")
            })
            .sheet(isPresented: $smakPrzejdz) {
                SmakView(smak: self.$smak)
            }
            Button(action: {
                self.rodzajPrzejdz.toggle()
            }, label: {
                Text("Wybierz rodzaj")
            })
            .sheet(isPresented: $rodzajPrzejdz) {
                RodzajView(rodzaj: self.$rodzaj)
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
