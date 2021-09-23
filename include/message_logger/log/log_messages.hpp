/**********************************************************************
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2014, Christian Gehring
 * All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Autonomous Systems Lab nor ETH Zurich
 *     nor the names of its contributors may be used to endorse or
 *     promote products derived from this software without specific
 *     prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */
/*!
* @file     log_messages.hpp
* @author   Christian Gehring, Peter Fankhauser
* @date     Dec, 2014
* @brief
*/
#pragma once

#include "message_logger/common/preprocessor_defines.hpp"
#include "message_logger/log/log_messages_backend.hpp"

namespace message_logger {
namespace log {

#if (MELO_MIN_SEVERITY) <= (MELO_SEVERITY_FATAL)
#define MELO_FATAL(logger, ...) MELO_LOG(logger, ::message_logger::log::levels::Fatal, __VA_ARGS__)
#define MELO_FATAL_STREAM(logger, message) MELO_LOG_STREAM(logger, ::message_logger::log::levels::Fatal, message)
#else
#define MELO_FATAL(logger, ...)
#define MELO_FATAL_STREAM(logger, message)
#endif

#if (MELO_MIN_SEVERITY) <= (MELO_SEVERITY_ERROR)
#define MELO_ERROR(logger, ...) MELO_LOG(logger, ::message_logger::log::levels::Error, __VA_ARGS__)
#define MELO_ERROR_FP(logger, ...) MELO_LOG_FP(logger, ::message_logger::log::levels::Error, __VA_ARGS__)
#define MELO_ERROR_STREAM(logger, message) MELO_LOG_STREAM(logger, ::message_logger::log::levels::Error, message)
#define MELO_ERROR_STREAM_FP(logger, message) MELO_LOG_STREAM_FP(logger, ::message_logger::log::levels::Error, message)
#define MELO_ERROR_THROTTLE(logger, rate, ...) MELO_LOG_THROTTLE(logger, rate, ::message_logger::log::levels::Error, __VA_ARGS__)
#define MELO_ERROR_THROTTLE_STREAM(logger, rate, message) MELO_LOG_THROTTLE_STREAM(logger, rate, ::message_logger::log::levels::Error, message)
#else
#define MELO_ERROR(logger, ...)
#define MELO_ERROR_FP(logger, ...)
#define MELO_ERROR_STREAM(logger, message)
#define MELO_ERROR_STREAM_FP(logger, message)
#define MELO_ERROR_THROTTLE(logger, rate, ...)
#define MELO_ERROR_THROTTLE_STREAM(logger, rate, message)
#endif

#if (MELO_MIN_SEVERITY) <= (MELO_SEVERITY_WARN)
#define MELO_WARN(logger, ...) MELO_LOG(logger, ::message_logger::log::levels::Warn, __VA_ARGS__)
#define MELO_WARN_FP(logger, ...) MELO_LOG_FP(logger, ::message_logger::log::levels::Warn, __VA_ARGS__)
#define MELO_WARN_STREAM(logger, message) MELO_LOG_STREAM(logger, ::message_logger::log::levels::Warn, message)
#define MELO_WARN_STREAM_FP(logger, message) MELO_LOG_STREAM_FP(logger, ::message_logger::log::levels::Warn, message)
#define MELO_WARN_THROTTLE(logger, rate, ...) MELO_LOG_THROTTLE(logger, rate, ::message_logger::log::levels::Warn, __VA_ARGS__)
#define MELO_WARN_THROTTLE_STREAM(logger, rate, message) MELO_LOG_THROTTLE_STREAM(logger, rate, ::message_logger::log::levels::Warn, message)
#else
#define MELO_WARN(logger, ...)
#define MELO_WARN_FP(logger, ...)
#define MELO_WARN_STREAM(logger, message)
#define MELO_WARN_STREAM_FP(logger, message)
#define MELO_WARN_THROTTLE(logger, rate, ...)
#define MELO_WARN_THROTTLE_STREAM(logger, rate, message)
#endif

#if (MELO_MIN_SEVERITY) <= (MELO_SEVERITY_INFO)
#define MELO_INFO(logger, ...) MELO_LOG(logger, ::message_logger::log::levels::Info, __VA_ARGS__)
#define MELO_INFO_FP(logger, ...) MELO_LOG_FP(logger, ::message_logger::log::levels::Info, __VA_ARGS__)
#define MELO_INFO_STREAM(logger, message) MELO_LOG_STREAM(logger, ::message_logger::log::levels::Info, message)
#define MELO_INFO_STREAM_FP(logger, message) MELO_LOG_STREAM_FP(logger, ::message_logger::log::levels::Info, message)
#define MELO_INFO_THROTTLE(logger, rate, ...) MELO_LOG_THROTTLE(logger, rate, ::message_logger::log::levels::Info, __VA_ARGS__)
#define MELO_INFO_THROTTLE_STREAM(logger, rate, message) MELO_LOG_THROTTLE_STREAM(logger, rate, ::message_logger::log::levels::Info, message)
#else
#define MELO_INFO(logger, ...)
#define MELO_INFO_FP(logger, ...)
#define MELO_INFO_STREAM(logger, message)
#define MELO_INFO_STREAM_FP(logger, message)
#define MELO_INFO_THROTTLE(logger, rate, ...)
#define MELO_INFO_THROTTLE_STREAM(logger, rate, message)
#endif

#if (MELO_MIN_SEVERITY) <= (MELO_SEVERITY_DEBUG)
#define MELO_DEBUG(logger, ...) MELO_LOG(logger, ::message_logger::log::levels::Debug, __VA_ARGS__)
#define MELO_DEBUG_FP(logger, ...) MELO_LOG_FP(logger, ::message_logger::log::levels::Debug, __VA_ARGS__)
#define MELO_DEBUG_STREAM(logger, message) MELO_LOG_STREAM(logger, ::message_logger::log::levels::Debug, message)
#define MELO_DEBUG_STREAM_FP(logger, message) MELO_LOG_STREAM_FP(logger, ::message_logger::log::levels::Debug, message)
#define MELO_DEBUG_THROTTLE(logger, rate, ...) MELO_LOG_THROTTLE(logger, rate, ::message_logger::log::levels::Debug, __VA_ARGS__)
#define MELO_DEBUG_THROTTLE_STREAM(logger, rate, message) MELO_LOG_THROTTLE_STREAM(logger, rate, ::message_logger::log::levels::Debug, message)
#else
#define MELO_DEBUG(logger, ...)
#define MELO_DEBUG_FP(logger, ...)
#define MELO_DEBUG_STREAM(logger, message)
#define MELO_DEBUG_STREAM_FP(logger, message)
#define MELO_DEBUG_THROTTLE(logger, rate, ...)
#define MELO_DEBUG_THROTTLE_STREAM(logger, rate, ...)
#endif

} // namespace log
} // namespace message_logger
