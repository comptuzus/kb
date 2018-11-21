###############################################################################
# kb is a kass brik
#
###############################################################################

LOCAL_PATH := $(call my-dir)

###############################################################################
# main
###############################################################################

include $(CLEAR_VARS)

LOCAL_MODULE := kb
LOCAL_SRC_FILES := \
        sources/src/main.cpp

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/sources/includes/

LOCAL_LIBRARIES := sfml

include $(BUILD_EXECUTABLE)
include $(LOCAL_PATH)/SFML/atom.mk
