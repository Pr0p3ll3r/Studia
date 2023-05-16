//
//  ContentView.swift
//  lab9_1
//
//  Created by student on 16/05/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    @State var number = 1
    @State var etykieta = ""
    @State var kolor = 0
    @State var kolory: [Color] = [Color.black, Color.red, Color.blue]
    @State var pozycja = CGPoint(x: 200, y: 0)
    @State var cars: [Car] = [Car(marka: "Marka1", model: "Model1", logo: "obraz1"),
    Car(marka: "Marka2", model: "Model2", logo: "obraz2"),
    Car(marka: "Marka3", model: "Model3", logo: "obraz3")]
    var body: some View {
        VStack {
            Image("obraz\(number)")
            .resizable()
            .frame(width: 300, height: 200)
            .gesture(TapGesture()
                .onEnded(){
                    _ in
                    self.number += 1
                    if(self.number == 4) {
                        self.number = 1
                    }
            })
            .gesture(LongPressGesture()
                .onEnded() {
                    _ in
                    self.etykieta = "obraz\(self.number)"
                }
            )
            Text(etykieta)
            Spacer()
            .fixedSize()
            Text("Napis")
            .foregroundColor(kolory[kolor])
            .gesture(LongPressGesture()
                .onEnded() {
                    _ in
                    self.kolor += 1
                    if(self.kolor == 3) {
                        self.kolor = 0
                    }
            })
            Rectangle()
                .fill(Color.red)
                .frame(width: 100, height: 100)
                .position(pozycja)
            .gesture(DragGesture()
                .onChanged{
                    value in
                    self.pozycja = value.location
            })
            List {
                ForEach(cars, id:\.self ){ car in
                    CarView(car: car)
                        .gesture(TapGesture()
                            .onEnded() {
                                if let index = self.cars.firstIndex(of: car) {
                                    self.cars.remove(at: index)
                                }
                        })
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
