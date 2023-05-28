//
//  ContactView.swift
//  KsiazkaKontaktow
//
//  Created by Jakub on 27/05/2023.
//  Copyright © 2023 Jakub Dudek. All rights reserved.
//

import SwiftUI

struct ContactView: View {
    @Environment(\.managedObjectContext) private var viewContext
    @State var contact: Contact
    @State private var isEditing = false
    @State var contactGroups: FetchedResults<ContactGroup>
       
    var body: some View {
        VStack(spacing: 20) {
            if (contact.photo != nil) {
                Image(uiImage: UIImage(data: contact.photo!)!)
                    .resizable()
                    .aspectRatio(contentMode: .fill)
                    .frame(width: 100, height: 100)
                    .clipShape(Circle())
                    .overlay(Circle().stroke(Color.white, lineWidth: 2))
                    .scaledToFit()
            } else {
                Image(systemName: "person.circle.fill")
                    .resizable()
                    .aspectRatio(contentMode: .fit)
                    .frame(width: 100, height: 100)
            }
            Text("\(contact.firstName ?? "") \(contact.lastName ?? "")")
                .font(.title)
                .fontWeight(.bold)
            Text("Numer telefonu: \(contact.phoneNumber!)")
            Text("Grupa: \(contact.toGroup?.name ?? "Brak")")
            HStack(spacing: 20) {
                Button(action: {
                    // Dodaj kod obsługujący akcję po naciśnięciu przycisku
                }) {
                    Image(systemName: "message")
                    .font(.title)
                }
                Button(action: {
                    // Dodaj kod obsługujący akcję po naciśnięciu przycisku
                }) {
                    Image(systemName: "phone")
                    .font(.title)
                }
            }
            .padding(.horizontal)
            Button(action: {
                self.isEditing = true
            }, label: {
                Text("Edytuj")
                .padding()
                .frame(maxWidth: .infinity)
                .background(Color.blue)
                .foregroundColor(.white)
                .cornerRadius(10)
            })
            .sheet(isPresented: $isEditing) {
                EditContactView(contact: self.contact, contactGroups: self.contactGroups)
                .environment(\.managedObjectContext, self.viewContext)
            }
        }
        .padding()
        .navigationBarTitle("Kontakt")
    }
}
