//
//  Utility.swift
//  Magicians
//
//  Created by Alchemist on 2017/10/29.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

#if os(iOS) || os(tvOS)
    import UIKit
#elseif os(macOS)
    import AppKit
#endif

//MARK: - Compatible
#if os(iOS) || os(tvOS)
    public typealias View = UIView
    public typealias ScrollView = UIScrollView
    public typealias EdgeInsets = UIEdgeInsets
    public typealias Color = UIColor
    public typealias ViewController = UIViewController
    
#elseif os(macOS)
    public typealias View = NSView
    public typealias ScrollView = NSScrollView
    public typealias EdgeInsets = NSEdgeInsets
    public typealias Color = NSColor
    public typealias ViewController = NSViewController
    
#endif

