#ifndef _ZNP_H_
#define _ZNP_H_
#include <boost/fusion/include/define_struct.hpp>
#include <boost/variant.hpp>
#include <iostream>

namespace znp {
enum class ZnpCommandType { POLL = 0, SREQ = 2, AREQ = 4, SRSP = 6 };

enum class ZnpSubsystem {
  RPC_Error = 0,
  SYS = 1,
  MAC = 2,
  NWK = 3,
  AF = 4,
  ZDO = 5,
  SAPI = 6,
  UTIL = 7,
  DEBUG = 8,
  APP = 9
};
std::ostream& operator<<(std::ostream& stream, const ZnpSubsystem& subsys);

enum class ZnpStatus : uint8_t {
  Success = 0x00,
  Failure = 0x01,
  InvalidParameter = 0x02,
  MemError = 0x03,
  BufferFull = 0x11
};
std::ostream& operator<<(std::ostream& stream, const ZnpCommandType& type);

typedef uint64_t IEEEAddress;
typedef uint16_t ShortAddress;

enum class AddrMode : uint8_t {
  NotPresent = 0,
  Group = 1,
  ShortAddress = 2,
  IEEEAddress = 3,
  Broadcast = 0xFF
};

// Commands in the SYS subsystem
enum class SysCommand : uint8_t {
  RESET = 0x00,
  PING = 0x01,
  VERSION = 0x02,
  SET_EXTADDR = 0x03,
  GET_EXTADDR = 0x04,
  RAM_READ = 0x05,
  RAM_WRITE = 0x06,
  OSAL_NV_ITEM_INIT = 0x07,
  OSAL_NV_READ = 0x08,
  OSAL_NV_WRITE = 0x09,
  OSAL_START_TIMER = 0x0A,
  OSAL_STOP_TIMER = 0x0B,
  RANDOM = 0x0C,
  ADC_READ = 0x0D,
  GPIO = 0x0E,
  STACK_TUNE = 0x0F,
  SET_TIME = 0x10,
  GET_TIME = 0x11,
  OSAL_NV_DELETE = 0x12,
  OSAL_NV_LENGTH = 0x13,
  TEST_RF = 0x40,
  TEST_LOOPBACK = 0x41,
  RESET_IND = 0x80,
  OSAL_TIMER_EXPIRED = 0x81,
};
std::ostream& operator<<(std::ostream& stream, SysCommand command);

// Commands in the AF subsystem
enum class AfCommand : uint8_t {
  REGISTER = 0x00,
  DATA_REQUEST = 0x01,
  DATA_REQUEST_EXT = 0x02,
  DATA_REQUEST_SRC_RTG = 0x03,
  INTER_PAN_CTL = 0x10,
  DATA_STORE = 0x11,
  DATA_RETRIEVE = 0x12,
  APSF_CONFIG_SET = 0x13,
  DATA_CONFIRM = 0x80,
  REFLECT_ERROR = 0x83,
  INCOMING_MSG = 0x81,
  INCOMING_MSG_EXT = 0x82
};
std::ostream& operator<<(std::ostream& stream, AfCommand command);

// Commands in the ZDO subsystem
enum class ZdoCommand : uint8_t {
  NWK_ADDR_REQ = 0x00,
  IEEE_ADDR_REQ = 0x01,
  NODE_DESC_REQ = 0x02,
  POWER_DESC_REQ = 0x03,
  SIMPLE_DESC_REQ = 0x04,
  ACTIVE_EP_REQ = 0x05,
  MATCH_DESC_REQ = 0x06,
  COMPLEX_DESC_REQ = 0x07,
  USER_DESC_REQ = 0x08,
  DEVICE_ANNCE = 0x0A,
  USER_DESC_SET = 0x0B,
  SERVER_DISC_REQ = 0x0C,
  END_DEVICE_BIND_REQ = 0x20,
  BIND_REQ = 0x21,
  UNBIND_REQ = 0x22,
  SET_LINK_KEY = 0x23,
  REMOVE_LINK_KEY = 0x24,
  GET_LINK_KEY = 0x25,
  MGMT_NWK_DISC_REQ = 0x30,
  MGMT_LQI_REQ = 0x31,
  MGMT_RTQ_REQ = 0x32,
  MGMT_BIND_REQ = 0x33,
  MGMT_LEAVE_REQ = 0x34,
  MGMT_DIRECT_JOIN_REQ = 0x35,
  MGMT_PERMIT_JOIN_REQ = 0x36,
  MGMT_NWK_UPDATE_REQ = 0x37,
  MSG_CB_REGISTER = 0x3E,
  MGS_CB_REMOVE = 0x3F,
  STARTUP_FROM_APP = 0x40,
  AUTO_FIND_DESTINATION = 0x41,
  NWK_ADDR_RSP = 0x80,
  IEEE_ADDR_RSP = 0x81,
  NODE_DESC_RSP = 0x82,
  POWER_DESC_RSP = 0x83,
  SIMPLE_DESC_RSP = 0x84,
  ACTIVE_EP_RSP = 0x85,
  MATCH_DESC_RSP = 0x86,
  COMPLEX_DESC_RSP = 0x87,
  USER_DESC_RSP = 0x88,
  USER_DESC_CONF = 0x89,
  SERVER_DISC_RSP = 0x8A,
  END_DEVICE_BIND_RSP = 0xA0,
  BIND_RSP = 0xA1,
  UNBIND_RSP = 0xA2,
  MGMT_NWK_DISC_RSP = 0xB0,
  MGMT_LQI_RSP = 0xB1,
  MGMT_RTG_RSP = 0xB2,
  MGMT_BIND_RSP = 0xB3,
  MGMT_LEAVE_RSP = 0xB4,
  MGMT_DIRECT_JOIN_RSP = 0xB5,
  MGMT_PERMIT_JOIN_RSP = 0xB6,
  STATE_CHANGE_IND = 0xC0,
  END_DEVICE_ANNCE_IND = 0xC1,
  MATCH_DESC_RSP_SENT = 0xC2,
  STATUS_ERROR_RSP = 0xC3,
  SRC_RTG_IND = 0xC4,
  LEAVE_IND = 0xC9,
  TC_DEV_IND = 0xCA,
  PERMIT_JOIN_IND = 0xCB,
  MSG_CB_INCOMING = 0xFF
};

std::ostream& operator<<(std::ostream& stream, ZdoCommand command);
// Commands in the SAPI subsystem
enum class SapiCommand : uint8_t {
  START_REQUEST = 0x00,
  BIND_DEVICE = 0x01,
  ALLOW_BIND = 0x02,
  SEND_DATA_REQUEST = 0x03,
  READ_CONFIGURATION = 0x04,
  WRITE_CONFIGURATION = 0x05,
  GET_DEVICE_INFO = 0x06,
  FIND_DEVICE_REQUEST = 0x07,
  PERMIT_JOINING_REQUEST = 0x08,
  SYSTEM_RESET = 0x09,
  START_CONFIRM = 0x80,
  BIND_CONFIRM = 0x81,
  ALLOW_BIND_CONFIRM = 0x82,
  SEND_DATA_CONFIRM = 0x83,
  FIND_DEVICE_CONFIRM = 0x85,
  RECEIVE_DATA_INDICATION = 0x87,
};

std::ostream& operator<<(std::ostream& stream, SapiCommand command);

class ZnpCommand {
 public:
  ZnpCommand(ZnpSubsystem subsystem, uint8_t command);
  ZnpCommand(SysCommand command);
  ZnpCommand(AfCommand command);
  ZnpCommand(ZdoCommand command);
  ZnpCommand(SapiCommand command);

  ZnpSubsystem Subsystem();
  uint8_t RawCommand();

  friend bool operator==(const ZnpCommand& a, const ZnpCommand& b);
  friend bool operator!=(const ZnpCommand& a, const ZnpCommand& b);
  friend bool operator<=(const ZnpCommand& a, const ZnpCommand& b);
  friend bool operator>=(const ZnpCommand& a, const ZnpCommand& b);
  friend bool operator<(const ZnpCommand& a, const ZnpCommand& b);
  friend bool operator>(const ZnpCommand& a, const ZnpCommand& b);
  friend std::ostream& operator<<(std::ostream& stream, ZnpCommand command);

 private:
  std::pair<ZnpSubsystem, uint8_t> value_;
};

enum class Capability : uint16_t {
  SYS = 0x0001,
  MAC = 0x0002,
  NWK = 0x0004,
  AF = 0x0008,
  ZDO = 0x0010,
  SAPI = 0x0020,
  UTIL = 0x0040,
  DEBUG = 0x0080,
  APP = 0x0100,
  ZOAD = 0x1000
};

std::ostream& operator<<(std::ostream& stream, const Capability& cap);

enum class ResetReason : uint8_t { PowerUp = 0, External = 1, Watchdog = 2 };
std::ostream& operator<<(std::ostream& stream, const ResetReason& reason);

enum class ConfigurationOption : uint8_t {
  STARTUP_OPTION = 0x03,
  POLL_RATE = 0x24,
  QUEUED_POLL_RATE = 0x25,
  RESPONSE_POLL_RATE = 0x26,
  POLL_FAILURE_RETRIES = 0x29,
  INDIRECT_MSG_TIMEOUT = 0x2B,
  ROUTE_EXPIRY_TIME = 0x2C,
  EXTENDED_PAN_ID = 0x2D,
  BCAST_RETRIES = 0x2E,
  PASSIVE_ACK_TIMEOUT = 0x2F,
  BCAST_DELIVERY_TIME = 0x30,
  APS_FRAME_RETRIES = 0x43,
  APS_ACK_WAIT_DURATION = 0x44,
  BINDING_TIME = 0x46,
  PRECFGKEY = 0x62,
  PRECFGKEYS_ENABLE = 0x63,
  SECURITY_MODE = 0x64,
  USERDESC = 0x81,
  PANID = 0x83,
  CHANLIST = 0x84,
  LOGICAL_TYPE = 0x87,
  ZDO_DIRECT_CB = 0x8F
};

template <ConfigurationOption O>
struct ConfigurationOptionInfo;

enum class StartupOption : uint8_t { ClearConfig = 1, ClearState = 2 };
inline StartupOption operator|(StartupOption a, StartupOption b) {
  return (StartupOption)(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}
template <>
struct ConfigurationOptionInfo<ConfigurationOption::STARTUP_OPTION> {
  typedef StartupOption Type;
};

template <>
struct ConfigurationOptionInfo<ConfigurationOption::EXTENDED_PAN_ID> {
  typedef uint64_t Type;
};

template <>
struct ConfigurationOptionInfo<ConfigurationOption::PRECFGKEY> {
  typedef std::array<uint8_t, 16> Type;
};
template <>
struct ConfigurationOptionInfo<ConfigurationOption::PRECFGKEYS_ENABLE> {
  typedef bool Type;
};
template <>
struct ConfigurationOptionInfo<ConfigurationOption::PANID> {
  typedef uint16_t Type;
};

template <>
struct ConfigurationOptionInfo<ConfigurationOption::CHANLIST> {
  typedef uint32_t Type;
};

enum class LogicalType : uint8_t { Coordinator = 0, Router = 1, EndDevice = 2 };
template <>
struct ConfigurationOptionInfo<ConfigurationOption::LOGICAL_TYPE> {
  typedef LogicalType Type;
};

template <>
struct ConfigurationOptionInfo<ConfigurationOption::ZDO_DIRECT_CB> {
  typedef bool Type;
};

enum class DeviceInfo : uint8_t {
  DeviceState = 0,
  DeviceIEEEAddress = 1,
  DeviceShortAddress = 2,
  ParentDeviceShortAddress = 3,
  ParentDeviceIEEEAddress = 4,
  Channel = 5,
  PanId = 6,
  ExtendedPanId = 7
};

template <DeviceInfo I>
struct DeviceInfoInfo;
enum DeviceState : uint8_t {
  HOLD = 0,
  INIT = 1,
  NWK_DISC = 2,
  NWK_JOINING = 3,
  NWK_REJOIN = 4,
  END_DEVICE_UNAUTH = 5,
  END_DEVICE = 6,
  ROUTER = 7,
  COORD_STARTING = 8,
  ZB_COORD = 9,
  NWK_ORPHAN = 10
};
template <>
struct DeviceInfoInfo<DeviceInfo::DeviceState> {
  typedef DeviceState Type;
};

template <>
struct DeviceInfoInfo<DeviceInfo::DeviceIEEEAddress> {
  typedef IEEEAddress Type;
};

template <>
struct DeviceInfoInfo<DeviceInfo::DeviceShortAddress> {
  typedef ShortAddress Type;
};
template <>
struct DeviceInfoInfo<DeviceInfo::ParentDeviceShortAddress> {
  typedef ShortAddress Type;
};
template <>
struct DeviceInfoInfo<DeviceInfo::ParentDeviceIEEEAddress> {
  typedef IEEEAddress Type;
};
template <>
struct DeviceInfoInfo<DeviceInfo::Channel> {
  /* TODO! */
};

template <>
struct DeviceInfoInfo<DeviceInfo::PanId> {
  typedef uint16_t Type;
};
template <>
struct DeviceInfoInfo<DeviceInfo::ExtendedPanId> {
  typedef uint64_t Type;
};

struct VersionInfo {
  uint8_t TransportRev;
  uint8_t Product;
  uint8_t MajorRel;
  uint8_t MinorRel;
  uint8_t MaintRel;
};

enum StartupFromAppResponse : uint8_t { Restored = 0, New = 1, Leave = 2 };
}  // namespace znp

BOOST_FUSION_DEFINE_STRUCT((znp), ResetInfo,
                           (znp::ResetReason,
                            reason)(uint8_t, TransportRev)(uint8_t, ProductId)(
                               uint8_t, MajorRel)(uint8_t, MinorRel)(uint8_t,
                                                                     HwRev))
namespace znp {
std::ostream& operator<<(std::ostream& stream, const ResetInfo& info);
}  // namespace znp
#endif  //_ZNP_H_
