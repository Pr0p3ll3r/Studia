//
//  SmakView.swift
//  lab6_2
//
//  Created by student on 04/04/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct SmakView: View {
    @Binding var smak: String
    var body: some View {
        VStack {
            Text("Wybierz smak soku")
            Text("Wybrany smak: \(smak)")
            Button(action: {
                self.smak = "Jablkowy"}) {
                    Image("jablko")
                    .renderingMode(.original)
                    .resizable()
                    .frame(width: 32.0, height: 32.0)
            }
            Button(action: {
                self.smak = "Pomaranczowy"}) {
                    Image("pomarancza")
                    .renderingMode(.original)
                    .resizable()
                    .frame(width: 32.0, height: 32.0)
            }
            Button(action: {
                self.smak = "Bananowy"}) {
                    Image("banan")
                    .renderingMode(.original)
                    .resizable()
                    .frame(width: 32.0, height: 32.0)
            }
        }
    }
}

struct SmakView_Previews: PreviewProvider {
    static var previews: some View {
        SmakView(smak: .constant(""))
    }
}
