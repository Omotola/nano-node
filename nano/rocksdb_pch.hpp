#pragma once

// Precompiled header for the bundled RocksDB static library.
//
// In a clean nano_node build, RocksDB's own headers dominate frontend parse
// cost: its backbone headers (rocksdb/options.h, rocksdb/listener.h and
// port/win/port_win.h via port.h) plus heavy STL are parsed by the large
// majority of RocksDB's translation units. RocksDB ships with no PCH, so
// precompiling that backbone once amortizes the parse across every RocksDB
// translation unit. This is the single largest untapped lever in the build.

// --- Tier 1: standard library ---
#include <algorithm>
#include <atomic>
#include <cassert>
#include <chrono>
#include <cinttypes>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

// --- RocksDB backbone (resolved via the rocksdb target's include dirs) ---
// port/port.h expands to port/win/port_win.h on Windows.
#include "port/port.h"
#include "rocksdb/options.h"
#include "rocksdb/listener.h"
