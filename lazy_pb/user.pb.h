// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: user.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_user_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_user_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3014000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3014000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_user_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_user_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[4]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_user_2eproto;
::PROTOBUF_NAMESPACE_ID::Metadata descriptor_table_user_2eproto_metadata_getter(int index);
class Factory;
struct FactoryDefaultTypeInternal;
extern FactoryDefaultTypeInternal _Factory_default_instance_;
class FactoryList;
struct FactoryListDefaultTypeInternal;
extern FactoryListDefaultTypeInternal _FactoryList_default_instance_;
class Role;
struct RoleDefaultTypeInternal;
extern RoleDefaultTypeInternal _Role_default_instance_;
class RoleBasic;
struct RoleBasicDefaultTypeInternal;
extern RoleBasicDefaultTypeInternal _RoleBasic_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::Factory* Arena::CreateMaybeMessage<::Factory>(Arena*);
template<> ::FactoryList* Arena::CreateMaybeMessage<::FactoryList>(Arena*);
template<> ::Role* Arena::CreateMaybeMessage<::Role>(Arena*);
template<> ::RoleBasic* Arena::CreateMaybeMessage<::RoleBasic>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class RoleBasic PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:RoleBasic) */ {
 public:
  inline RoleBasic() : RoleBasic(nullptr) {}
  virtual ~RoleBasic();
  explicit constexpr RoleBasic(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  RoleBasic(const RoleBasic& from);
  RoleBasic(RoleBasic&& from) noexcept
    : RoleBasic() {
    *this = ::std::move(from);
  }

  inline RoleBasic& operator=(const RoleBasic& from) {
    CopyFrom(from);
    return *this;
  }
  inline RoleBasic& operator=(RoleBasic&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const RoleBasic& default_instance() {
    return *internal_default_instance();
  }
  static inline const RoleBasic* internal_default_instance() {
    return reinterpret_cast<const RoleBasic*>(
               &_RoleBasic_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(RoleBasic& a, RoleBasic& b) {
    a.Swap(&b);
  }
  inline void Swap(RoleBasic* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(RoleBasic* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline RoleBasic* New() const final {
    return CreateMaybeMessage<RoleBasic>(nullptr);
  }

  RoleBasic* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<RoleBasic>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const RoleBasic& from);
  void MergeFrom(const RoleBasic& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RoleBasic* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "RoleBasic";
  }
  protected:
  explicit RoleBasic(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_user_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kGoldFieldNumber = 1,
  };
  // optional int32 gold = 1;
  bool has_gold() const;
  private:
  bool _internal_has_gold() const;
  public:
  void clear_gold();
  ::PROTOBUF_NAMESPACE_ID::int32 gold() const;
  void set_gold(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_gold() const;
  void _internal_set_gold(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:RoleBasic)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::int32 gold_;
  friend struct ::TableStruct_user_2eproto;
};
// -------------------------------------------------------------------

class Factory PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Factory) */ {
 public:
  inline Factory() : Factory(nullptr) {}
  virtual ~Factory();
  explicit constexpr Factory(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Factory(const Factory& from);
  Factory(Factory&& from) noexcept
    : Factory() {
    *this = ::std::move(from);
  }

  inline Factory& operator=(const Factory& from) {
    CopyFrom(from);
    return *this;
  }
  inline Factory& operator=(Factory&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Factory& default_instance() {
    return *internal_default_instance();
  }
  static inline const Factory* internal_default_instance() {
    return reinterpret_cast<const Factory*>(
               &_Factory_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Factory& a, Factory& b) {
    a.Swap(&b);
  }
  inline void Swap(Factory* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Factory* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Factory* New() const final {
    return CreateMaybeMessage<Factory>(nullptr);
  }

  Factory* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Factory>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Factory& from);
  void MergeFrom(const Factory& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Factory* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Factory";
  }
  protected:
  explicit Factory(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_user_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIdFieldNumber = 1,
    kCdFieldNumber = 2,
  };
  // optional int32 id = 1;
  bool has_id() const;
  private:
  bool _internal_has_id() const;
  public:
  void clear_id();
  ::PROTOBUF_NAMESPACE_ID::int32 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_id() const;
  void _internal_set_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // optional uint32 cd = 2;
  bool has_cd() const;
  private:
  bool _internal_has_cd() const;
  public:
  void clear_cd();
  ::PROTOBUF_NAMESPACE_ID::uint32 cd() const;
  void set_cd(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_cd() const;
  void _internal_set_cd(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:Factory)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::int32 id_;
  ::PROTOBUF_NAMESPACE_ID::uint32 cd_;
  friend struct ::TableStruct_user_2eproto;
};
// -------------------------------------------------------------------

class FactoryList PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:FactoryList) */ {
 public:
  inline FactoryList() : FactoryList(nullptr) {}
  virtual ~FactoryList();
  explicit constexpr FactoryList(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  FactoryList(const FactoryList& from);
  FactoryList(FactoryList&& from) noexcept
    : FactoryList() {
    *this = ::std::move(from);
  }

  inline FactoryList& operator=(const FactoryList& from) {
    CopyFrom(from);
    return *this;
  }
  inline FactoryList& operator=(FactoryList&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const FactoryList& default_instance() {
    return *internal_default_instance();
  }
  static inline const FactoryList* internal_default_instance() {
    return reinterpret_cast<const FactoryList*>(
               &_FactoryList_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(FactoryList& a, FactoryList& b) {
    a.Swap(&b);
  }
  inline void Swap(FactoryList* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(FactoryList* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline FactoryList* New() const final {
    return CreateMaybeMessage<FactoryList>(nullptr);
  }

  FactoryList* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<FactoryList>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const FactoryList& from);
  void MergeFrom(const FactoryList& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FactoryList* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "FactoryList";
  }
  protected:
  explicit FactoryList(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_user_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFactoryListFieldNumber = 1,
  };
  // repeated .Factory factory_list = 1;
  int factory_list_size() const;
  private:
  int _internal_factory_list_size() const;
  public:
  void clear_factory_list();
  ::Factory* mutable_factory_list(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Factory >*
      mutable_factory_list();
  private:
  const ::Factory& _internal_factory_list(int index) const;
  ::Factory* _internal_add_factory_list();
  public:
  const ::Factory& factory_list(int index) const;
  ::Factory* add_factory_list();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Factory >&
      factory_list() const;

  // @@protoc_insertion_point(class_scope:FactoryList)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Factory > factory_list_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_user_2eproto;
};
// -------------------------------------------------------------------

class Role PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Role) */ {
 public:
  inline Role() : Role(nullptr) {}
  virtual ~Role();
  explicit constexpr Role(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Role(const Role& from);
  Role(Role&& from) noexcept
    : Role() {
    *this = ::std::move(from);
  }

  inline Role& operator=(const Role& from) {
    CopyFrom(from);
    return *this;
  }
  inline Role& operator=(Role&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Role& default_instance() {
    return *internal_default_instance();
  }
  static inline const Role* internal_default_instance() {
    return reinterpret_cast<const Role*>(
               &_Role_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  friend void swap(Role& a, Role& b) {
    a.Swap(&b);
  }
  inline void Swap(Role* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Role* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Role* New() const final {
    return CreateMaybeMessage<Role>(nullptr);
  }

  Role* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Role>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Role& from);
  void MergeFrom(const Role& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Role* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Role";
  }
  protected:
  explicit Role(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_user_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRoleBasicFieldNumber = 1,
    kFactoryListFieldNumber = 2,
  };
  // optional .RoleBasic role_basic = 1;
  bool has_role_basic() const;
  private:
  bool _internal_has_role_basic() const;
  public:
  void clear_role_basic();
  const ::RoleBasic& role_basic() const;
  ::RoleBasic* release_role_basic();
  ::RoleBasic* mutable_role_basic();
  void set_allocated_role_basic(::RoleBasic* role_basic);
  private:
  const ::RoleBasic& _internal_role_basic() const;
  ::RoleBasic* _internal_mutable_role_basic();
  public:
  void unsafe_arena_set_allocated_role_basic(
      ::RoleBasic* role_basic);
  ::RoleBasic* unsafe_arena_release_role_basic();

  // optional .FactoryList factory_list = 2 [lazy = true];
  bool has_factory_list() const;
  private:
  bool _internal_has_factory_list() const;
  public:
  void clear_factory_list();
  const ::FactoryList& factory_list() const;
  ::FactoryList* release_factory_list();
  ::FactoryList* mutable_factory_list();
  void set_allocated_factory_list(::FactoryList* factory_list);
  private:
  const ::FactoryList& _internal_factory_list() const;
  ::FactoryList* _internal_mutable_factory_list();
  public:
  void unsafe_arena_set_allocated_factory_list(
      ::FactoryList* factory_list);
  ::FactoryList* unsafe_arena_release_factory_list();

  // @@protoc_insertion_point(class_scope:Role)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::RoleBasic* role_basic_;
  ::PROTOBUF_NAMESPACE_ID::LazyMessage<::FactoryList> factory_list_;
  friend struct ::TableStruct_user_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RoleBasic

// optional int32 gold = 1;
inline bool RoleBasic::_internal_has_gold() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool RoleBasic::has_gold() const {
  return _internal_has_gold();
}
inline void RoleBasic::clear_gold() {
  gold_ = 0;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RoleBasic::_internal_gold() const {
  return gold_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RoleBasic::gold() const {
  // @@protoc_insertion_point(field_get:RoleBasic.gold)
  return _internal_gold();
}
inline void RoleBasic::_internal_set_gold(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000001u;
  gold_ = value;
}
inline void RoleBasic::set_gold(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_gold(value);
  // @@protoc_insertion_point(field_set:RoleBasic.gold)
}

// -------------------------------------------------------------------

// Factory

// optional int32 id = 1;
inline bool Factory::_internal_has_id() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Factory::has_id() const {
  return _internal_has_id();
}
inline void Factory::clear_id() {
  id_ = 0;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Factory::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Factory::id() const {
  // @@protoc_insertion_point(field_get:Factory.id)
  return _internal_id();
}
inline void Factory::_internal_set_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000001u;
  id_ = value;
}
inline void Factory::set_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:Factory.id)
}

// optional uint32 cd = 2;
inline bool Factory::_internal_has_cd() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool Factory::has_cd() const {
  return _internal_has_cd();
}
inline void Factory::clear_cd() {
  cd_ = 0u;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Factory::_internal_cd() const {
  return cd_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Factory::cd() const {
  // @@protoc_insertion_point(field_get:Factory.cd)
  return _internal_cd();
}
inline void Factory::_internal_set_cd(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000002u;
  cd_ = value;
}
inline void Factory::set_cd(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_cd(value);
  // @@protoc_insertion_point(field_set:Factory.cd)
}

// -------------------------------------------------------------------

// FactoryList

// repeated .Factory factory_list = 1;
inline int FactoryList::_internal_factory_list_size() const {
  return factory_list_.size();
}
inline int FactoryList::factory_list_size() const {
  return _internal_factory_list_size();
}
inline void FactoryList::clear_factory_list() {
  factory_list_.Clear();
}
inline ::Factory* FactoryList::mutable_factory_list(int index) {
  // @@protoc_insertion_point(field_mutable:FactoryList.factory_list)
  return factory_list_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Factory >*
FactoryList::mutable_factory_list() {
  // @@protoc_insertion_point(field_mutable_list:FactoryList.factory_list)
  return &factory_list_;
}
inline const ::Factory& FactoryList::_internal_factory_list(int index) const {
  return factory_list_.Get(index);
}
inline const ::Factory& FactoryList::factory_list(int index) const {
  // @@protoc_insertion_point(field_get:FactoryList.factory_list)
  return _internal_factory_list(index);
}
inline ::Factory* FactoryList::_internal_add_factory_list() {
  return factory_list_.Add();
}
inline ::Factory* FactoryList::add_factory_list() {
  // @@protoc_insertion_point(field_add:FactoryList.factory_list)
  return _internal_add_factory_list();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Factory >&
FactoryList::factory_list() const {
  // @@protoc_insertion_point(field_list:FactoryList.factory_list)
  return factory_list_;
}

// -------------------------------------------------------------------

// Role

// optional .RoleBasic role_basic = 1;
inline bool Role::_internal_has_role_basic() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || role_basic_ != nullptr);
  return value;
}
inline bool Role::has_role_basic() const {
  return _internal_has_role_basic();
}
inline void Role::clear_role_basic() {
  if (role_basic_ != nullptr) role_basic_->Clear();
  _has_bits_[0] &= ~0x00000001u;
}
inline const ::RoleBasic& Role::_internal_role_basic() const {
  const ::RoleBasic* p = role_basic_;
  return p != nullptr ? *p : reinterpret_cast<const ::RoleBasic&>(
      ::_RoleBasic_default_instance_);
}
inline const ::RoleBasic& Role::role_basic() const {
  // @@protoc_insertion_point(field_get:Role.role_basic)
  return _internal_role_basic();
}
inline void Role::unsafe_arena_set_allocated_role_basic(
    ::RoleBasic* role_basic) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(role_basic_);
  }
  role_basic_ = role_basic;
  if (role_basic) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Role.role_basic)
}
inline ::RoleBasic* Role::release_role_basic() {
  _has_bits_[0] &= ~0x00000001u;
  ::RoleBasic* temp = role_basic_;
  role_basic_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::RoleBasic* Role::unsafe_arena_release_role_basic() {
  // @@protoc_insertion_point(field_release:Role.role_basic)
  _has_bits_[0] &= ~0x00000001u;
  ::RoleBasic* temp = role_basic_;
  role_basic_ = nullptr;
  return temp;
}
inline ::RoleBasic* Role::_internal_mutable_role_basic() {
  _has_bits_[0] |= 0x00000001u;
  if (role_basic_ == nullptr) {
    auto* p = CreateMaybeMessage<::RoleBasic>(GetArena());
    role_basic_ = p;
  }
  return role_basic_;
}
inline ::RoleBasic* Role::mutable_role_basic() {
  // @@protoc_insertion_point(field_mutable:Role.role_basic)
  return _internal_mutable_role_basic();
}
inline void Role::set_allocated_role_basic(::RoleBasic* role_basic) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete role_basic_;
  }
  if (role_basic) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(role_basic);
    if (message_arena != submessage_arena) {
      role_basic = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, role_basic, submessage_arena);
    }
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  role_basic_ = role_basic;
  // @@protoc_insertion_point(field_set_allocated:Role.role_basic)
}

// optional .FactoryList factory_list = 2 [lazy = true];
inline bool Role::_internal_has_factory_list() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  PROTOBUF_ASSUME(!value || factory_list_ != nullptr);
  return value;
}
inline bool Role::has_factory_list() const {
  return _internal_has_factory_list();
}
inline void Role::clear_factory_list() {
  if (factory_list_ != nullptr) factory_list_.Clear();
  _has_bits_[0] &= ~0x00000002u;
}
inline const ::FactoryList& Role::_internal_factory_list() const {
  const ::FactoryList* p = factory_list_.GetLazyMessage(GetArena());
  return p != nullptr ? *p : reinterpret_cast<const ::FactoryList&>(
      ::_FactoryList_default_instance_);
}
inline const ::FactoryList& Role::factory_list() const {
  // @@protoc_insertion_point(field_get:Role.factory_list)
  return _internal_factory_list();
}
inline void Role::unsafe_arena_set_allocated_factory_list(
    ::FactoryList* factory_list) {
  if (GetArena() == nullptr) {
    factory_list_.Delete<true>();
  }
  factory_list_ = factory_list;
  if (factory_list) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Role.factory_list)
}
inline ::FactoryList* Role::release_factory_list() {
  _has_bits_[0] &= ~0x00000002u;
  ::FactoryList* temp = factory_list_.GetLazyMessage(GetArena());
  factory_list_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::FactoryList* Role::unsafe_arena_release_factory_list() {
  // @@protoc_insertion_point(field_release:Role.factory_list)
  _has_bits_[0] &= ~0x00000002u;
  ::FactoryList* temp = factory_list_.GetLazyMessage(GetArena());
  factory_list_ = nullptr;
  return temp;
}
inline ::FactoryList* Role::_internal_mutable_factory_list() {
  _has_bits_[0] |= 0x00000002u;
  if (factory_list_ == nullptr) {
    auto* p = CreateMaybeMessage<::FactoryList>(GetArena());
    factory_list_ = p;
  }
  return factory_list_.GetLazyMessage(GetArena());
}
inline ::FactoryList* Role::mutable_factory_list() {
  // @@protoc_insertion_point(field_mutable:Role.factory_list)
  return _internal_mutable_factory_list();
}
inline void Role::set_allocated_factory_list(::FactoryList* factory_list) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    factory_list_.Delete<false>();
  }
  if (factory_list) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(factory_list);
    if (message_arena != submessage_arena) {
      factory_list = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, factory_list, submessage_arena);
    }
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  factory_list_ = factory_list;
  // @@protoc_insertion_point(field_set_allocated:Role.factory_list)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_user_2eproto
