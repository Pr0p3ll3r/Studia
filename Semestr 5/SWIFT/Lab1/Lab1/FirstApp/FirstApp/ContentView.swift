//
//  ContentView.swift
//  FirstApp
//
//  Created by student on 03/10/2022.
//  Copyright © 2022 PL. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    @State private var liczba1: String = ""
    @State private var liczba2: String = ""
    @State private var liczba3: String = ""
    @State var suma: Int = 0
    @State var srednia: Double = 0.0
    @State var obliczono: Bool = false
    var body: some View {
        VStack{
            Text("Podaj 3 liczby calkowite")
                .padding()
            TextField("Wprowadz 1 liczbe: ", text: $liczba1)
            TextField("Wprowadz 2 liczbe: ", text: $liczba2)
            TextField("Wprowadz 3 liczbe: ", text: $liczba3)
            
            Button(action: {
                self.obliczono = true
                self.suma = (Int)(self.liczba1)! + (Int)(self.liczba2)! + (Int)(self.liczba3)!
                self.srednia = (Double)(self.suma)/3
            }, label: {
                Text("Oblicz")
            })
            if(obliczono){
                Text("Suma 3 liczb: \(suma), a srednia:  \(srednia)")
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
