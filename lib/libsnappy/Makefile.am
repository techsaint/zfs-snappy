include $(top_srcdir)/config/Rules.am

#AM_CFLAGS += $(DEBUG_STACKFLAGS) $(FRAME_LARGER_THAN)

AM_CLFAGS = -Wall -g -O2 -DNDEBUG=0  -DSG=1 $(DEBUG_STACKFLAGS) $(FRAME_LARGER_THAN)

DEFAULT_INCLUDES += \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/lib/libspl/include

noinst_LTLIBRARIES = libsnappy.la

libsnappy_la_SOURCES = \
	$(top_srcdir)/lib/libsnappy/snappy.c
