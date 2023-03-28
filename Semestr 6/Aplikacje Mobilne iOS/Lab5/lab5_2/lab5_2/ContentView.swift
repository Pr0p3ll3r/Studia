//
//  ContentView.swift
//  lab5_2
//
//  Created by student on 28/03/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        NavigationView {
            VStack {
                NavigationLink("Volkswagen", destination: Marka1View())
                NavigationLink("Audi", destination: Marka2View())
                NavigationLink("Toyota", destination: Marka3View())
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
