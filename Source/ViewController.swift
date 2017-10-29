//
//  ViewController.swift
//
//  Created by XuXudong on 5/28/17.
//  Copyright © 2017 alchemistxxd. All rights reserved.
//

#if os(iOS) || os(tvOS)
    import UIKit
#elseif os(macOS)
    import AppKit
#endif

#if os(iOS) || os(tvOS)
    
@IBDesignable
extension UIViewController {
        
    @IBInspectable var _extendedLayoutIncludesOpaqueBars: Bool {
        set {
            extendedLayoutIncludesOpaqueBars = newValue
        } get {
            return extendedLayoutIncludesOpaqueBars
        }
    }
}

#endif

