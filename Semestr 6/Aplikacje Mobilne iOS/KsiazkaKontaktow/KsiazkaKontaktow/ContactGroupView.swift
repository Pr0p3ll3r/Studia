//
//  ContactGroupView.swift
//  KsiazkaKontaktow
//
//  Created by Jakub on 28/05/2023.
//  Copyright © 2023 Jakub Dudek. All rights reserved.
//

import SwiftUI

struct ContactGroupView: View {
    @Environment(\.managedObjectContext) private var viewContext
    @Environment(\.presentationMode) private var presentationMode
    @FetchRequest(sortDescriptors: [NSSortDescriptor(keyPath: \ContactGroup.name, ascending: true)],animation: .default)
    private var contactGroups: FetchedResults<ContactGroup>
    @State private var showAddGroup = false
    
    var body: some View {
        NavigationView {
            List(contactGroups, id: \.self) { group in
                HStack {
                    Text(group.name ?? "")
                    Spacer()
                }
                .contentShape(Rectangle())
                .onLongPressGesture {
                    self.deleteGroup(group: group)
                }
            }
            .navigationBarTitle("Grupy", displayMode: .inline)
            .navigationBarItems(
                leading: Button(action: {
                    self.showAddGroup = true
                }) {
                    Text("Dodaj grupę")
                },
                 trailing: Button(action: {
                    self.presentationMode.wrappedValue.dismiss()
                }) {
                Text("Cofnij")
            })
            .sheet(isPresented: $showAddGroup) {
                AddContactGroupView(contactGroups: self.contactGroups)
                    .environment(\.managedObjectContext, self.viewContext)
            }
        }
        .navigationBarTitle("Grupy")
    }
    
    private func deleteGroup(group: ContactGroup) {
        if let contactsInGroup = group.contactArray as? [Contact] {
            for contact in contactsInGroup {
                contact.toGroup = nil
            }
        }
        
        self.viewContext.delete(group)
         
        do {
            try self.viewContext.save()
        } catch {
            let nsError = error as NSError
            fatalError("Unresolved error \(nsError), \(nsError.userInfo)")
        }
     }
}
