//
//  ContentView.swift
//  lab5_1
//
//  Created by student on 28/03/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        NavigationView {
            VStack {
                Text("Widok 1")
                Path { path in
                    path.move(to: CGPoint(x : 200, y : 100))
                    path.addLine (to : CGPoint(x: 300, y : 300))
                    path.addLine (to : CGPoint(x: 100, y : 300))
                    path.addLine (to : CGPoint(x: 200, y : 100))
                    path.closeSubpath()
                }
                .fill(Color.green)
                NavigationLink("Nastepny ekran", destination: View2())

            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
