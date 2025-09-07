#!/bin/bash
find src -name "*.src" -exec touch {} \;
find test -name "*.src" -exec touch {} \;
