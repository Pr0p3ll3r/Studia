//
//  MieszkanieView.swift
//  lab7_2
//
//  Created by student on 18/04/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct MieszkanieView: View {
    var mieszkanie: Mieszkanie
    var body: some View {
        VStack {
            Image(mieszkanie.obraz)
                .resizable()
                .aspectRatio(contentMode: .fit)
            Text("Nazwa: \(mieszkanie.nazwa)")
            Text("Powierzchnia: \(mieszkanie.powierzchnia)")
            Text("Liczba pokoi: \(mieszkanie.liczbaPokoi)")
            Text("Czy jest dwupoziomowe: \(mieszkanie.czyDwupoziomowy ? "Tak" : "Nie")")
        }
        .navigationBarTitle(mieszkanie.nazwa)
    }
}

struct MieszkanieView_Previews: PreviewProvider {
    static let mieszkanie2 = Mieszkanie(nazwa: "Test", powierzchnia: 50, liczbaPokoi: 2, czyDwupoziomowy: true, obraz: "mieszkanie")
    static var previews: some View {
        MieszkanieView(mieszkanie: mieszkanie2)
    }
}
