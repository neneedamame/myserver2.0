// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mypb.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_mypb_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_mypb_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021011 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_mypb_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_mypb_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_mypb_2eproto;
namespace mypb {
class dataBody_getdata;
struct dataBody_getdataDefaultTypeInternal;
extern dataBody_getdataDefaultTypeInternal _dataBody_getdata_default_instance_;
class dataBody_login;
struct dataBody_loginDefaultTypeInternal;
extern dataBody_loginDefaultTypeInternal _dataBody_login_default_instance_;
class dataHeader;
struct dataHeaderDefaultTypeInternal;
extern dataHeaderDefaultTypeInternal _dataHeader_default_instance_;
}  // namespace mypb
PROTOBUF_NAMESPACE_OPEN
template<> ::mypb::dataBody_getdata* Arena::CreateMaybeMessage<::mypb::dataBody_getdata>(Arena*);
template<> ::mypb::dataBody_login* Arena::CreateMaybeMessage<::mypb::dataBody_login>(Arena*);
template<> ::mypb::dataHeader* Arena::CreateMaybeMessage<::mypb::dataHeader>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace mypb {

enum RequestType : int {
  REQUEST_TYPE_LOGIN = 0,
  REQUEST_TYPE_GETDATA = 1,
  RequestType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  RequestType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool RequestType_IsValid(int value);
constexpr RequestType RequestType_MIN = REQUEST_TYPE_LOGIN;
constexpr RequestType RequestType_MAX = REQUEST_TYPE_GETDATA;
constexpr int RequestType_ARRAYSIZE = RequestType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* RequestType_descriptor();
template<typename T>
inline const std::string& RequestType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, RequestType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function RequestType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    RequestType_descriptor(), enum_t_value);
}
inline bool RequestType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, RequestType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<RequestType>(
    RequestType_descriptor(), name, value);
}
// ===================================================================

class dataHeader final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mypb.dataHeader) */ {
 public:
  inline dataHeader() : dataHeader(nullptr) {}
  ~dataHeader() override;
  explicit PROTOBUF_CONSTEXPR dataHeader(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  dataHeader(const dataHeader& from);
  dataHeader(dataHeader&& from) noexcept
    : dataHeader() {
    *this = ::std::move(from);
  }

  inline dataHeader& operator=(const dataHeader& from) {
    CopyFrom(from);
    return *this;
  }
  inline dataHeader& operator=(dataHeader&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const dataHeader& default_instance() {
    return *internal_default_instance();
  }
  static inline const dataHeader* internal_default_instance() {
    return reinterpret_cast<const dataHeader*>(
               &_dataHeader_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(dataHeader& a, dataHeader& b) {
    a.Swap(&b);
  }
  inline void Swap(dataHeader* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(dataHeader* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  dataHeader* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<dataHeader>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const dataHeader& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const dataHeader& from) {
    dataHeader::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(dataHeader* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mypb.dataHeader";
  }
  protected:
  explicit dataHeader(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRequestFieldNumber = 1,
    kBodysizeFieldNumber = 2,
  };
  // .mypb.RequestType request = 1;
  void clear_request();
  ::mypb::RequestType request() const;
  void set_request(::mypb::RequestType value);
  private:
  ::mypb::RequestType _internal_request() const;
  void _internal_set_request(::mypb::RequestType value);
  public:

  // int32 bodysize = 2;
  void clear_bodysize();
  int32_t bodysize() const;
  void set_bodysize(int32_t value);
  private:
  int32_t _internal_bodysize() const;
  void _internal_set_bodysize(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:mypb.dataHeader)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    int request_;
    int32_t bodysize_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_mypb_2eproto;
};
// -------------------------------------------------------------------

class dataBody_login final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mypb.dataBody_login) */ {
 public:
  inline dataBody_login() : dataBody_login(nullptr) {}
  ~dataBody_login() override;
  explicit PROTOBUF_CONSTEXPR dataBody_login(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  dataBody_login(const dataBody_login& from);
  dataBody_login(dataBody_login&& from) noexcept
    : dataBody_login() {
    *this = ::std::move(from);
  }

  inline dataBody_login& operator=(const dataBody_login& from) {
    CopyFrom(from);
    return *this;
  }
  inline dataBody_login& operator=(dataBody_login&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const dataBody_login& default_instance() {
    return *internal_default_instance();
  }
  static inline const dataBody_login* internal_default_instance() {
    return reinterpret_cast<const dataBody_login*>(
               &_dataBody_login_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(dataBody_login& a, dataBody_login& b) {
    a.Swap(&b);
  }
  inline void Swap(dataBody_login* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(dataBody_login* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  dataBody_login* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<dataBody_login>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const dataBody_login& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const dataBody_login& from) {
    dataBody_login::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(dataBody_login* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mypb.dataBody_login";
  }
  protected:
  explicit dataBody_login(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUserFieldNumber = 1,
    kPasswordFieldNumber = 2,
  };
  // string user = 1;
  void clear_user();
  const std::string& user() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_user(ArgT0&& arg0, ArgT... args);
  std::string* mutable_user();
  PROTOBUF_NODISCARD std::string* release_user();
  void set_allocated_user(std::string* user);
  private:
  const std::string& _internal_user() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_user(const std::string& value);
  std::string* _internal_mutable_user();
  public:

  // string password = 2;
  void clear_password();
  const std::string& password() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_password(ArgT0&& arg0, ArgT... args);
  std::string* mutable_password();
  PROTOBUF_NODISCARD std::string* release_password();
  void set_allocated_password(std::string* password);
  private:
  const std::string& _internal_password() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_password(const std::string& value);
  std::string* _internal_mutable_password();
  public:

  // @@protoc_insertion_point(class_scope:mypb.dataBody_login)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr user_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr password_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_mypb_2eproto;
};
// -------------------------------------------------------------------

class dataBody_getdata final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mypb.dataBody_getdata) */ {
 public:
  inline dataBody_getdata() : dataBody_getdata(nullptr) {}
  ~dataBody_getdata() override;
  explicit PROTOBUF_CONSTEXPR dataBody_getdata(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  dataBody_getdata(const dataBody_getdata& from);
  dataBody_getdata(dataBody_getdata&& from) noexcept
    : dataBody_getdata() {
    *this = ::std::move(from);
  }

  inline dataBody_getdata& operator=(const dataBody_getdata& from) {
    CopyFrom(from);
    return *this;
  }
  inline dataBody_getdata& operator=(dataBody_getdata&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const dataBody_getdata& default_instance() {
    return *internal_default_instance();
  }
  static inline const dataBody_getdata* internal_default_instance() {
    return reinterpret_cast<const dataBody_getdata*>(
               &_dataBody_getdata_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(dataBody_getdata& a, dataBody_getdata& b) {
    a.Swap(&b);
  }
  inline void Swap(dataBody_getdata* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(dataBody_getdata* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  dataBody_getdata* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<dataBody_getdata>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const dataBody_getdata& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const dataBody_getdata& from) {
    dataBody_getdata::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(dataBody_getdata* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mypb.dataBody_getdata";
  }
  protected:
  explicit dataBody_getdata(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kKeyFieldNumber = 1,
  };
  // string key = 1;
  void clear_key();
  const std::string& key() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_key(ArgT0&& arg0, ArgT... args);
  std::string* mutable_key();
  PROTOBUF_NODISCARD std::string* release_key();
  void set_allocated_key(std::string* key);
  private:
  const std::string& _internal_key() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_key(const std::string& value);
  std::string* _internal_mutable_key();
  public:

  // @@protoc_insertion_point(class_scope:mypb.dataBody_getdata)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr key_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_mypb_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// dataHeader

// .mypb.RequestType request = 1;
inline void dataHeader::clear_request() {
  _impl_.request_ = 0;
}
inline ::mypb::RequestType dataHeader::_internal_request() const {
  return static_cast< ::mypb::RequestType >(_impl_.request_);
}
inline ::mypb::RequestType dataHeader::request() const {
  // @@protoc_insertion_point(field_get:mypb.dataHeader.request)
  return _internal_request();
}
inline void dataHeader::_internal_set_request(::mypb::RequestType value) {
  
  _impl_.request_ = value;
}
inline void dataHeader::set_request(::mypb::RequestType value) {
  _internal_set_request(value);
  // @@protoc_insertion_point(field_set:mypb.dataHeader.request)
}

// int32 bodysize = 2;
inline void dataHeader::clear_bodysize() {
  _impl_.bodysize_ = 0;
}
inline int32_t dataHeader::_internal_bodysize() const {
  return _impl_.bodysize_;
}
inline int32_t dataHeader::bodysize() const {
  // @@protoc_insertion_point(field_get:mypb.dataHeader.bodysize)
  return _internal_bodysize();
}
inline void dataHeader::_internal_set_bodysize(int32_t value) {
  
  _impl_.bodysize_ = value;
}
inline void dataHeader::set_bodysize(int32_t value) {
  _internal_set_bodysize(value);
  // @@protoc_insertion_point(field_set:mypb.dataHeader.bodysize)
}

// -------------------------------------------------------------------

// dataBody_login

// string user = 1;
inline void dataBody_login::clear_user() {
  _impl_.user_.ClearToEmpty();
}
inline const std::string& dataBody_login::user() const {
  // @@protoc_insertion_point(field_get:mypb.dataBody_login.user)
  return _internal_user();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void dataBody_login::set_user(ArgT0&& arg0, ArgT... args) {
 
 _impl_.user_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:mypb.dataBody_login.user)
}
inline std::string* dataBody_login::mutable_user() {
  std::string* _s = _internal_mutable_user();
  // @@protoc_insertion_point(field_mutable:mypb.dataBody_login.user)
  return _s;
}
inline const std::string& dataBody_login::_internal_user() const {
  return _impl_.user_.Get();
}
inline void dataBody_login::_internal_set_user(const std::string& value) {
  
  _impl_.user_.Set(value, GetArenaForAllocation());
}
inline std::string* dataBody_login::_internal_mutable_user() {
  
  return _impl_.user_.Mutable(GetArenaForAllocation());
}
inline std::string* dataBody_login::release_user() {
  // @@protoc_insertion_point(field_release:mypb.dataBody_login.user)
  return _impl_.user_.Release();
}
inline void dataBody_login::set_allocated_user(std::string* user) {
  if (user != nullptr) {
    
  } else {
    
  }
  _impl_.user_.SetAllocated(user, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.user_.IsDefault()) {
    _impl_.user_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:mypb.dataBody_login.user)
}

// string password = 2;
inline void dataBody_login::clear_password() {
  _impl_.password_.ClearToEmpty();
}
inline const std::string& dataBody_login::password() const {
  // @@protoc_insertion_point(field_get:mypb.dataBody_login.password)
  return _internal_password();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void dataBody_login::set_password(ArgT0&& arg0, ArgT... args) {
 
 _impl_.password_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:mypb.dataBody_login.password)
}
inline std::string* dataBody_login::mutable_password() {
  std::string* _s = _internal_mutable_password();
  // @@protoc_insertion_point(field_mutable:mypb.dataBody_login.password)
  return _s;
}
inline const std::string& dataBody_login::_internal_password() const {
  return _impl_.password_.Get();
}
inline void dataBody_login::_internal_set_password(const std::string& value) {
  
  _impl_.password_.Set(value, GetArenaForAllocation());
}
inline std::string* dataBody_login::_internal_mutable_password() {
  
  return _impl_.password_.Mutable(GetArenaForAllocation());
}
inline std::string* dataBody_login::release_password() {
  // @@protoc_insertion_point(field_release:mypb.dataBody_login.password)
  return _impl_.password_.Release();
}
inline void dataBody_login::set_allocated_password(std::string* password) {
  if (password != nullptr) {
    
  } else {
    
  }
  _impl_.password_.SetAllocated(password, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.password_.IsDefault()) {
    _impl_.password_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:mypb.dataBody_login.password)
}

// -------------------------------------------------------------------

// dataBody_getdata

// string key = 1;
inline void dataBody_getdata::clear_key() {
  _impl_.key_.ClearToEmpty();
}
inline const std::string& dataBody_getdata::key() const {
  // @@protoc_insertion_point(field_get:mypb.dataBody_getdata.key)
  return _internal_key();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void dataBody_getdata::set_key(ArgT0&& arg0, ArgT... args) {
 
 _impl_.key_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:mypb.dataBody_getdata.key)
}
inline std::string* dataBody_getdata::mutable_key() {
  std::string* _s = _internal_mutable_key();
  // @@protoc_insertion_point(field_mutable:mypb.dataBody_getdata.key)
  return _s;
}
inline const std::string& dataBody_getdata::_internal_key() const {
  return _impl_.key_.Get();
}
inline void dataBody_getdata::_internal_set_key(const std::string& value) {
  
  _impl_.key_.Set(value, GetArenaForAllocation());
}
inline std::string* dataBody_getdata::_internal_mutable_key() {
  
  return _impl_.key_.Mutable(GetArenaForAllocation());
}
inline std::string* dataBody_getdata::release_key() {
  // @@protoc_insertion_point(field_release:mypb.dataBody_getdata.key)
  return _impl_.key_.Release();
}
inline void dataBody_getdata::set_allocated_key(std::string* key) {
  if (key != nullptr) {
    
  } else {
    
  }
  _impl_.key_.SetAllocated(key, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.key_.IsDefault()) {
    _impl_.key_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:mypb.dataBody_getdata.key)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace mypb

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::mypb::RequestType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::mypb::RequestType>() {
  return ::mypb::RequestType_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_mypb_2eproto
