//
//  ContentView.swift
//  KsiazkaKontaktow
//
//  Created by Jakub on 26/05/2023.
//  Copyright © 2023 Jakub Dudek. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    @Environment(\.managedObjectContext) private var viewContext
    @FetchRequest(sortDescriptors: [NSSortDescriptor(keyPath: \Contact.firstName,ascending: true)],animation: .default)
    private var contacts: FetchedResults<Contact>
    @FetchRequest(sortDescriptors: [NSSortDescriptor(keyPath: \ContactGroup.name, ascending: true)],animation: .default)
    private var contactGroups: FetchedResults<ContactGroup>
    @State private var selectedGroup: ContactGroup?
    @State private var showAddContact = false
    @State private var searchText: String = ""
    @State private var showGroupSelection = false
    
    private var filteredContacts: [Contact] {
        if searchText.isEmpty {
            return Array(contacts)
        } else {
            return contacts.filter { contact in
                let fullName = "\(contact.firstName ?? "") \(contact.lastName ?? "")"
                return fullName.localizedCaseInsensitiveContains(searchText)
            }
        }
    }
    
    var body: some View {
        NavigationView{
            VStack {
                Button(action: {
                    self.showAddContact.toggle()
                }, label: {
                    Text("Dodaj kontakt")
                    .foregroundColor(.white)
                    .padding()
                    .frame(maxWidth: .infinity)
                    .background(Color.blue)
                    .cornerRadius(10)
                })
                .sheet(isPresented: $showAddContact) {
                    AddContactView(contactGroups: self.contactGroups)
                        .environment(\.managedObjectContext, self.viewContext)
                }
                SearchBar(text: $searchText)
                List {
                    ForEach(filteredContacts, id: \.self){ contact in
                        NavigationLink(destination: ContactView(contact: contact, contactGroups: self.contactGroups)){
                            HStack {
                                self.showImage(contact: contact)
                                .resizable()
                                .aspectRatio(contentMode: .fill)
                                .frame(width: 50, height: 50)
                                .clipShape(Circle())
                                .overlay(Circle().stroke(Color.white, lineWidth: 2))
                                .scaledToFit()
                              Text("\(contact.firstName!) \(contact.lastName!)" )
                            }
                        }
                    }
                    .onDelete(perform: self.deleteContact)
                }
                .onAppear(){
                    self.viewContext.refreshAllObjects()
                }
            }
            .padding()
            .navigationBarTitle("Kontakty", displayMode: .inline)
            .navigationBarItems(leading:
                Button(action: {
                    self.showGroupSelection.toggle()
                }, label: {
                    Text("Grupy")
                })
                .sheet(isPresented: $showGroupSelection) {
                    ContactGroupView()
                        .environment(\.managedObjectContext, self.viewContext)
                }
            )
        }
        .onAppear() {
            self.addGroups()
        }
    }
    
    private func showImage(contact: Contact) -> Image {
        if let imageData = contact.photo, let uiImage = UIImage(data: imageData) {
            return Image(uiImage: uiImage)
        } else {
            return Image(systemName: "person.circle.fill")
        }
    }
    
    private func addGroups(){
        if contactGroups.isEmpty {
            let rodzinaGroup = ContactGroup(context: viewContext)
            rodzinaGroup.name = "Rodzina"
            
            let przyjacieleGroup = ContactGroup(context: viewContext)
            przyjacieleGroup.name = "Przyjaciele"
            
            do {
                try viewContext.save()
            } catch {
                fatalError("Unresolved error \(error)")
            }
        }
    }
    
    private func deleteContact(offsets: IndexSet) {
        for index in offsets {
            let contact = contacts[index]
            viewContext.delete(contact)
        }
        do {
            try viewContext.save()
        } catch {
            fatalError("Unresolved error \(error)")
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
