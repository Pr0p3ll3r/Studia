//
//  ContentView.swift
//  lab8_1
//
//  Created by student on 09/05/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    @State var wydarzenia: [Wydarzenie] = [Wydarzenie(ikona: "trash", nazwa: "Wydarzenie 1", czasTrwania: 0), Wydarzenie(ikona: "globe", nazwa: "Wydarzenie 2", czasTrwania: 0)]
    var body: some View {
        NavigationView {
                List {
                     ForEach(0..<wydarzenia.count) { i in
                        NavigationLink(destination: WydarzenieView(wydarzenie: self.$wydarzenia[i], nowaNazwa: self.wydarzenia[i].nazwa, nowyCzas: self.wydarzenia[i].czasTrwania), label: {
                            HStack {
                                Image(systemName: self.wydarzenia[i].ikona)
                                VStack {
                                    Text(self.wydarzenia[i].nazwa)
                                    Text("\(String(format: "%.f", self.wydarzenia[i].czasTrwania)) min")
                                }
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
