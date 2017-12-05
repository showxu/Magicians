//
//  RawRepresentable.h
//  Magicians
//
//  Created by Alchemist on 2016/11/23.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

#import <Foundation/Foundation.h>

/// A type that can be converted to and from an associated raw value.
///
/// With a `RawRepresentable` type, you can switch back and forth between a
/// custom type and an associated `RawValue` type without losing the value of
/// the original `RawRepresentable` type. Using the raw value of a conforming
/// type streamlines interoperation with Objective-C and legacy APIs and
/// simplifies conformance to other protocols, such as `Equatable`,
/// `Comparable`, and `Hashable`.
///
/// The `RawRepresentable` protocol is seen mainly in two categories of types:
/// enumerations with raw value types and option sets.
///
/// Enumerations with Raw Values
/// ============================
///
/// For any enumeration with a string, integer, or floating-point raw type, the
/// Swift compiler automatically adds `RawRepresentable` conformance. When
/// defining your own custom enumeration, you give it a raw type by specifying
/// the raw type as the first item in the enumeration's type inheritance list.
/// You can also use literals to specify values for one or more cases.
///
/// For example, the `Counter` enumeration defined here has an `Int` raw value
/// type and gives the first case a raw value of `1`:
///
///     enum Counter: Int {
///         case one = 1, two, three, four, five
///     }
///
/// You can create a `Counter` instance from an integer value between 1 and 5
/// by using the `init?(rawValue:)` initializer declared in the
/// `RawRepresentable` protocol. This initializer is failable because although
/// every case of the `Counter` type has a corresponding `Int` value, there
/// are many `Int` values that *don't* correspond to a case of `Counter`.
///
///     for i in 3...6 {
///         print(Counter(rawValue: i))
///     }
///     // Prints "Optional(Counter.three)"
///     // Prints "Optional(Counter.four)"
///     // Prints "Optional(Counter.five)"
///     // Prints "nil"
///
/// Option Sets
/// ===========
///
/// Option sets all conform to `RawRepresentable` by inheritance using the
/// `OptionSet` protocol. Whether using an option set or creating your own,
/// you use the raw value of an option set instance to store the instance's
/// bitfield. The raw value must therefore be of a type that conforms to the
/// `FixedWidthInteger` protocol, such as `UInt8` or `Int`. For example, the
/// `Direction` type defines an option set for the four directions you can
/// move in a game.
///
///     struct Directions: OptionSet {
///         let rawValue: UInt8
///
///         static let up    = Directions(rawValue: 1 << 0)
///         static let down  = Directions(rawValue: 1 << 1)
///         static let left  = Directions(rawValue: 1 << 2)
///         static let right = Directions(rawValue: 1 << 3)
///     }
///
/// Unlike enumerations, option sets provide a nonfailable `init(rawValue:)`
/// initializer to convert from a raw value, because option sets don't have an
/// enumerated list of all possible cases. Option set values have
/// a one-to-one correspondence with their associated raw values.
///
/// In the case of the `Directions` option set, an instance can contain zero,
/// one, or more of the four defined directions. This example declares a
/// constant with three currently allowed moves. The raw value of the
/// `allowedMoves` instance is the result of the bitwise OR of its three
/// members' raw values:
///
///     let allowedMoves: Directions = [.up, .down, .left]
///     print(allowedMoves.rawValue)
///     // Prints "7"
///
/// Option sets use bitwise operations on their associated raw values to
/// implement their mathematical set operations. For example, the `contains()`
/// method on `allowedMoves` performs a bitwise AND operation to check whether
/// the option set contains an element.
///
///     print(allowedMoves.contains(.right))
///     // Prints "false"
///     print(allowedMoves.rawValue & Directions.right.rawValue)
///     // Prints "0"
@protocol RawRepresentable<T>
    
/// The raw type that can be used to represent all values of the conforming
/// type.
///
/// Every distinct value of the conforming type has a corresponding unique
/// value of the `RawValue` type, but there may be values of the `RawValue`
/// type that don't have a corresponding value of the conforming type.
@property (class, nonatomic, readonly) Class RawValue;

/// Creates a new instance with the specified raw value.
///
/// If there is no value of the type that corresponds with the specified raw
/// value, this initializer returns `nil`. For example:
///
///     enum PaperSize: String {
///         case A4, A5, Letter, Legal
///     }
///
///     print(PaperSize(rawValue: "Legal"))
///     // Prints "Optional("PaperSize.Legal")"
///
///     print(PaperSize(rawValue: "Tabloid"))
///     // Prints "nil"
///
/// - Parameter rawValue: The raw value to use for the new instance.
- (instancetype)initWithRawValue:(id)rawValue;

/// The corresponding value of the raw type.
///
/// A new instance initialized with `rawValue` will be equivalent to this
/// instance. For example:
///
///     enum PaperSize: String {
///         case A4, A5, Letter, Legal
///     }
///
///     let selectedSize = PaperSize.Letter
///     print(selectedSize.rawValue)
///     // Prints "Letter"
///
///     print(selectedSize == PaperSize(rawValue: selectedSize.rawValue)!)
///     // Prints "true"
@property (nonatomic, readonly) id rawValue;

@end
