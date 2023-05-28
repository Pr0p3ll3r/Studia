//
//  AddContactGroupView.swift
//  KsiazkaKontaktow
//
//  Created by Jakub on 28/05/2023.
//  Copyright © 2023 Jakub Dudek. All rights reserved.
//

import SwiftUI

struct AddContactGroupView: View {
    @Environment(\.managedObjectContext) private var viewContext
    @Environment(\.presentationMode) private var presentationMode
    @State var contactGroups: FetchedResults<ContactGroup>
    @State var name: String = ""
    @State private var showErrorAlert = false
    
    var body: some View {
        NavigationView {
            VStack {
                TextField("Nazwa grupy", text: $name)
                    .textFieldStyle(RoundedBorderTextFieldStyle())
                Button(action: {
                    self.addGroup()
                }) {
                    Text("Dodaj grupe")
                    .padding()
                    .frame(maxWidth: .infinity)
                    .background(Color.blue)
                    .foregroundColor(.white)
                    .cornerRadius(10)
                }
            }
            .padding()
            .navigationBarTitle("Dodaj grupę", displayMode: .inline)
            .navigationBarItems(trailing:
                Button(action: {
                self.presentationMode.wrappedValue.dismiss()
            }) {
                Text("Anuluj")
            })
        }
        .alert(isPresented: $showErrorAlert) {
              Alert(
                  title: Text("Błąd"),
                  message: Text("Grupa o podanej nazwie już istnieje."),
                  dismissButton: .default(Text("OK"))
              )
        }
    }
    
    private func addGroup() {
        guard !name.isEmpty else { return }
        
        let groupExists = contactGroups.contains { $0.name == name }
        if groupExists {
            showErrorAlert = true
            return
        }
        
        let newGroup = ContactGroup(context: viewContext)
        newGroup.name = name
        
        do {
            try self.viewContext.save()
            presentationMode.wrappedValue.dismiss()
        } catch {
            let nsError = error as NSError
            fatalError("Unresolved error \(nsError), \(nsError.userInfo)")
        }
    }
}
