//
//  ContentView.swift
//  lab1
//
//  Created by student on 07/03/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    @State var dzien: String = ""
    @State var wybor: String = ""
    @State var dniTygodnia: [String] = ["Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota", "Niedziela"]
    var body: some View {
        VStack (alignment: .center) {
            Text("Podaj wybrany dzien tygodnia")
                .foregroundColor(.blue)
                .rotation3DEffect(.degrees(45), axis: (x: 1, y: 0, z: 0))
            TextField("Wpisz dzien tygodnia", text: self.$dzien)
                .multilineTextAlignment(.center)
            Button("Zatwierdz wybor"){
                if(self.dniTygodnia.contains(self.dzien)) {
                       self.wybor = self.dzien
                }
            }
            .background(Color.yellow)
            Text("Wybrano: \(wybor)")
        }
        .padding()
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
