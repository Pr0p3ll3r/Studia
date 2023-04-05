//
//  SecondView.swift
//  lab6_1
//
//  Created by student on 04/04/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct SecondView: View {
    @Binding var wybranyKolor : Color
    var body: some View {
        Picker(selection: $wybranyKolor, label: Text("Kolory")) {
            Text("Czarny").tag(Color.black)
            Text("Czerwony").tag(Color.red)
            Text("Niebieski").tag(Color.blue)
            Text("Zielony").tag(Color.green)
        }
    }
}

struct SecondView_Previews: PreviewProvider {
    static var previews: some View {
        SecondView(wybranyKolor: .constant(Color.white))
    }
}
