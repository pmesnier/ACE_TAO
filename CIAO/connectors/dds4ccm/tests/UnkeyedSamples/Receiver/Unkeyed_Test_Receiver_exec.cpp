// -*- C++ -*-
/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.3
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

#include "Unkeyed_Test_Receiver_exec.h"
#include "dds4ccm/impl/dds4ccm_conf.h"

namespace CIAO_Unkeyed_Test_Receiver_Impl
{

  /**
   * Facet Executor Implementation Class: info_out_data_listener_exec_i
   */

  info_out_data_listener_exec_i::info_out_data_listener_exec_i (
        ::Unkeyed_Test::CCM_Receiver_Context_ptr ctx,
        Atomic_ULong &received)
    : ciao_context_ (
        ::Unkeyed_Test::CCM_Receiver_Context::_duplicate (ctx))
      , received_ (received)
      , handle_ (DDS::HANDLE_NIL)
  {
  }

  info_out_data_listener_exec_i::~info_out_data_listener_exec_i (void)
  {
  }

  // Operations from ::Unkeyed_Test::UnkeyedTestConnector::Listener

  void
  info_out_data_listener_exec_i::on_one_data (const ::UnkeyedTest & datum,
  const ::CCM_DDS::ReadInfo & info)
  {
    // From the first sample store the instance handle, the handle should be
    // nil (RTI DDS) or stay the same (OpenDDS)
    if (this->received_ == 0)
      {
        this->handle_ = info.instance_handle;
      }
    ++this->received_;

    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("UnkeyedTest_Listener: ")
            ACE_TEXT ("received keyed_test_info for <%C> at iteration <%u> for handle ")
            DDS_INSTANCE_HANDLE_FORMAT_SPECIFIER
            ACE_TEXT ("\n"),
            datum.key.in (),
            datum.iteration,
            DDS_INSTANCE_HANDLE_LOG (info.instance_handle)));
    if ((info.instance_handle != ::DDS::HANDLE_NIL) &&
        (this->handle_.value () != info.instance_handle))
      {
        ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("ERROR: UnkeyedTest_Listener::on_one_data: ")
                ACE_TEXT ("received instance handle ")
                DDS_INSTANCE_HANDLE_FORMAT_SPECIFIER
                ACE_TEXT (" should be nil or stay the same ")
                ACE_TEXT ("for unkeyed data ")
                ACE_TEXT ("key <%C> - iteration <%u>\n"),
                DDS_INSTANCE_HANDLE_LOG (info.instance_handle),
                datum.key.in (),
                datum.iteration));
      }
    if (info.source_timestamp.sec == 0 &&
        info.source_timestamp.nanosec == 0)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: UnkeyedTest_Listener::on_one_data: "
                            "source timestamp seems to be invalid (nil) "
                            "key <%C> - iteration <%d>\n",
                            datum.key.in (),
                            datum.iteration));
      }
  }

  void
  info_out_data_listener_exec_i::on_many_data (const ::UnkeyedTestSeq & /* data */,
  const ::CCM_DDS::ReadInfoSeq & /* infos */)
  {
    /* Your code here. */
  }

  /**
   * Facet Executor Implementation Class: info_out_status_exec_i
   */

  info_out_status_exec_i::info_out_status_exec_i (
        ::Unkeyed_Test::CCM_Receiver_Context_ptr ctx)
    : ciao_context_ (
        ::Unkeyed_Test::CCM_Receiver_Context::_duplicate (ctx))
  {
  }

  info_out_status_exec_i::~info_out_status_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::PortStatusListener

  void
  info_out_status_exec_i::on_requested_deadline_missed (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::RequestedDeadlineMissedStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_out_status_exec_i::on_sample_lost (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::SampleLostStatus & /* status */)
  {
    /* Your code here. */
  }

  /**
   * Facet Executor Implementation Class: info_out_connector_status_exec_i
   */

  info_out_connector_status_exec_i::info_out_connector_status_exec_i (
        ::Unkeyed_Test::CCM_Receiver_Context_ptr ctx)
    : ciao_context_ (
        ::Unkeyed_Test::CCM_Receiver_Context::_duplicate (ctx))
  {
  }

  info_out_connector_status_exec_i::~info_out_connector_status_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::ConnectorStatusListener

  void
  info_out_connector_status_exec_i::on_inconsistent_topic (::DDS::Topic_ptr /* the_topic */,
  const ::DDS::InconsistentTopicStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_out_connector_status_exec_i::on_requested_incompatible_qos (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::RequestedIncompatibleQosStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_out_connector_status_exec_i::on_sample_rejected (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::SampleRejectedStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_out_connector_status_exec_i::on_offered_deadline_missed (::DDS::DataWriter_ptr /* the_writer */,
  const ::DDS::OfferedDeadlineMissedStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_out_connector_status_exec_i::on_offered_incompatible_qos (::DDS::DataWriter_ptr /* the_writer */,
  const ::DDS::OfferedIncompatibleQosStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_out_connector_status_exec_i::on_unexpected_status (::DDS::Entity_ptr /* the_entity */,
  ::DDS::StatusKind /* status_kind */)
  {
    /* Your code here. */
  }

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  Receiver_exec_i::Receiver_exec_i (void)
    : iterations_ (10)
      , keys_ (3)
      , received_ (0)
  {
  }

  Receiver_exec_i::~Receiver_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  ::Unkeyed_Test::UnkeyedTestConnector::CCM_Listener_ptr
  Receiver_exec_i::get_info_out_data_listener (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_out_data_listener_.in ()))
      {
        info_out_data_listener_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_out_data_listener_exec_i (
            this->ciao_context_.in (),
            this->received_),
            ::Unkeyed_Test::UnkeyedTestConnector::CCM_Listener::_nil ());

          this->ciao_info_out_data_listener_ = tmp;
      }

    return
      ::Unkeyed_Test::UnkeyedTestConnector::CCM_Listener::_duplicate (
        this->ciao_info_out_data_listener_.in ());
  }

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_info_out_status (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_out_status_.in ()))
      {
        info_out_status_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_out_status_exec_i (
            this->ciao_context_.in ()),
            ::CCM_DDS::CCM_PortStatusListener::_nil ());

          this->ciao_info_out_status_ = tmp;
      }

    return
      ::CCM_DDS::CCM_PortStatusListener::_duplicate (
        this->ciao_info_out_status_.in ());
  }

  ::CCM_DDS::CCM_ConnectorStatusListener_ptr
  Receiver_exec_i::get_info_out_connector_status (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_out_connector_status_.in ()))
      {
        info_out_connector_status_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_out_connector_status_exec_i (
            this->ciao_context_.in ()),
            ::CCM_DDS::CCM_ConnectorStatusListener::_nil ());

          this->ciao_info_out_connector_status_ = tmp;
      }

    return
      ::CCM_DDS::CCM_ConnectorStatusListener::_duplicate (
        this->ciao_info_out_connector_status_.in ());
  }

  ::CORBA::UShort
  Receiver_exec_i::iterations (void)
  {
    return this->iterations_;
  }

  void
  Receiver_exec_i::iterations (
    const ::CORBA::UShort iterations)
  {
    this->iterations_ = iterations;
  }

  ::CORBA::UShort
  Receiver_exec_i::keys (void)
  {
    return this->keys_;
  }

  void
  Receiver_exec_i::keys (
    const ::CORBA::UShort keys)
  {
    this->keys_ = keys;
  }

  // Operations from Components::SessionComponent.

  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::Unkeyed_Test::CCM_Receiver_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Receiver_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_activate (void)
  {
    ::CCM_DDS::DataListenerControl_var lc =
      this->ciao_context_->get_connection_info_out_data_control ();

    if (::CORBA::is_nil (lc.in ()))
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Error:  Listener control receptacle is null!\n")));
        throw ::CORBA::INTERNAL ();
      }

    lc->mode (::CCM_DDS::ONE_BY_ONE);
  }

  void
  Receiver_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_remove (void)
  {
    ::CORBA::ULong expected = this->keys_ * this->iterations_;
    ACE_DEBUG ((LM_INFO, "Receiver_exec_i summary: received <%u>\n",
                this->received_.value ()));

    if (this->received_.value () != expected)
      {
        ACE_ERROR ((LM_ERROR, "Receiver_exec_i::ccm_remove - "
                  "ERROR: Unexpected number of samples received: "
                  "expected <%u> - received <%u>\n",
                  expected,
                  this->received_.value ()));
      }
  }

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Unkeyed_Test_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Receiver_exec_i);

    return retval;
  }
}
