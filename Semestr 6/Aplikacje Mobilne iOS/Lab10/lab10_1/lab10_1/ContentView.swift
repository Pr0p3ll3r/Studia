//
//  ContentView.swift
//  lab10_1
//
//  Created by student on 23/05/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import SwiftUI
import MapKit

class MyAnnotation: NSObject, MKAnnotation {
     let title: String?
     let subtitle: String?
    var coordinate: CLLocationCoordinate2D
     init(title: String?,subtitle: String?,coordinate: CLLocationCoordinate2D) {
         self.title = title
         self.subtitle = subtitle
         self.coordinate = coordinate
     }
}

struct MapView: UIViewRepresentable {
    @Binding var myAnnotation : MyAnnotation
    @Binding var span: Double
    
    func makeUIView(context: Context) -> MKMapView {
         let myMap = MKMapView(frame: .zero)
         return myMap
    }

    func updateUIView(_ uiView: MKMapView, context: Context) {
        let span = MKCoordinateSpan(latitudeDelta: 0.1, longitudeDelta: 0.1)
        let region = MKCoordinateRegion(center: myAnnotation.coordinate, span: span)
        uiView.setRegion(region, animated: true)
        uiView.addAnnotation(myAnnotation.self)
    }
}

struct ContentView: View {
    @State var myAnnotation = MyAnnotation(title: "Katedra Informatyki", subtitle: "Politechnika Lubelska", coordinate: CLLocationCoordinate2D(latitude: 51.2353112433304, longitude: 22.55289822681853))
    @State var newSpan: Double = 0.1
    @State var latitude: String = ""
    @State var longitude: String = ""

    var body: some View {
        VStack {
            MapView(myAnnotation: $myAnnotation, span: $newSpan)
                .frame(width: 300, height: 400, alignment: .center)
                .onTapGesture {
                    self.changeZoom()
            }
            HStack {
                TextField("Latitude", text: $latitude)
                    .textFieldStyle(RoundedBorderTextFieldStyle())
                TextField("Longitude", text: $longitude)
                    .textFieldStyle(RoundedBorderTextFieldStyle())
            }
            Button("Dodaj punkt", action: {
                self.addAnnotation()
            })
        }
    }

    private func addAnnotation() {
        guard let latitude = Double(latitude), let longitude = Double(longitude) else {
            return
        }
        let newCoordinate = CLLocationCoordinate2D(latitude: latitude, longitude: longitude)
        self.myAnnotation = MyAnnotation(title: "Brama Krakowska", subtitle: "Lublin", coordinate: newCoordinate)
    }
    
    private func changeZoom() {
        guard let latitude = Double(latitude), let longitude = Double(longitude) else {
            return
        }
        
        let currentSpan = MKCoordinateSpan(latitudeDelta: newSpan, longitudeDelta: newSpan)
        let maximumSpan = MKCoordinateSpan(latitudeDelta: 1.0, longitudeDelta: 1.0)
        
        if currentSpan.latitudeDelta < maximumSpan.latitudeDelta && currentSpan.longitudeDelta < maximumSpan.longitudeDelta {
            let newZoomSpan = currentSpan.latitudeDelta * 1.2
            newSpan = newZoomSpan
            
            let newCoordinate = CLLocationCoordinate2D(latitude: latitude, longitude: longitude)
            myAnnotation.coordinate = newCoordinate
        } else {
            newSpan = 0.1
        }
    }


}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
