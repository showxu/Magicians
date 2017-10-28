//
//  UIViewController.swift
//  IBZealot
//
//  Created by XuXudong on 5/28/17.
//  Copyright © 2017 alchemistxxd. All rights reserved.
//

import UIKit.UIViewController

@IBDesignable
private extension UIViewController {
    
    @IBInspectable private var _extendedLayoutIncludesOpaqueBars: Bool {
        set {
            extendedLayoutIncludesOpaqueBars = newValue
        } get {
            return extendedLayoutIncludesOpaqueBars
        }
    }
}

