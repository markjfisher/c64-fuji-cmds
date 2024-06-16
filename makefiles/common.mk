-include makefiles/fujinet-lib.mk

VERSION_FILE := src/version.txt
GIT_VERSION := $(shell git rev-parse --short HEAD)
VERSION_STRING := $(strip $(file < $(VERSION_FILE)))-$(GIT_VERSION)

CFLAGS += -DVERSION_STRING=\"$(VERSION_STRING)\"
CFLAGS += -Osir
