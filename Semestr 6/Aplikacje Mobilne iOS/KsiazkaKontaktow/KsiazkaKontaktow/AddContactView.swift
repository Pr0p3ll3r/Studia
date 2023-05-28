//
//  AddContactView.swift
//  KsiazkaKontaktow
//
//  Created by Jakub on 27/05/2023.
//  Copyright © 2023 Jakub Dudek. All rights reserved.
//

import SwiftUI
import CoreData

struct AddContactView: View {
    @Environment(\.managedObjectContext) private var viewContext
    @Environment(\.presentationMode) private var presentationMode
    @State var contactGroups: FetchedResults<ContactGroup>
    @State private var firstName: String = ""
    @State private var lastName: String = ""
    @State private var phoneNumber: String = ""
    @State private var selectedGroup: ContactGroup?
    @State private var showImagePicker = false
    @State private var selectedImage: UIImage?
    
    @State private var showAlert = false
    @State private var alertMessage = ""
    
    var body: some View {
        NavigationView {
            VStack {
                if (selectedImage != nil) {
                    Image(uiImage: selectedImage!)
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
                    Text("Dodaj zdjęcie")
                }
                .sheet(isPresented: $showImagePicker) {
                    ImagePicker(image: self.$selectedImage)
                }
                
                TextField("Imie", text: $firstName)
                    .textFieldStyle(RoundedBorderTextFieldStyle())
                TextField("Nazwisko", text: $lastName)
                    .textFieldStyle(RoundedBorderTextFieldStyle())
                TextField("Numer telefonu", text: $phoneNumber)
                    .keyboardType(.phonePad)
                    .textFieldStyle(RoundedBorderTextFieldStyle())
                Text("Wybierz grupe")
                Picker("Grupa", selection: $selectedGroup) {
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
            .navigationBarTitle("Dodaj kontakt", displayMode: .inline)
            .navigationBarItems(trailing: Button(action: {
                self.presentationMode.wrappedValue.dismiss()
                }) {
                    Text("Anuluj")
                })
            .alert(isPresented: $showAlert) {
                Alert(
                    title: Text("Błąd"),
                    message: Text(alertMessage),
                    dismissButton: .default(Text("OK"))
                )
            }
        }
    }
    
    private func saveContact() {
        guard !firstName.isEmpty, !lastName.isEmpty, !phoneNumber.isEmpty else {
            showAlert = true
            alertMessage = "Wprowadź imię i nazwisko oraz numer telefonu"
            return
        }
        
        guard phoneNumber.rangeOfCharacter(from: CharacterSet.decimalDigits.inverted) == nil else {
            showAlert = true
            alertMessage = "Numer telefonu może zawierać tylko cyfry"
            return
        }
        
        let newContact = Contact(context: viewContext)
        newContact.firstName = firstName
        newContact.lastName = lastName
        newContact.phoneNumber = phoneNumber
        if selectedGroup != nil {
            newContact.toGroup = selectedGroup
        } else {
            newContact.toGroup = nil
        }
        if let image = selectedImage {
            if let imageData = image.jpegData(compressionQuality: 0.8) {
                newContact.photo = imageData
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
