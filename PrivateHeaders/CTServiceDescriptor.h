//
//  CTServiceDescriptor.h
//  CoreTelephony
//
//  Private header for CTServiceDescriptor
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CTServiceDescriptorContainer : NSObject <NSSecureCoding, NSCopying>
@property (nonatomic, readonly) NSArray<NSObject *> *descriptors;
- (instancetype)initWithDescriptors:(NSArray *)descriptors;
@end

@interface CTServiceDescriptor : NSObject <NSSecureCoding, NSCopying>
@property (nonatomic, readonly) NSString *identifier;
@property (nonatomic, assign) long long domain;
@property (nonatomic, retain, nullable) NSNumber *instance;
- (instancetype)initWithDomain:(long long)domain instance:(NSNumber *)instance;
@end

NS_ASSUME_NONNULL_END
