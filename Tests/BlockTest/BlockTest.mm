//
//  BlockTests.m
//  MagiciansTests
//
//  Created by Alchemist on 2016/11/24.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "Magicians.h"

#import <regex.h>
#import <vector>
#import <tuple>
#import <array>

@interface BlockTest : XCTestCase

@end

@implementation BlockTest

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
    let b = ^(void (^x)(void)){
        return ^(void (^)(void)){};
    }; _Pragma("unused(b)")
    let x0 = std::make_tuple((id)(^(BOOL animated) { return; }), UIViewController.self, @selector(viewWillAppear:), YES);
    let x1 = std::make_tuple((id)(^(BOOL animated) { return; }), UIViewController.self, @selector(viewDidLoad), NO);
    let cases = std::array<std::tuple<id, id, SEL, BOOL>, 2> {x0, x1};
    
    std::for_each(cases.begin(), cases.end(), [self](std::tuple<id, id, SEL, BOOL> x) {
//        XCTAssertEqual(block_getObjcTypesEquality(std::get<0>(x), std::get<1>(x), std::get<2>(x)),
//                       std::get<3>(x));
    });
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
