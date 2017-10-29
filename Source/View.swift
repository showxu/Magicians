//
//  View.swift
//
//  Created by XuXudong on 4/7/17.
//
//

#if os(iOS) || os(tvOS)
    import UIKit
#elseif os(macOS)
    import AppKit
#endif

#if os(iOS) || os(tvOS)
// MARK: - UIView @IBInspectable extension
@IBDesignable
extension UIView {
    
    @IBInspectable public var cornerRadius: CGFloat {
        get {
            return layer.cornerRadius
        } set {
            layer.cornerRadius = newValue
        }
    }
    
    @IBInspectable public var borderColor: UIColor? {
        get {
            guard let cgColor = layer.borderColor else {
                return nil
            }
            return UIColor(cgColor: cgColor)
        } set {
            layer.borderColor = newValue?.cgColor
        }
    }
    
    @IBInspectable public var borderWidth: CGFloat {
        get {
            return layer.borderWidth
        } set {
            layer.borderWidth = newValue
        }
    }
    
    @IBInspectable public var shadowColor: UIColor? {
        get {
            return layer.shadowColor != nil ? UIColor(cgColor: layer.shadowColor!) : nil
        } set {
            layer.shadowColor = newValue?.cgColor
        }
    }
    
    @IBInspectable public var shadowRadius: CGFloat {
        get {
            return layer.shadowRadius
        } set {
            layer.shadowRadius = newValue
        }
    }
    
    @IBInspectable public var shadowOpacity: Float {
        get {
            return layer.shadowOpacity
        } set {
            layer.shadowOpacity = newValue
        }
    }
    
    @IBInspectable public var shadowOffset: CGSize {
        get {
            return layer.shadowOffset
        } set {
            layer.shadowOffset = newValue
        }
    }
    
    @IBInspectable public var isDoubleSided: Bool {
        get {
            return layer.isDoubleSided
        } set {
            layer.isDoubleSided = newValue
        }
    }
}
    
@IBDesignable
extension UIView {
    
    @IBInspectable var _frame: CGRect {
        get {
            return frame
        } set {
            frame = newValue
        }
    }
    
    @IBInspectable var _bounds: CGRect {
        get {
            return bounds
        } set {
            bounds = newValue
        }
    }
    
    @IBInspectable var _center: CGPoint {
        get {
            return center
        } set {
            center = newValue
        }
    }
}
    
#elseif os(macOS)
// MARK: - NSView @IBInspectable extension
@IBDesignable
extension NSView {
    
    @IBInspectable public var cornerRadius: CGFloat {
        get {
            return layer?.cornerRadius ?? 0
        } set {
            layer?.cornerRadius = newValue
        }
    }
}
    
#endif
