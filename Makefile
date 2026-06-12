include $(THEOS)/makefiles/common.mk

export TARGET = iphone:clang:latest:11.0
export ARCHS = arm64 arm64e

BUNDLE_NAME = NetworkManager
NetworkManager_BUNDLE_EXTENSION = bundle
NetworkManager_FILES = CCNetworkManager.x
NetworkManager_FRAMEWORKS = CoreTelephony
NetworkManager_PRIVATE_FRAMEWORKS = ControlCenterUIKit
NetworkManager_INSTALL_PATH = /Library/ControlCenter/Bundles/

NetworkManager_CFLAGS += "-Wno-unused-function"
NetworkManager_CFLAGS += "-Wno-unused-variable"

# Add roothide library for roothide builds
ifeq ($(THEOS_PACKAGE_SCHEME),roothide)
NetworkManager_LDFLAGS += -lroothide
endif

# Allow undefined symbols (will be resolved at runtime)
NetworkManager_LDFLAGS += -Wl,-undefined,dynamic_lookup

after-install::
	install.exec "killall -9 SpringBoard"

include $(THEOS_MAKE_PATH)/bundle.mk
SUBPROJECTS += networkmanagerprefs
include $(THEOS_MAKE_PATH)/aggregate.mk
