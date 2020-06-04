LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := owl

LOCAL_CFLAGS := \
    -Wall \
    -Wextra \
    -Wno-macro-redefined \
    -Wno-sometimes-uninitialized \

LOCAL_SRC_FILES := \
    src/log.c \
    src/state.c \
    src/election.c \
    src/sync.c \
    src/channel.c \
    src/schedule.c \
    src/tx.c \
    src/rx.c \
    src/frame.c \
    src/crc32.c \
    src/wire.c \
    src/peers.c \
    src/version.c \
    src/hashmap.c \
    src/siphash24.c \
    src/circular_buffer.c \

LOCAL_SRC_FILES += \
    daemon/io.c \
    daemon/core.c \
    daemon/netutils.c \
    daemon/owl.c \

LOCAL_SHARED_LIBRARIES := \
    radiotap \
    libpcap2 \
    libnl3 \
    libev \

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/src \
    $(LOCAL_PATH)/daemon \
    external/radiotap/include \
    external/libpcap2 \
    external/libnl3/include \
    external/libev \

include $(BUILD_EXECUTABLE)
