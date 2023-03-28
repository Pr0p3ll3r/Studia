//
//  View2.swift
//  lab5_1
//
//  Created by student on 28/03/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct View2: View {
    var body: some View {
        VStack {
            Text("Widok 2")
            ZStack {
                Rectangle()
                    .fill(Color.green)
                    .frame(width:210, height: 210)
                HStack(spacing: 0) {
                    Rectangle()
                        .fill(Color.gray)
                        .frame(width: 100, height:200)
                    VStack(spacing: 0) {
                        Rectangle()
                            .fill(Color.yellow)
                            .frame(width: 100, height: 100)
                        Rectangle()
                        .fill(Color.white)
                        .frame(width: 100, height: 100)
                    }
                }
            }
            NavigationLink("Nastepny ekran", destination: View3())
        }
    }
}

struct View2_Previews: PreviewProvider {
    static var previews: some View {
        View2()
    }
}
