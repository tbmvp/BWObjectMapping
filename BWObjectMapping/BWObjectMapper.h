//
// Created by Bruno Wernimont on 2012
// Copyright 2012 BWObjectMapping
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>

#import "BWObjectMapping.h"

#define BW_DEFAULT_DATE_IDENTIFIER @"defaultDate"

@interface BWObjectMapper : NSObject

@property (nonatomic, readonly) NSDictionary *mappings;
@property (nonatomic, copy) BWObjectMappingObjectBlock objectBlock;
@property (nonatomic, copy) NSString *defaultDateFormat;
@property (nonatomic, copy) BWObjectMappingObjectDidMapObjectBlock didMapObjectBlock;
@property (nonatomic, strong) NSTimeZone *timeZone;
@property (nonatomic, strong) NSMutableDictionary *defaultMappings;

+ (BWObjectMapper *)shared;

+ (BWObjectMapper *)mapperWithSharedMappings;

- (void)mapKeyPath:(NSString *)keyPath toAttribute:(NSString *)attribute;

- (void)unregisterAllMappings;

- (void)registerMapping:(BWObjectMapping *)mapping;

- (void)registerMappingForClass:(Class)klass;

- (void)registerMappingForClass:(Class)klass mapping:(BWObjectMappingMappingBlock)mappingBlock;

- (void)registerMappingForClass:(Class)klass withRootKeyPath:(NSString *)keyPath mapping:(BWObjectMappingMappingBlock)mappingBlock;

- (void)registerMappingForClass:(Class)klass withRootKeyPath:(NSString *)keyPath;

- (void)registerMapping:(BWObjectMapping *)mapping withRootKeyPath:(NSString *)keyPath;

- (NSArray *)objectsFromJSON:(id)JSON withMapping:(BWObjectMapping *)mapping userInfo:(id)userInfo;

- (NSArray *)objectsFromJSON:(id)JSON withObjectClass:(Class)objectClass userInfo:(id)userInfo;

- (NSArray *)objectsFromJSON:(id)JSON userInfo:(id)userInfo;

- (id)objectFromJSON:(id)JSON withMapping:(BWObjectMapping *)mapping userInfo:(id)userInfo;

- (id)objectFromJSON:(id)JSON withMapping:(BWObjectMapping *)mapping existingObject:(id)object userInfo:(id)userInfo;

- (id)objectFromJSON:(id)JSON withObjectClass:(Class)objectClass userInfo:(id)userInfo;

- (id)objectFromJSON:(id)JSON withObjectClass:(Class)objectClass existingObject:(id)object userInfo:(id)userInfo;

- (id)objectFromJSON:(id)JSON userInfo:(id)userInfo;

- (id)objectFromJSON:(id)JSON existingObject:(id)object userInfo:(id)userInfo;

- (void)objectWithBlock:(BWObjectMappingObjectBlock)objectBlock;

- (void)didMapObjectWithBlock:(BWObjectMappingObjectDidMapObjectBlock)didMapBlock;

- (void)registerMappings:(NSDictionary *)mappings;

- (NSArray *)objectsFromJSON:(id)JSON withMapping:(BWObjectMapping *)mapping;

- (NSArray *)objectsFromJSON:(id)JSON withObjectClass:(Class)objectClass;

- (NSArray *)objectsFromJSON:(id)JSON;

- (id)objectFromJSON:(id)JSON withMapping:(BWObjectMapping *)mapping;

- (id)objectFromJSON:(id)JSON withMapping:(BWObjectMapping *)mapping existingObject:(id)object;

- (id)objectFromJSON:(id)JSON withObjectClass:(Class)objectClass;

- (id)objectFromJSON:(id)JSON withObjectClass:(Class)objectClass existingObject:(id)object;

- (id)objectFromJSON:(id)JSON;

- (id)objectFromJSON:(id)JSON existingObject:(id)object;

@end
