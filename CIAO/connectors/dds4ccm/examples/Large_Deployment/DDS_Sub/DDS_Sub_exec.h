// -*- C++ -*-
/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.7
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.dre.vanderbilt.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:1216

#ifndef CIAO_DDS_SUB_EXEC_NW9STU_H_
#define CIAO_DDS_SUB_EXEC_NW9STU_H_

#include /**/ "ace/pre.h"

#include "DDS_SubEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "DDS_Sub_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_DDS_Sub_Impl
{
  // TAO_IDL - Generated from
  // be/be_visitor_component/facet_exh.cpp:53

  class DDS_SUB_EXEC_Export Listener_exec_i
    : public virtual ::LargeTypeConn::CCM_Listener,
      public virtual ::CORBA::LocalObject
  {
  public:
    Listener_exec_i (void);
    virtual ~Listener_exec_i (void);

    // Operations and attributes from LargeTypeConn::Listener

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:37

    virtual void
    on_one_data (
      const ::LargeType & datum,
      const ::CCM_DDS::ReadInfo & info) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:37

    virtual void
    on_many_data (
      const ::LargeTypeSeq & data,
      const ::CCM_DDS::ReadInfoSeq & infos) = 0;
  };

  // TAO_IDL - Generated from
  // be/be_visitor_component/facet_exh.cpp:53

  class DDS_SUB_EXEC_Export PortStatusListener_exec_i
    : public virtual ::CCM_DDS::CCM_PortStatusListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    PortStatusListener_exec_i (void);
    virtual ~PortStatusListener_exec_i (void);

    // Operations and attributes from CCM_DDS::PortStatusListener

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:37

    virtual void
    on_requested_deadline_missed (
      ::DDS::DataReader_ptr the_reader,
      const ::DDS::RequestedDeadlineMissedStatus & status) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:37

    virtual void
    on_sample_lost (
      ::DDS::DataReader_ptr the_reader,
      const ::DDS::SampleLostStatus & status) = 0;
  };

  class DDS_SUB_EXEC_Export DDS_Sub_exec_i
    : public virtual DDS_Sub_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    DDS_Sub_exec_i (void);
    virtual ~DDS_Sub_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */


    virtual ::LargeTypeConn::CCM_Listener_ptr
    get_info_in_data_listener (void);

    virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_info_in_status (void);

    virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_ingo_get_status (void);
    //@}

    //@{
    /** Operations from Components::SessionComponent. */

    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}


  private:
    ::CCM_DDS_Sub_Context_var context_;
  };

  extern "C" DDS_SUB_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_DDS_Sub_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */

