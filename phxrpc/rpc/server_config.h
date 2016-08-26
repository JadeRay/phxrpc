/*
Tencent is pleased to support the open source community by making 
PhxRPC available.
Copyright (C) 2016 THL A29 Limited, a Tencent company. 
All rights reserved.

Licensed under the BSD 3-Clause License (the "License"); you may 
not use this file except in compliance with the License. You may 
obtain a copy of the License at

https://opensource.org/licenses/BSD-3-Clause

Unless required by applicable law or agreed to in writing, software 
distributed under the License is distributed on an "AS IS" basis, 
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
implied. See the License for the specific language governing 
permissions and limitations under the License.

See the AUTHORS file for names of contributors.
*/

#pragma once

#include <string>
#include <memory>
#include "phxrpc/file.h"

namespace phxrpc {

class ServerConfig {
public:
    ServerConfig();
    virtual ~ServerConfig();

    bool Read(const char * config_file);

    virtual bool DoRead(Config & config);

    void SetBindIP(const char * ip);
    const char * GetBindIP() const;

    void SetPort(int port);
    int GetPort() const;

    void SetMaxThreads(int max_threads);
    int GetMaxThreads() const;

    void SetSocketTimeoutMS(int socket_timeout_ms);
    int GetSocketTimeoutMS() const;

    void SetPackageName(const char * package_name);
    const char * GetPackageName() const;

private:
    char bind_ip_[32];
    int port_;
    int max_threads_;
    int socket_timeout_ms_;
    char package_name_[64];
};

class HshaServerConfig : public ServerConfig {
public:
    HshaServerConfig();
    ~HshaServerConfig();

    bool DoRead(Config & config);

    void SetMaxConnections(const int max_connections);
    int GetMaxConnections() const;

    void SetMaxQueueLength(const int max_queue_length);
    int GetMaxQueueLength() const;

    void SetFastRejectThresholdMS(const int fast_reject_threshold_ms);
    int GetFastRejectThresholdMS() const;

    void SetIOThreadCount(const int io_thread_count);
    int GetIOThreadCount() const;

private:
    int max_connections_;
    int max_queue_length_;
    int fast_reject_threshold_ms_;
    int io_thread_count_;
};

}

