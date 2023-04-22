//
//  ContentView.swift
//  lab7_2
//
//  Created by student on 18/04/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    var mieszkania: [Mieszkanie] = [Mieszkanie(nazwa: "Mieszkanie 1", powierzchnia: 50, liczbaPokoi: 4, czyDwupoziomowy: false, obraz: "mieszkanie")]
    var domy : [Dom] = [Dom(nazwa: "Dom 1", powierzchnia: 100, liczbaPokoi: 8, wielkoscDzialki: 200, liczbaPieter: 2, obraz: "dom"), Dom(nazwa: "Dom 2", powierzchnia: 200, liczbaPokoi: 10, wielkoscDzialki: 200, liczbaPieter: 2, obraz: "dom")]
    
    var body: some View {
        NavigationView {
            VStack {
                Text("Mieszkania")
                List{
                    ForEach(mieszkania, id: \.self) { mieszkanie in
                        NavigationLink(destination: MieszkanieView(mieszkanie: mieszkanie)) {
                            Image("\(mieszkanie.obraz)")
                                .resizable()
                                .frame(width: 50, height: 50)
                            Text("\(mieszkanie.nazwa)")
                        }
                    }
                }
                Text("Domy")
                List{
                    ForEach(domy , id: \.self) { dom in
                        NavigationLink(destination: DomView(dom: dom)) {
                            Image("\(dom.obraz)")
                                .resizable()
                                .frame(width: 50, height: 50)
                            Text("\(dom.nazwa)")
                        }
                    }
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
