// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:151

#ifndef _TAO_IDL_ORIG_MESSAGING_RT_POLICYC_H_
#define _TAO_IDL_ORIG_MESSAGING_RT_POLICYC_H_

#include "ace/pre.h"
#include "tao/PolicyC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "messaging_export.h"
#include "tao/TimeBaseC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Messaging_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Messaging_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:48

TAO_NAMESPACE  Messaging
{
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typedef/typedef_ch.cpp:333
  
  typedef TimeBase::TimeT Timeout;
  typedef TimeBase::TimeT_out Timeout_out;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_Timeout;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::PolicyType RELATIVE_RT_TIMEOUT_POLICY_TYPE = 32U;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:567

#if !defined (_MESSAGING_RELATIVEROUNDTRIPTIMEOUTPOLICY__ODDS_N_ENDS_CH_)
#define _MESSAGING_RELATIVEROUNDTRIPTIMEOUTPOLICY__ODDS_N_ENDS_CH_
  
  class RelativeRoundtripTimeoutPolicy;
  typedef RelativeRoundtripTimeoutPolicy *RelativeRoundtripTimeoutPolicy_ptr;
  struct tao_RelativeRoundtripTimeoutPolicy_life;
  
  typedef
    TAO_Objref_Var_T<
        RelativeRoundtripTimeoutPolicy,
        tao_RelativeRoundtripTimeoutPolicy_life
      >
    RelativeRoundtripTimeoutPolicy_var;
  
  typedef
    TAO_Objref_Out_T<
        RelativeRoundtripTimeoutPolicy,
        tao_RelativeRoundtripTimeoutPolicy_life
      >
    RelativeRoundtripTimeoutPolicy_out;
  
  struct TAO_Messaging_Export tao_RelativeRoundtripTimeoutPolicy_life
  {
    static RelativeRoundtripTimeoutPolicy_ptr tao_duplicate (RelativeRoundtripTimeoutPolicy_ptr);
    static void tao_release (RelativeRoundtripTimeoutPolicy_ptr);
    static RelativeRoundtripTimeoutPolicy_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        RelativeRoundtripTimeoutPolicy_ptr,
        TAO_OutputCDR &
      );
  };
  
  struct TAO_Messaging_Export tao_RelativeRoundtripTimeoutPolicy_cast
  {
    static RelativeRoundtripTimeoutPolicy_ptr tao_narrow (
        CORBA::Object_ptr
        ACE_ENV_ARG_DECL
      );
    static CORBA::Object_ptr tao_upcast (void *);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_MESSAGING_RELATIVEROUNDTRIPTIMEOUTPOLICY_CH_)
#define _MESSAGING_RELATIVEROUNDTRIPTIMEOUTPOLICY_CH_
  
  class TAO_Messaging_Export RelativeRoundtripTimeoutPolicy
    : public virtual CORBA::Policy
  {
  public:
    typedef RelativeRoundtripTimeoutPolicy_ptr _ptr_type;
    typedef RelativeRoundtripTimeoutPolicy_var _var_type;
    static int _tao_class_id;
    
    // The static operations.
    static RelativeRoundtripTimeoutPolicy_ptr _duplicate (RelativeRoundtripTimeoutPolicy_ptr obj);
    
    static RelativeRoundtripTimeoutPolicy_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static RelativeRoundtripTimeoutPolicy_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static RelativeRoundtripTimeoutPolicy_ptr _nil (void)
      {
        return (RelativeRoundtripTimeoutPolicy_ptr)0;
      }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual TimeBase::TimeT relative_expiry (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:211
    
    virtual void *_tao_QueryInterface (ptrdiff_t type);
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    RelativeRoundtripTimeoutPolicy (void);
    virtual ~RelativeRoundtripTimeoutPolicy (void);
  
  private:
    RelativeRoundtripTimeoutPolicy (const RelativeRoundtripTimeoutPolicy &);
    void operator= (const RelativeRoundtripTimeoutPolicy &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_RelativeRoundtripTimeoutPolicy;

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module Messaging

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_ch.cpp:52

TAO_Messaging_Export void operator<<= (CORBA::Any &, Messaging::RelativeRoundtripTimeoutPolicy_ptr); // copying
TAO_Messaging_Export void operator<<= (CORBA::Any &, Messaging::RelativeRoundtripTimeoutPolicy_ptr *); // non-copying
TAO_Messaging_Export CORBA::Boolean operator>>= (const CORBA::Any &, Messaging::RelativeRoundtripTimeoutPolicy_ptr &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:1018

#if defined (__ACE_INLINE__)
#include "Messaging_RT_PolicyC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include "ace/post.h"
#endif /* ifndef */

