//
//  ContentView.swift
//  Lab3_1
//
//  Created by student on 21/03/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    @State var ileRazy: Int = 0
    var body: some View {
        VStack {
            PanelView(ileRazy: $ileRazy)
            Text("Wcisnieto \(ileRazy) razy!")
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
