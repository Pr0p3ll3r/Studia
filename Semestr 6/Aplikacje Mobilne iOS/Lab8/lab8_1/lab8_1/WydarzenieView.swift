//
//  WydarzenieView.swift
//  lab8_1
//
//  Created by student on 09/05/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct WydarzenieView: View {
    @Binding var wydarzenie: Wydarzenie
    
    @State var nowaNazwa: String
    @State var nowyCzas: Double
    @Environment(\.presentationMode) var presentationMode
    
    var body: some View {
        HStack {
            VStack {
                TextField("", text: $nowaNazwa)
                Slider(value: $nowyCzas, in: 0...60, step: 5.0)
                Text("\(nowyCzas)")
                Button("Zapisz") {
                    self.wydarzenie.nazwa = self.nowaNazwa
                    self.wydarzenie.czasTrwania = self.nowyCzas
                    self.presentationMode.wrappedValue.dismiss()
                }
            }
        }
    }
}

struct WydarzenieView_Previews: PreviewProvider {
    static var previews: some View {
        WydarzenieView(wydarzenie: .constant(Wydarzenie(ikona: "trash", nazwa: "Wydarzenie 1", czasTrwania: 0)), nowaNazwa: "", nowyCzas: 0)
    }
}
