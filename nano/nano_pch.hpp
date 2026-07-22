#pragma once

// Precompiled header for nano's first-party C++ libraries.
//
// Contents target the headers that dominate frontend parse cost in a clean
// nano_node build: heavy STL (notably <chrono>), nano's spdlog/fmt-based
// logging, boost.asio, and boost.multiprecision (pulled in by nano's core
// number types). Precompiling those stable STL / third-party headers once
// amortizes the parse across all nano translation units. Only standard-library
// and stable third-party headers are included here; volatile nano project
// headers are deliberately excluded.

// --- Tier 1: standard library (never changes) ---
#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <functional>
#include <future>
#include <map>
#include <memory>
#include <mutex>
#include <optional>
#include <ostream>
#include <shared_mutex>
#include <sstream>
#include <string>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// --- Tier 2: third-party (changes only on dependency upgrade) ---
#include <boost/asio.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <spdlog/spdlog.h>
