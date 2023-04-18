//
//  ViewController.swift
//  lab7_1
//
//  Created by student on 18/04/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    @IBOutlet var tableView: UITableView!
    var mieszkania = [Mieszkanie(nazwa: "Mieszkanie 1", powierzchnia: 50, liczbaPokoi: 4, czyDwupoziomowy: false, obraz: UIImage(named: "mieszkanie")!)]
    var domy = [Dom(nazwa: "Dom 1", powierzchnia: 100, liczbaPokoi: 8, wielkoscDzialki: 200, liczbaPieter: 2, obraz: UIImage(named: "dom")!), Dom(nazwa: "Dom 2", powierzchnia: 200, liczbaPokoi: 10, wielkoscDzialki: 200, liczbaPieter: 2, obraz: UIImage(named: "dom")!)]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.tableView.delegate = self
        self.tableView.dataSource = self
    }
    
    func numberOfSections(in tableView: UITableView) -> Int {
        return 2
    }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if (section == 0) {
            return mieszkania.count
        } else {
            return domy.count
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "myCell", for: indexPath)
        if (indexPath.section == 0) {
            let mieszkanie = mieszkania[indexPath.row]
            cell.textLabel?.text = "\(mieszkanie.nazwa) \(mieszkanie.powierzchnia)m2 \(mieszkanie.liczbaPokoi) \(mieszkanie.czyDwupoziomowy)"
            cell.imageView?.image = mieszkanie.obraz
        } else {
            let dom = domy[indexPath.row]
            cell.textLabel?.text = "\(dom.nazwa) \(dom.powierzchnia)m2 \(dom.liczbaPokoi) \(dom.wielkoscDzialki)km2 \(dom.liczbaPieter)"
            cell.imageView?.image = dom.obraz
        }
        return cell
    }
}
