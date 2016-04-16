// -*- C++ -*-
/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.0.0
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
#ifndef CIAO_QUOTER_CLIENT_EXEC_RCQDNE_H_
#define CIAO_QUOTER_CLIENT_EXEC_RCQDNE_H_

#include /**/ "ace/pre.h"

#include "Quoter_ClientEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Quoter_Client_exec_export.h"
#include "tao/LocalObject.h"
#include "ace/Task.h"

namespace CIAO_Quoter_Client_Impl
{

  /// Worker thread for asynchronous invocations
  class asynch_quoter_generator : public virtual ACE_Task_Base
  {
  public:
    asynch_quoter_generator (::Quoter::CCM_Client_Context_ptr context);

    virtual int svc (void);

  private:
    ::Quoter::CCM_Client_Context_var context_;
  };

  /**
   * Component Executor Implementation Class: Client_exec_i
   */

  class Client_exec_i
    : public virtual Client_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Client_exec_i (void);
    virtual ~Client_exec_i (void);

    /** @name Supported operations and attributes. */
    //@{

    //@}

    /** @name Component attributes and port operations. */
    //@{
    //@}

    /** @name Operations from Components::SessionComponent. */
    //@{
    virtual void set_session_context (::Components::SessionContext_ptr ctx);
    virtual void configuration_complete (void);
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    /** @name User defined public operations. */
    //@{

    //@}

  private:
    /** @name Component attributes. */
    //@{
    //@}

    /** @name User defined members. */
    //@{
    ::Quoter::CCM_Client_Context_var context_;
    asynch_quoter_generator* asynch_quoter_gen_;
    //@}

    /** @name User defined private operations. */
    //@{

    //@}
  };

  class AMI4CCM_StockManagerReplyHandler_my_quoter_i
    : public ::Quoter::CCM_AMI4CCM_StockManagerReplyHandler,
      public virtual ::CORBA::LocalObject
    {
    public:
      AMI4CCM_StockManagerReplyHandler_my_quoter_i (void);
      virtual ~AMI4CCM_StockManagerReplyHandler_my_quoter_i (void);

      virtual void
      get_stock_exchange_name (
        const char * stock_exchange_name);

      virtual void
      get_stock_exchange_name_excep (
        ::CCM_AMI::ExceptionHolder_ptr excep_holder);

      virtual void
      set_stock_exchange_name (void);

      virtual void
      set_stock_exchange_name_excep (
        ::CCM_AMI::ExceptionHolder_ptr excep_holder);

      virtual void
      add_stock (
        ::CORBA::Boolean ami_return_val);

      virtual void
      add_stock_excep (
        ::CCM_AMI::ExceptionHolder_ptr excep_holder);

      virtual void
      edit_stock (void);

      virtual void
      edit_stock_excep (
        ::CCM_AMI::ExceptionHolder_ptr excep_holder);

      virtual void
      remove_stock (
        ::CORBA::Double quote);

      virtual void
      remove_stock_excep (
        ::CCM_AMI::ExceptionHolder_ptr excep_holder);

      virtual void
      find_closest_symbol (
        ::CORBA::Boolean ami_return_val,
        const char * symbol);

      virtual void
      find_closest_symbol_excep (
        ::CCM_AMI::ExceptionHolder_ptr excep_holder);

      virtual void
      get_quote (
        ::CORBA::Double ami_return_val);

      virtual void
      get_quote_excep (
        ::CCM_AMI::ExceptionHolder_ptr excep_holder);
    };

    extern "C" QUOTER_CLIENT_EXEC_Export ::Components::EnterpriseComponent_ptr
    create_Quoter_Client_Impl (void);
  }

#include /**/ "ace/post.h"

#endif /* ifndef */
