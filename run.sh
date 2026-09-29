#!/usr/bin/env bash

cpr() {
    local src="${1:-a.cpp}"
    local bin
    bin=$(mktemp /tmp/cpr.XXXXXX) || return
    if g++ -std=c++20 -O2 -Wall "$src" -o "$bin"; then
        "$bin"
    fi
    rm -f "$bin"
}
