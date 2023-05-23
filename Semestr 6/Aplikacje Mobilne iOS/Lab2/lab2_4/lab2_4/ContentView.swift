//
//  ContentView.swift
//  lab2_4
//
//  Created by Jakub on 23/05/2023.
//  Copyright © 2023 Jakub. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    @State private var number1: String = ""
    @State private var number2: String = ""
    @State private var operation: Operation = .addition
    @State private var result: String = ""
    
    enum Operation: String {
        case addition = "+"
        case subtraction = "-"
        case multiplication = "*"
        case division = "/"
    }
    
    var body: some View {
        VStack {
            TextField("Liczba 1", text: $number1)
            TextField("Liczba 2", text: $number2)
            HStack {
                Button(action: {
                    self.operation = .addition
                    self.calculate()
                }, label: {
                    Text("+")
                })
                Button(action: {
                    self.operation = .subtraction
                    self.calculate()
                }, label: {
                    Text("-")
                })
                Button(action: {
                    self.operation = .multiplication
                    self.calculate()
                }, label: {
                    Text("*")
                })
                Button(action: {
                    self.operation = .division
                    self.calculate()
                }, label: {
                    Text("/")
                })
            }
            Text(result)
        }
        .padding()
    }
    
    private func calculate() {
        guard let number1 = Int(number1), let number2 = Int(number2) else {
            result = "Nieprawidłowe dane"
            return
        }
            
        switch operation {
            case .addition:
                result = String(number1 + number2)
            case .subtraction:
                result = String(number1 - number2)
            case .multiplication:
                result = String(number1 * number2)
            case .division:
                if number2 != 0 {
                    result = String(number1 / number2)
                } else {
                    result = "Dzielenie przez zero"
                }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
