BUILD_DIR ?= build

.PHONY: all configure build test

all: build

configure:
	cmake -S . -B "$(BUILD_DIR)" -DBUILD_TESTING=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

build: configure
	cmake --build "$(BUILD_DIR)" --parallel

test: configure
	cmake --build "$(BUILD_DIR)" --target yliu_tests --parallel
	ctest --test-dir "$(BUILD_DIR)" --output-on-failure --no-tests=error
