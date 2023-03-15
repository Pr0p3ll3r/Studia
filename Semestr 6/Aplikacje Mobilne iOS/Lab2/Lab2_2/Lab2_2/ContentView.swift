//
//  ContentView.swift
//  Lab2_2
//
//  Created by student on 14/03/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        ZStack (alignment: .bottomLeading){
            Image("pies")
                .resizable()
                .aspectRatio(contentMode: .fit)
            HStack (){
                VStack (alignment: .leading){
                  Text("Piesek")
                  Text("Nieznany autor")
                }
                .padding(20)
                .foregroundColor(Color.green)
                .font(.headline)
            }
            .frame(maxWidth: .infinity, alignment: .bottomLeading)
            .background(Color.white.opacity(0.7))
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
