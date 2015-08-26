/**
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "status_models_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace apache { namespace airavata { namespace model { namespace status {

int _kExperimentStateValues[] = {
  ExperimentState::CREATED,
  ExperimentState::VALIDATED,
  ExperimentState::SCHEDULED,
  ExperimentState::LAUNCHED,
  ExperimentState::EXECUTING,
  ExperimentState::CANCELING,
  ExperimentState::CANCELED,
  ExperimentState::COMPLETED,
  ExperimentState::FAILED
};
const char* _kExperimentStateNames[] = {
  "CREATED",
  "VALIDATED",
  "SCHEDULED",
  "LAUNCHED",
  "EXECUTING",
  "CANCELING",
  "CANCELED",
  "COMPLETED",
  "FAILED"
};
const std::map<int, const char*> _ExperimentState_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(9, _kExperimentStateValues, _kExperimentStateNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

int _kTaskStateValues[] = {
  TaskState::CREATED,
  TaskState::EXECUTING,
  TaskState::COMPLETED,
  TaskState::FAILED,
  TaskState::CANCELED
};
const char* _kTaskStateNames[] = {
  "CREATED",
  "EXECUTING",
  "COMPLETED",
  "FAILED",
  "CANCELED"
};
const std::map<int, const char*> _TaskState_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(5, _kTaskStateValues, _kTaskStateNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

int _kProcessStateValues[] = {
  ProcessState::CREATED,
  ProcessState::VALIDATED,
  ProcessState::PRE_PROCESSING,
  ProcessState::CONFIGURING_WORKSPACE,
  ProcessState::INPUT_DATA_STAGING,
  ProcessState::EXECUTING,
  ProcessState::MONITORING,
  ProcessState::OUTPUT_DATA_STAGING,
  ProcessState::POST_PROCESSING,
  ProcessState::COMPLETED,
  ProcessState::FAILED,
  ProcessState::CANCELLING,
  ProcessState::CANCELED
};
const char* _kProcessStateNames[] = {
  "CREATED",
  "VALIDATED",
  "PRE_PROCESSING",
  "CONFIGURING_WORKSPACE",
  "INPUT_DATA_STAGING",
  "EXECUTING",
  "MONITORING",
  "OUTPUT_DATA_STAGING",
  "POST_PROCESSING",
  "COMPLETED",
  "FAILED",
  "CANCELLING",
  "CANCELED"
};
const std::map<int, const char*> _ProcessState_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(13, _kProcessStateValues, _kProcessStateNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

int _kJobStateValues[] = {
  JobState::SUBMITTED,
  JobState::QUEUED,
  JobState::ACTIVE,
  JobState::COMPLETE,
  JobState::CANCELED,
  JobState::FAILED,
  JobState::SUSPENDED,
  JobState::UNKNOWN
};
const char* _kJobStateNames[] = {
  "SUBMITTED",
  "QUEUED",
  "ACTIVE",
  "COMPLETE",
  "CANCELED",
  "FAILED",
  "SUSPENDED",
  "UNKNOWN"
};
const std::map<int, const char*> _JobState_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(8, _kJobStateValues, _kJobStateNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));


ExperimentStatus::~ExperimentStatus() throw() {
}


void ExperimentStatus::__set_state(const ExperimentState::type val) {
  this->state = val;
}

void ExperimentStatus::__set_timeOfStateChange(const int64_t val) {
  this->timeOfStateChange = val;
__isset.timeOfStateChange = true;
}

void ExperimentStatus::__set_reason(const std::string& val) {
  this->reason = val;
__isset.reason = true;
}

const char* ExperimentStatus::ascii_fingerprint = "CDBB2A55999EF5954D567AC5CF6F0786";
const uint8_t ExperimentStatus::binary_fingerprint[16] = {0xCD,0xBB,0x2A,0x55,0x99,0x9E,0xF5,0x95,0x4D,0x56,0x7A,0xC5,0xCF,0x6F,0x07,0x86};

uint32_t ExperimentStatus::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_state = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->state = (ExperimentState::type)ecast0;
          isset_state = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->timeOfStateChange);
          this->__isset.timeOfStateChange = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->reason);
          this->__isset.reason = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_state)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t ExperimentStatus::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("ExperimentStatus");

  xfer += oprot->writeFieldBegin("state", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->state);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.timeOfStateChange) {
    xfer += oprot->writeFieldBegin("timeOfStateChange", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->timeOfStateChange);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.reason) {
    xfer += oprot->writeFieldBegin("reason", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->reason);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(ExperimentStatus &a, ExperimentStatus &b) {
  using ::std::swap;
  swap(a.state, b.state);
  swap(a.timeOfStateChange, b.timeOfStateChange);
  swap(a.reason, b.reason);
  swap(a.__isset, b.__isset);
}

ExperimentStatus::ExperimentStatus(const ExperimentStatus& other1) {
  state = other1.state;
  timeOfStateChange = other1.timeOfStateChange;
  reason = other1.reason;
  __isset = other1.__isset;
}
ExperimentStatus& ExperimentStatus::operator=(const ExperimentStatus& other2) {
  state = other2.state;
  timeOfStateChange = other2.timeOfStateChange;
  reason = other2.reason;
  __isset = other2.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const ExperimentStatus& obj) {
  using apache::thrift::to_string;
  out << "ExperimentStatus(";
  out << "state=" << to_string(obj.state);
  out << ", " << "timeOfStateChange="; (obj.__isset.timeOfStateChange ? (out << to_string(obj.timeOfStateChange)) : (out << "<null>"));
  out << ", " << "reason="; (obj.__isset.reason ? (out << to_string(obj.reason)) : (out << "<null>"));
  out << ")";
  return out;
}


ProcessStatus::~ProcessStatus() throw() {
}


void ProcessStatus::__set_state(const ProcessState::type val) {
  this->state = val;
}

void ProcessStatus::__set_timeOfStateChange(const int64_t val) {
  this->timeOfStateChange = val;
__isset.timeOfStateChange = true;
}

void ProcessStatus::__set_reason(const std::string& val) {
  this->reason = val;
__isset.reason = true;
}

const char* ProcessStatus::ascii_fingerprint = "CDBB2A55999EF5954D567AC5CF6F0786";
const uint8_t ProcessStatus::binary_fingerprint[16] = {0xCD,0xBB,0x2A,0x55,0x99,0x9E,0xF5,0x95,0x4D,0x56,0x7A,0xC5,0xCF,0x6F,0x07,0x86};

uint32_t ProcessStatus::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_state = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast3;
          xfer += iprot->readI32(ecast3);
          this->state = (ProcessState::type)ecast3;
          isset_state = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->timeOfStateChange);
          this->__isset.timeOfStateChange = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->reason);
          this->__isset.reason = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_state)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t ProcessStatus::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("ProcessStatus");

  xfer += oprot->writeFieldBegin("state", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->state);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.timeOfStateChange) {
    xfer += oprot->writeFieldBegin("timeOfStateChange", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->timeOfStateChange);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.reason) {
    xfer += oprot->writeFieldBegin("reason", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->reason);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(ProcessStatus &a, ProcessStatus &b) {
  using ::std::swap;
  swap(a.state, b.state);
  swap(a.timeOfStateChange, b.timeOfStateChange);
  swap(a.reason, b.reason);
  swap(a.__isset, b.__isset);
}

ProcessStatus::ProcessStatus(const ProcessStatus& other4) {
  state = other4.state;
  timeOfStateChange = other4.timeOfStateChange;
  reason = other4.reason;
  __isset = other4.__isset;
}
ProcessStatus& ProcessStatus::operator=(const ProcessStatus& other5) {
  state = other5.state;
  timeOfStateChange = other5.timeOfStateChange;
  reason = other5.reason;
  __isset = other5.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const ProcessStatus& obj) {
  using apache::thrift::to_string;
  out << "ProcessStatus(";
  out << "state=" << to_string(obj.state);
  out << ", " << "timeOfStateChange="; (obj.__isset.timeOfStateChange ? (out << to_string(obj.timeOfStateChange)) : (out << "<null>"));
  out << ", " << "reason="; (obj.__isset.reason ? (out << to_string(obj.reason)) : (out << "<null>"));
  out << ")";
  return out;
}


TaskStatus::~TaskStatus() throw() {
}


void TaskStatus::__set_state(const TaskState::type val) {
  this->state = val;
}

void TaskStatus::__set_timeOfStateChange(const int64_t val) {
  this->timeOfStateChange = val;
__isset.timeOfStateChange = true;
}

void TaskStatus::__set_reason(const std::string& val) {
  this->reason = val;
__isset.reason = true;
}

const char* TaskStatus::ascii_fingerprint = "CDBB2A55999EF5954D567AC5CF6F0786";
const uint8_t TaskStatus::binary_fingerprint[16] = {0xCD,0xBB,0x2A,0x55,0x99,0x9E,0xF5,0x95,0x4D,0x56,0x7A,0xC5,0xCF,0x6F,0x07,0x86};

uint32_t TaskStatus::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_state = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast6;
          xfer += iprot->readI32(ecast6);
          this->state = (TaskState::type)ecast6;
          isset_state = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->timeOfStateChange);
          this->__isset.timeOfStateChange = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->reason);
          this->__isset.reason = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_state)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t TaskStatus::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("TaskStatus");

  xfer += oprot->writeFieldBegin("state", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->state);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.timeOfStateChange) {
    xfer += oprot->writeFieldBegin("timeOfStateChange", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->timeOfStateChange);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.reason) {
    xfer += oprot->writeFieldBegin("reason", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->reason);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(TaskStatus &a, TaskStatus &b) {
  using ::std::swap;
  swap(a.state, b.state);
  swap(a.timeOfStateChange, b.timeOfStateChange);
  swap(a.reason, b.reason);
  swap(a.__isset, b.__isset);
}

TaskStatus::TaskStatus(const TaskStatus& other7) {
  state = other7.state;
  timeOfStateChange = other7.timeOfStateChange;
  reason = other7.reason;
  __isset = other7.__isset;
}
TaskStatus& TaskStatus::operator=(const TaskStatus& other8) {
  state = other8.state;
  timeOfStateChange = other8.timeOfStateChange;
  reason = other8.reason;
  __isset = other8.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const TaskStatus& obj) {
  using apache::thrift::to_string;
  out << "TaskStatus(";
  out << "state=" << to_string(obj.state);
  out << ", " << "timeOfStateChange="; (obj.__isset.timeOfStateChange ? (out << to_string(obj.timeOfStateChange)) : (out << "<null>"));
  out << ", " << "reason="; (obj.__isset.reason ? (out << to_string(obj.reason)) : (out << "<null>"));
  out << ")";
  return out;
}


JobStatus::~JobStatus() throw() {
}


void JobStatus::__set_jobState(const JobState::type val) {
  this->jobState = val;
}

void JobStatus::__set_timeOfStateChange(const int64_t val) {
  this->timeOfStateChange = val;
__isset.timeOfStateChange = true;
}

void JobStatus::__set_reason(const std::string& val) {
  this->reason = val;
__isset.reason = true;
}

const char* JobStatus::ascii_fingerprint = "CDBB2A55999EF5954D567AC5CF6F0786";
const uint8_t JobStatus::binary_fingerprint[16] = {0xCD,0xBB,0x2A,0x55,0x99,0x9E,0xF5,0x95,0x4D,0x56,0x7A,0xC5,0xCF,0x6F,0x07,0x86};

uint32_t JobStatus::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_jobState = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast9;
          xfer += iprot->readI32(ecast9);
          this->jobState = (JobState::type)ecast9;
          isset_jobState = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->timeOfStateChange);
          this->__isset.timeOfStateChange = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->reason);
          this->__isset.reason = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_jobState)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t JobStatus::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("JobStatus");

  xfer += oprot->writeFieldBegin("jobState", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->jobState);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.timeOfStateChange) {
    xfer += oprot->writeFieldBegin("timeOfStateChange", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->timeOfStateChange);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.reason) {
    xfer += oprot->writeFieldBegin("reason", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->reason);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(JobStatus &a, JobStatus &b) {
  using ::std::swap;
  swap(a.jobState, b.jobState);
  swap(a.timeOfStateChange, b.timeOfStateChange);
  swap(a.reason, b.reason);
  swap(a.__isset, b.__isset);
}

JobStatus::JobStatus(const JobStatus& other10) {
  jobState = other10.jobState;
  timeOfStateChange = other10.timeOfStateChange;
  reason = other10.reason;
  __isset = other10.__isset;
}
JobStatus& JobStatus::operator=(const JobStatus& other11) {
  jobState = other11.jobState;
  timeOfStateChange = other11.timeOfStateChange;
  reason = other11.reason;
  __isset = other11.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const JobStatus& obj) {
  using apache::thrift::to_string;
  out << "JobStatus(";
  out << "jobState=" << to_string(obj.jobState);
  out << ", " << "timeOfStateChange="; (obj.__isset.timeOfStateChange ? (out << to_string(obj.timeOfStateChange)) : (out << "<null>"));
  out << ", " << "reason="; (obj.__isset.reason ? (out << to_string(obj.reason)) : (out << "<null>"));
  out << ")";
  return out;
}

}}}} // namespace