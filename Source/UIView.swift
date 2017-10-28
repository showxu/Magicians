//
//  UIView.swift
//  Medel
//
//  Created by XuXudong on 4/7/17.
//
//

import UIKit

@IBDesignable
private extension UIView {

    @IBInspectable private var _translation: CGPoint {
        get {
            return .zero
        } set {
            UIStoryboardSegue
            transform = transform.translatedBy(x: newValue.x, y: newValue.y)
        }
    }
    
    @IBInspectable private var _scale: CGPoint {
        get {
            return .zero
        } set {
            transform = transform.scaledBy(x: newValue.x, y: newValue.y)
        }
    }
    
    @IBInspectable private var _rotationAngle: CGFloat {
        get {
            return 0
        } set {
            transform = transform.rotated(by: newValue)
        }
    }
}

@IBDesignable
extension UIView {
    
    @IBInspectable open var cornerRadius: CGFloat {
        get {
            return layer.cornerRadius
        } set {
            layer.cornerRadius = newValue
            layer.masksToBounds = newValue > 0
        }
    }
    
    @IBInspectable open var borderColor: UIColor? {
        get {
            return layer.borderColor != nil ? UIColor(cgColor: layer.borderColor!) : nil
        } set {
            layer.borderColor = newValue?.cgColor
        }
    }
    
    @IBInspectable open var borderWidth: CGFloat {
        get {
            return layer.borderWidth
        } set {
            layer.borderWidth = newValue
        }
    }
    
    @IBInspectable open var shadowColor: UIColor? {
        get {
            return layer.shadowColor != nil ? UIColor(cgColor: layer.shadowColor!) : nil
        } set {
            layer.shadowColor = newValue?.cgColor
        }
    }
    
    @IBInspectable open var shadowRadius: CGFloat {
        get {
            return layer.shadowRadius
        } set {
            layer.shadowRadius = newValue
        }
    }
    
    @IBInspectable open var shadowOpacity: Float {
        get {
            return layer.shadowOpacity
        } set {
            layer.shadowOpacity = newValue
        }
    }
    
    @IBInspectable open var shadowOffset: CGSize {
        get {
            return layer.shadowOffset
        } set {
            layer.shadowOffset = newValue
        }
    }
    
    @IBInspectable open var isDoubleSided: Bool {
        get {
            return layer.isDoubleSided
        } set {
            layer.isDoubleSided = newValue
        }
    }
}
