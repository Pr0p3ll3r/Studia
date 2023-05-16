//
//  CarView.swift
//  lab9_1
//
//  Created by student on 16/05/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI

struct CarView: View {
    var car: Car
    var body: some View {
        HStack {
            Image(car.logo)
                .resizable()
                .frame(width: 200, height: 100)
            VStack {
                Text(car.marka)
                Text(car.model)
            }
        }
    }
}

struct CarView_Previews: PreviewProvider {
    static var previews: some View {
        CarView(car: Car(marka: "Test", model: "Test", logo: "trash"))
    }
}
