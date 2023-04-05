//
//  SecondView.swift
//  lab6_3
//
//  Created by student on 04/04/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct SecondView: View {
    @Binding var autor: String
    var body: some View {
        VStack {
            Text("Wpisz autora")
            TextField("Nazwisko autora", text: $autor)
        }
    }
}

struct SecondView_Previews: PreviewProvider {
    static var previews: some View {
        SecondView(autor: .constant(""))
    }
}
