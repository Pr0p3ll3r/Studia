//
//  ViewController.swift
//  lab1_4
//
//  Created by Jakub on 23/05/2023.
//  Copyright © 2023 Jakub. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var number1TextField: UITextField!
    @IBOutlet weak var number2TextField: UITextField!
    @IBOutlet weak var resultLabel: UILabel!

    @IBAction func calculateButtonTapped(_ sender: UIButton) {
        guard let number1Text = number1TextField.text,
              let number2Text = number2TextField.text,
              let number1 = Double(number1Text),
              let number2 = Double(number2Text) else {
            resultLabel.text = "Nieprawidłowe dane"
            return
        }

        if number2 != 0 {
            let result = number1 / number2
            resultLabel.text = String(result)
        } else {
            resultLabel.text = "Dzielenie przez zero"
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

}
