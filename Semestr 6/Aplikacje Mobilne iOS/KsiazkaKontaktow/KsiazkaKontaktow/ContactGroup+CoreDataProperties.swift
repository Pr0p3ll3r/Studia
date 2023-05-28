//
//  ContactGroup+CoreDataProperties.swift
//  KsiazkaKontaktow
//
//  Created by Jakub on 27/05/2023.
//  Copyright © 2023 Jakub Dudek. All rights reserved.
//
//

import Foundation
import CoreData


extension ContactGroup {

    @nonobjc public class func fetchRequest() -> NSFetchRequest<ContactGroup> {
        return NSFetchRequest<ContactGroup>(entityName: "ContactGroup")
    }

    @NSManaged public var name: String?
    @NSManaged public var toContact: NSSet?
    public var contactArray: [Contact] {
        let set = toContact as? Set<Contact> ?? []
            return set.sorted {
            $0.firstName! < $1.firstName!
        }
    }
}

extension ContactGroup : Identifiable {

}
