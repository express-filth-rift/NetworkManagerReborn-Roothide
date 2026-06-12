#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#if __has_include(<roothide.h>)
#import <roothide.h>
#else
#define jbroot(path) (path)
#endif

#import <ControlCenterUIKit/CCUIToggleModule.h>

static NSString *_Nonnull rootlessPath(NSString* _Nonnull path) __attribute__((unused));
static NSString *_Nonnull rootlessPath(NSString* _Nonnull path) {
  return jbroot(path);
}

#define ROOT_PATH_NS(path) rootlessPath(@path)

@interface CCNetworkManager : CCUIToggleModule
@end

static BOOL getBool(NSString * _Nonnull key);
static NSString* _Nullable getValue(NSString * _Nonnull key);
static void writeSelectedNetwork();

static NSString * _Nonnull getNextEnabledNetwork();
static void sendSimpleAlert(NSString * _Nonnull title, NSString * _Nonnull content);

typedef void* CTServerConnectionRef;

extern CTServerConnectionRef _CTServerConnectionCreate(CFAllocatorRef, void *, void*);
extern void* _CTServerConnectionSetRATSelection(CTServerConnectionRef, CFStringRef, void*);

extern CFStringRef kCTRegistrationRATSelection0;
#define kGSM kCTRegistrationRATSelection0

extern CFStringRef kCTRegistrationRATSelection1;
#define kUMTS kCTRegistrationRATSelection1

extern CFStringRef kCTRegistrationRATSelection3;
#define kCDMA kCTRegistrationRATSelection3

extern CFStringRef kCTRegistrationRATSelection4;
#define kEVDO kCTRegistrationRATSelection4

extern CFStringRef kCTRegistrationRATSelection6;
#define kLTE kCTRegistrationRATSelection6

extern CFStringRef kCTRegistrationRATSelection7;
#define kAutomatic kCTRegistrationRATSelection7

extern CFStringRef kCTRegistrationRATSelection9;
#define kNRStandAlone kCTRegistrationRATSelection9

extern CFStringRef kCTRegistrationRATSelection10;
#define kNRNonStandAlone kCTRegistrationRATSelection10

extern CFStringRef kCTRegistrationRATSelection11;
#define kNR kCTRegistrationRATSelection11

static void callback() {};
