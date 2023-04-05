//
//  ContentView.swift
//  lab6_1
//
//  Created by student on 04/04/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    @State private var przejdz: Bool = false;
    @State var wybranyKolor: Color = Color.black
    var body: some View {
        VStack {
            Text("Hello, World!")
                .foregroundColor(wybranyKolor)
            Button(action:{
                self.przejdz.toggle()
            }, label: {
                Text("Pokaz")
            })
            .sheet(isPresented: $przejdz) {
                SecondView(wybranyKolor: self.$wybranyKolor)
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
