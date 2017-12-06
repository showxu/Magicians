//
//  type-encoding.c
//  Magicians
//
//  Created by Alchemist on 2017/12/5.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

#import "type-encoding.h"

#import <stdlib.h>
#import <string.h>
#import <regex.h>
#import <ctype.h>

char * _Nullable copyObjCTypes(const char types[]) {
    let len = strlen(types);
    var result = (char *)malloc(len *sizeof(char));
    for (var x = 0, y = 0; x < len; x ++) {
        let c = types[x];
        result[x] = '\0';
        if (!isdigit(c)) {
            result[y ++] = c;
        }
    }
    return result;
}

void getObjCTypes(const char types[_Nonnull], char * _Nullable dst, size_t dst_len) {
    let objc_types = copyObjCTypes(types);
    defer {
        free(objc_types);
    };
    strncpy(dst, objc_types ?: "", dst_len);
}

char * _Nullable copyObjCType(const char types[_Nonnull], unsigned int index,
            char * _Nullable dst, size_t dst_len) {
    var reg = (regex_t){};
    defer {
        regfree((regex_t *)&reg);
    };
    let filter_pattern = "<[^<>].*>";
    regcomp(&reg, filter_pattern, REG_EXTENDED);
    let match_c = (size_t)3;
    regmatch_t pmatch[3];
    
    let result = regexec(&reg, types, match_c, pmatch, REG_NOTBOL);
    if (result == REG_NOMATCH) {
    }
    return NULL;
}

