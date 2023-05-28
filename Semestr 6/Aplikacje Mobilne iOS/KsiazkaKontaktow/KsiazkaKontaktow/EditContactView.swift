//
//  EditContactView.swift
//  KsiazkaKontaktow
//
//  Created by Jakub on 27/05/2023.
//  Copyright © 2023 Jakub Dudek. All rights reserved.
//

import SwiftUI

struct EditContactView: View {
    @Environment(\.managedObjectContext) private var viewContext
    @Environment(\.presentationMode) private var presentationMode
    @ObservedObject var contact: Contact
    @State private var editFirstName: String
    @State private var editLastName: String
    @State private var editPhoneNumber: String
    @State private var editSelectedGroup: ContactGroup? = nil
    @State private var showImagePicker = false
    @State private var editSelectedImage: UIImage?
    private var contactGroups: FetchedResults<ContactGroup>
    @State private var selectedGroupIndex: Int?
    
    init(contact: Contact, contactGroups: FetchedResults<ContactGroup>) {
        self.contact = contact
        self.contactGroups = contactGroups
        self._editFirstName = State(initialValue: contact.firstName ?? "")
        self._editLastName = State(initialValue: contact.lastName ?? "")
        self._editSelectedGroup = State(initialValue: contact.toGroup)
        self._editPhoneNumber = State(initialValue: contact.phoneNumber ?? "")
        if contact.photo != nil {
            self._editSelectedImage = State(initialValue: (UIImage(data: contact.photo!)))
        } else {
            editSelectedImage = nil
        }
     
    }
    
    var body: some View {
        NavigationView {
            VStack {
               if (editSelectedImage != nil) {
                Image(uiImage: editSelectedImage!)
                .resizable()
                .aspectRatio(contentMode: .fill)
                .frame(width: 100, height: 100)
                .clipShape(Circle())
                .overlay(Circle().stroke(Color.white, lineWidth: 2))
                .scaledToFit()
                .onTapGesture {
                    self.showImagePicker = true
                }
                } else {
                    Image(systemName: "person.circle.fill")
                    .resizable()
                    .aspectRatio(contentMode: .fit)
                    .frame(width: 100, height: 100)
                    .onTapGesture {
                        self.showImagePicker = true
                    }
                }
                Button(action: {
                    self.showImagePicker = true
                }) {
                    Text("Zmień zdjęcie")
                }
                .sheet(isPresented: $showImagePicker) {
                    ImagePicker(image: self.$editSelectedImage)
                }
                TextField("Imie", text: $editFirstName)
                    .textFieldStyle(RoundedBorderTextFieldStyle())
                TextField("Nazwisko", text: $editLastName)
                    .textFieldStyle(RoundedBorderTextFieldStyle())
                TextField("Numer telefonu", text: $editPhoneNumber)
                    .keyboardType(.phonePad)
                    .textFieldStyle(RoundedBorderTextFieldStyle())
                Text("Wybierz grupe")
                Picker("Grupa", selection: $editSelectedGroup) {
                    Text("Brak").tag(nil as ContactGroup?)
                    ForEach(contactGroups, id: \.self) { group in
                        Text(group.name ?? "").tag(group as ContactGroup?)
                    }
                }
                .pickerStyle(SegmentedPickerStyle())
                Button(action: {
                    self.saveContact()
                }) {
                    Text("Zapisz")
                        .padding()
                        .frame(maxWidth: .infinity)
                        .background(Color.blue)
                        .foregroundColor(.white)
                        .cornerRadius(10)
                }
            }
            .padding()
            .navigationBarTitle("Edytuj kontakt", displayMode: .inline)
            .navigationBarItems(trailing: Button(action: {
                self.presentationMode.wrappedValue.dismiss()
            }) {
                Text("Anuluj")
            })
        }
    }
    
    private func saveContact() {
        guard !editFirstName.isEmpty, !editLastName.isEmpty, !editPhoneNumber.isEmpty else {
            return
        }
        
        guard editPhoneNumber.rangeOfCharacter(from: CharacterSet.decimalDigits.inverted) == nil else {
            return
        }
        
        contact.firstName = editFirstName
        contact.lastName = editLastName
        contact.phoneNumber = editPhoneNumber
        contact.toGroup = editSelectedGroup
        if editSelectedGroup != nil {
            contact.toGroup = editSelectedGroup
        } else {
            contact.toGroup = nil
        }
        if let image = editSelectedImage {
            if let imageData = image.jpegData(compressionQuality: 0.8) {
                contact.photo = imageData
            }
        }
        do {
            try self.viewContext.save()
            presentationMode.wrappedValue.dismiss()
        } catch {
            let nsError = error as NSError
            fatalError("Unresolved error \(nsError), \(nsError.userInfo)")
        }
    }
}



/*
struct EditContactView_Previews: PreviewProvider {
    static var previews: some View {
        EditContactView()
    }
}
*/
