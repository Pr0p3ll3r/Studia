//
//  ContentView.swift
//  Lab2_3
//
//  Created by student on 14/03/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        VStack {
            HStack {
                Text("Podaj bok 1:")
                TextField("")
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
