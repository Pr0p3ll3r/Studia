//
//  ViewController.swift
//  lab1_3
//
//  Created by student on 07/03/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    @IBOutlet weak var wybierzDzien: UILabel!
    @IBOutlet weak var dzienField: UITextField!
    @IBOutlet weak var wybrano: UILabel!
    var dniTygodnia: [String] = ["Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota", "Niedziela"]
    
    override func viewDidLoad() {
        super.viewDidLoad()
       
    }


    @IBAction func click(_ sender: Any) {
        if(self.dniTygodnia.contains(self.dzienField.text!))
        {
            wybrano.text = "Wybrano: \(self.dzienField.text!)"
        }
    }
}

