//
//  DULSDKModel.h
//  DJIUILibrary
//
//  Copyright © 2016 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DJISDK/DJISDK.h>
#import "DULObjectProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class DULWidget;
@class DULSDKModelValue;
@class DJIKeyManager;
@protocol DULObjectProtocol;


/**
 *  The DULSDKModel is the bridge between the SDK which provides the communication
 *  with the aircraft and the UILibrary which give a visual rendering on the data
 *  received. It is integrated with the any object conforming to DULObjectProtocol
 *  and is used when customizing objects to register to different SDK keys or to
 *  receive live view video.
 */
@interface DULSDKModel : NSObject


/**
 *  The singleton to be used whenever you need to use the SDKModel.
 *  
 *  @return The singleton to be used whenever you need to use the SDKModel
 */
+ (nullable instancetype)defaultSDKModel;


/**
 *  The key manager from the SDK's keyed interfaces. This will likely be removed in
 *  the future as it doesn't need to be used.
 *  
 *  @return The SDK KeyManager
 */
- (DJIKeyManager *)keyManager;

/*********************************************************************************/
#pragma mark - SDKModelKeys
/*********************************************************************************/


/**
 *  Allows an object to register dependent keys and receive data updates as soon as
 *  it is available.
 *  
 *  @param object The object for which we register the keys.
 *  @param dependentKeys The dependent keys which we are registering.
 */
- (void)registerDependentKeys:(nonnull NSArray <__kindof DJIKey *> *)dependentKeys forObject:(nonnull id <DULObjectProtocol>)object;


/**
 *  Removes data watching for all dependentKeys of a given object.
 *  
 *  @param object The object for which we unregister the keys.
 */
- (void)unregisterDependentKeysForObject:(nonnull id <DULObjectProtocol>)object;


@end

NS_ASSUME_NONNULL_END
