//
//  ContentView.swift
//  lab1_5
//
//  Created by Jakub on 23/05/2023.
//  Copyright © 2023 Jakub. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    @State private var number1: String = ""
    @State private var number2: String = ""
    @State private var result: String = ""

    var body: some View {
        VStack {
            TextField("Liczba 1", text: $number1)
            TextField("Liczba 2", text: $number2)
            Button(action: {self.calculate()}, label: {
                Text("Oblicz")
            })
            Text(result)
        }.padding()
    }

    private func calculate() {
        guard let number1 = Double(number1), let number2 = Double(number2) else {
            result = "Nieprawidłowe dane"
            return
        }

        if number2 != 0 {
            let resultTemp = number1 / number2
            result = String(resultTemp)
        } else {
            result = "Dzielenie przez zero"
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
