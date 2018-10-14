/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: request.proto */

#ifndef PROTOBUF_C_request_2eproto__INCLUDED
#define PROTOBUF_C_request_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Request Request;
typedef struct _LoginRequest LoginRequest;
typedef struct _MoveRequest MoveRequest;


/* --- enums --- */

typedef enum _RequestType {
  REQUEST_TYPE__LOGIN = 0,
  REQUEST_TYPE__MOVE = 1
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(REQUEST_TYPE)
} RequestType;
typedef enum _CharacterClass {
  CHARACTER_CLASS__WARRIOR = 0,
  CHARACTER_CLASS__MAGE = 1,
  CHARACTER_CLASS__PRIEST = 2
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(CHARACTER_CLASS)
} CharacterClass;

/* --- messages --- */

struct  _Request
{
  ProtobufCMessage base;
  RequestType type;
  LoginRequest *login;
  MoveRequest *move;
};
#define REQUEST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&request__descriptor) \
    , REQUEST_TYPE__LOGIN, NULL, NULL }


struct  _LoginRequest
{
  ProtobufCMessage base;
  char *nickname;
  CharacterClass class_;
};
#define LOGIN_REQUEST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&login_request__descriptor) \
    , NULL, CHARACTER_CLASS__WARRIOR }


struct  _MoveRequest
{
  ProtobufCMessage base;
  int32_t id;
  int32_t key;
  int32_t pos_x;
  int32_t pos_y;
};
#define MOVE_REQUEST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&move_request__descriptor) \
    , 0, 0, 0, 0 }


/* Request methods */
void   request__init
                     (Request         *message);
size_t request__get_packed_size
                     (const Request   *message);
size_t request__pack
                     (const Request   *message,
                      uint8_t             *out);
size_t request__pack_to_buffer
                     (const Request   *message,
                      ProtobufCBuffer     *buffer);
Request *
       request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   request__free_unpacked
                     (Request *message,
                      ProtobufCAllocator *allocator);
/* LoginRequest methods */
void   login_request__init
                     (LoginRequest         *message);
size_t login_request__get_packed_size
                     (const LoginRequest   *message);
size_t login_request__pack
                     (const LoginRequest   *message,
                      uint8_t             *out);
size_t login_request__pack_to_buffer
                     (const LoginRequest   *message,
                      ProtobufCBuffer     *buffer);
LoginRequest *
       login_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   login_request__free_unpacked
                     (LoginRequest *message,
                      ProtobufCAllocator *allocator);
/* MoveRequest methods */
void   move_request__init
                     (MoveRequest         *message);
size_t move_request__get_packed_size
                     (const MoveRequest   *message);
size_t move_request__pack
                     (const MoveRequest   *message,
                      uint8_t             *out);
size_t move_request__pack_to_buffer
                     (const MoveRequest   *message,
                      ProtobufCBuffer     *buffer);
MoveRequest *
       move_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   move_request__free_unpacked
                     (MoveRequest *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Request_Closure)
                 (const Request *message,
                  void *closure_data);
typedef void (*LoginRequest_Closure)
                 (const LoginRequest *message,
                  void *closure_data);
typedef void (*MoveRequest_Closure)
                 (const MoveRequest *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    request_type__descriptor;
extern const ProtobufCEnumDescriptor    character_class__descriptor;
extern const ProtobufCMessageDescriptor request__descriptor;
extern const ProtobufCMessageDescriptor login_request__descriptor;
extern const ProtobufCMessageDescriptor move_request__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_request_2eproto__INCLUDED */
