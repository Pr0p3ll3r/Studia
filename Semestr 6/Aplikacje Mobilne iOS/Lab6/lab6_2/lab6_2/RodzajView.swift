//
//  RodzajView.swift
//  lab6_2
//
//  Created by student on 04/04/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct RodzajView: View {
    @Binding var rodzaj: String
    var body: some View {
        VStack {
            Text("Wybierz rodzaj kawy")
            Picker(selection: $rodzaj, label: Text("Rodzaje")) {
                Text("Espresso").tag("Espresso")
                Text("Ristretto").tag("Ristretto")
                Text("Cappuccino").tag("Cappuccino")
                Text("Latte").tag("Latte")
            }
        }
    }
}

struct RodzajView_Previews: PreviewProvider {
    static var previews: some View {
        RodzajView(rodzaj: .constant(""))
    }
}
