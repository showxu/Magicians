//
//  BlockTests.m
//  MagiciansTests
//
//  Created by Alchemist on 2016/11/24.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

@import XCTest;
@import Magicians;

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

- (void)testGetSignature {
    let typeAssert = ^(const char *argv[], const int argc, const char *types[]) {
        for (var i = 0; i < argc; i++) {
            XCTAssertFalse(strcmp(argv[i], types[i]));
        }
    };
    let blockAssert = ^(id block, const char *argv[], const int argc, const char *return_t) {
        let signature = block_getSignature(block);
        XCTAssertEqual(signature.numberOfArguments, argc);
   
        const char *argv_r[argc + 1];
        memcpy(argv_r, argv, argc);
        argv_r[argc] =  return_t;
        
        const char *types[argc + 1];
        for (var i = 0; i < argc; i++) {
            let t = [signature getArgumentTypeAtIndex:i];
            types[i] = t;
        }
        types[argc] =signature.methodReturnType;
        typeAssert(argv, argc, types);
    };

    // __NSGlobalBlock__
    let block = ^(id vc, BOOL animated) {
        return;
    };
    const char *argv[] = {"@?",  @encode(id), @encode(BOOL)};
    let argc = sizeof(argv)/sizeof(argv[0]);
    blockAssert(block, argv, argc, @encode(void));
}

- (void)testMatchSignature {
    // __NSGlobalBlock__
    let block = ^(NSInvocation *ivc) {
        return;
    };
    let result = block_matchSignature(block, NSObject.class, @selector(forwardInvocation:));
    XCTAssertTrue(result);
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
