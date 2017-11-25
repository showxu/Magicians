//
//  Magicians
//
//  Created by Alchemist on 2017/11/11.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <vector>

template<typename R, typename T>
struct Transform {
    typedef R (^Factor)(T value);
};

template<typename R, typename T>
using Tranformation = R (^)(T value);



CGSize operator+(const CGSize &lhs, CGFloat f) {
    return (CGSize){lhs.width / f, lhs.height / f};
}


template <typename T>
static inline NSArray *ArrayWithVector(const std::vector<T> &vector,
                                            id (^block)(const T &value)) {
    NSMutableArray *result = [NSMutableArray arrayWithCapacity:vector.size()];
    for (const T &value : vector) {
        [result addObject: block(value)];
    }
    return result;
}

template <typename T>
static inline NSArray *ArrayWithVector(const std::vector<T> &vector, T(^block)(id value)) {
    NSMutableArray *result = [NSMutableArray arrayWithCapacity:vector.size()];
    return result;
}

template <typename T>
static inline std::vector<T> VectorWithElements(id<NSFastEnumeration> array,
                                                     T(^block)(id value)) {
    std::vector<T> result;
    for (id value in array) {
        result.push_back(block(value));
    }
    return result;
}

//void hehe(__attribute__((noescape)) NSArray* array) {
//    const std::vector<CGPoint> v = std::vector<CGPoint>{{10, 10}};
//
//    let newBlock = ^(id v) {
//        return CGPointZero;
//    };
//    //let block = ;
//    let a = ArrayWithVector(v, newBlock);
//    let b = ArrayWithVector(v, ^(const CGPoint & v) {
//        return (id)nil;
//    });
//}



