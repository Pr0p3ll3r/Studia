//
//  PanelView.swift
//  Lab3_1
//
//  Created by student on 21/03/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct PanelView: View {
    @Binding var ileRazy : Int
    var body: some View {
        VStack {
            Text("Wcisnij przycisk")
            Button(action: {
                self.ileRazy += 1
            })
            {
                Text("Wcisnij")
            }
        }
    }
}

struct PanelView_Previews: PreviewProvider {
    static var previews: some View {
        PanelView(ileRazy: .constant(0))
    }
}
