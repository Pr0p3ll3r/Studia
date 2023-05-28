//
//  GroupSelectionView.swift
//  KsiazkaKontaktow
//
//  Created by Jakub on 28/05/2023.
//  Copyright © 2023 Jakub Dudek. All rights reserved.
//

import SwiftUI

struct GroupSelectionView: View {
    @Environment(\.managedObjectContext) private var viewContext
    @Environment(\.presentationMode) private var presentationMode
    @State var contactGroups: FetchedResults<ContactGroup>
    @Binding var selectedGroup: ContactGroup?

    var body: some View {
        NavigationView {
            List {
                ForEach(contactGroups, id: \.self) { group in
                    Button(action: {
                        self.selectedGroup = group
                    }) {
                        HStack {
                            Text(group.name ?? "")
                            Spacer()
                            if group == self.selectedGroup {
                                Image(systemName: "checkmark")
                                    .foregroundColor(.blue)
                            }
                        }
                    }
                }
            }
            .navigationBarTitle("Wybierz grupę", displayMode: .inline)
            .navigationBarItems(trailing: Button("Anuluj") {
                self.selectedGroup = nil
            })
        }
    }
}
