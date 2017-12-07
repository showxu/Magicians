//
//  objc-debug.h
//  Magicians
//
//  Created by Alchemist on 2017/12/4.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

_Pragma("once")

#import <objc/objc.h>
#import <objc/runtime.h>

#ifdef __cplusplus
#import <tuple>
#endif

_Pragma("clang assume_nonnull begin")

#ifdef __cplusplus

/**
 * Creates and returns a list of pointers to all registered class definitions.
 *
 * @return A nil terminated array of classes.
 *
 * @see objc_getClassList
 */
OBJC_VISIBLE std::tuple<Class _Nonnull * _Nullable, int>
objc_getClassList(void)
    OBJC_AVAILABLE(10.7, 3.1, 9.0, 1.0, 2.0);


/**
 * Describes the properties declared by a class.
 *
 * @param cls The class you want to inspect.
 *  If \e outCount is \c NULL, the length is not returned.
 *
 * @return An array of pointers of type \c objc_property_t describing the properties
 *  declared by the class. Any properties declared by superclasses are not included.
 *  The array contains \c *outCount pointers followed by a \c NULL terminator. You must free the array with \c free().
 *
 *  If \e cls declares no properties, or \e cls is \c Nil, returns \c NULL and \c *outCount is \c 0.
 */
OBJC_VISIBLE std::tuple<objc_property_t _Nonnull * _Nullable, int>
class_getPropertyList(Class _Nullable cls)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);


/**
 * Describes the instance variables declared by a class.
 *
 * @param cls The class to inspect.
 *
 *  If the class declares no instance variables, or cls is Nil, NULL is returned and count is 0.
 */
OBJC_VISIBLE std::tuple<Ivar _Nonnull * _Nullable, int>
class_getInstanceVariableList(Class _Nullable cls)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);


/**
 * Describes the class variables declared by a class.
 *
 * @param cls The class to inspect.
 *
 *  If the class declares no class variables, or cls is Nil, NULL is returned and count is 0.
 */
OBJC_VISIBLE std::tuple<Ivar _Nonnull * _Nullable, int>
class_getClassVariableList(Class _Nullable cls)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);


/**
 * Describes the instance methods implemented by a class.
 *
 * @param cls The class you want to inspect.
 *  If outCount is NULL, the length is not returned.
 *
 * @return An array of pointers of type Method describing the instance methods
 *  implemented by the class—any instance methods implemented by superclasses are not included.
 *  The array contains *outCount pointers followed by a NULL terminator. You must free the array with free().
 *
 *  If cls implements no instance methods, or cls is Nil, returns NULL and *outCount is 0.
 *
 * @note To get the class methods of a class, use \c class_copyMethodList(object_getClass(cls), &count).
 * @note To get the implementations of methods that may be implemented by superclasses,
 *  use \c class_getInstanceMethod or \c class_getClassMethod.
 */
OBJC_VISIBLE std::tuple<Method _Nonnull * _Nullable, int>
class_getInstanceMethodList(Class _Nullable cls)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);


/**
 * Describes the instance methods implemented by a class.
 *
 * @param cls The class you want to inspect.
 *  If outCount is NULL, the length is not returned.
 *
 * @return An array of pointers of type Method describing the instance methods
 *  implemented by the class—any instance methods implemented by superclasses are not included.
 *  The array contains *outCount pointers followed by a NULL terminator. You must free the array with free().
 *
 *  If cls implements no instance methods, or cls is Nil, returns NULL and *outCount is 0.
 *
 * @note To get the class methods of a class, use \c class_copyMethodList(object_getClass(cls), &count).
 * @note To get the implementations of methods that may be implemented by superclasses,
 *  use \c class_getInstanceMethod or \c class_getClassMethod.
 */
OBJC_VISIBLE std::tuple<Method _Nonnull * _Nullable, int>
class_getClassMethodList(Class _Nullable cls)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);


/**
 * Describes the protocols adopted by a class.
 *
 * @param cls The class you want to inspect.
 *  If outCount is NULL, the length is not returned.
 *
 * @return An array of pointers of type Protocol* describing the protocols adopted
 *  by the class. Any protocols adopted by superclasses or other protocols are not included.
 *  The array contains *outCount pointers followed by a NULL terminator. You must free the array with free().
 *
 *  If cls adopts no protocols, or cls is Nil, returns NULL and *outCount is 0.
 */
OBJC_VISIBLE std::tuple<Protocol * __unsafe_unretained _Nonnull * _Nullable, int>
class_getProtocolList(Class _Nullable cls)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);

#endif


_Pragma("clang assume_nonnull end")

