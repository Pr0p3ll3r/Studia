//
//  Contact+CoreDataProperties.swift
//  KsiazkaKontaktow
//
//  Created by Jakub on 27/05/2023.
//  Copyright © 2023 Jakub Dudek. All rights reserved.
//
//

import Foundation
import CoreData


extension Contact {

    @nonobjc public class func fetchRequest() -> NSFetchRequest<Contact> {
        return NSFetchRequest<Contact>(entityName: "Contact")
    }

    @NSManaged public var firstName: String?
    @NSManaged public var lastName: String?
    @NSManaged public var phoneNumber: String?
    @NSManaged public var gender: String?
    @NSManaged public var photo: Data?
    @NSManaged public var toGroup: ContactGroup?

}

extension Contact : Identifiable {

}
