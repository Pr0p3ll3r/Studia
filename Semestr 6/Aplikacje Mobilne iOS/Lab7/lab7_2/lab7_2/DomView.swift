//
//  DomView.swift
//  lab7_2
//
//  Created by student on 18/04/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct DomView: View {
    var dom : Dom
    var body: some View {
        VStack {
            Image(dom.obraz)
                .resizable()
                .aspectRatio(contentMode: .fit)
            Text("Nazwa: \(dom.nazwa)")
            Text("Powierzchnia: \(dom.powierzchnia)")
            Text("Liczba pokoi: \(dom.liczbaPokoi)")
            Text("Wielkość działki: \(dom.wielkoscDzialki)")
        }
        .navigationBarTitle(dom.nazwa)
    }
}

struct DomView_Previews: PreviewProvider {
    static let dom2 = Dom(nazwa: "Dom 1", powierzchnia: 100, liczbaPokoi: 8, wielkoscDzialki: 200, liczbaPieter: 2, obraz: "dom")
    static var previews: some View {
        DomView(dom: dom2)
    }
}
