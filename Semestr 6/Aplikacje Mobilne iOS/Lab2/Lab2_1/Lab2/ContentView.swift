//
//  ContentView.swift
//  Lab2
//
//  Created by student on 14/03/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI
let tablica_kolorow = [Color.red, Color.orange, Color.yellow, Color.green, Color.blue, Color.purple]
struct ContentView: View {
    var body: some View {
        ZStack {
            ForEach((0..<tablica_kolorow.count), id: \.self){
                i in
                Rectangle()
                    .fill(tablica_kolorow[i])
                    .frame(width: 200, height: 200)
                    .offset(x: CGFloat(i) * 10.0, y: CGFloat(i) * 10.0)
            }
        }
        .padding()
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
