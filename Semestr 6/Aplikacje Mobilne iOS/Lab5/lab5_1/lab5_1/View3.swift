//
//  View3.swift
//  lab5_1
//
//  Created by student on 28/03/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct View3: View {
    var body: some View {
        VStack {
            Text("Widok 3")
            ZStack {
            RoundedRectangle(cornerRadius: 40)
                    .fill(Color.blue)
                    .frame(width: 210, height: 210)
                Capsule()
                    .fill(Color.green)
                    .frame(width: 200, height: 80)
                Circle()
                    .fill(Color.red)
                    .frame(width: CGFloat(50), height: CGFloat(50))
            }
        }
    }
}

struct View3_Previews: PreviewProvider {
    static var previews: some View {
        View3()
    }
}
