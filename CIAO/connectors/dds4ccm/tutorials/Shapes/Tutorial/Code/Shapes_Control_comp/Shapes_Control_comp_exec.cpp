// -*- C++ -*-
/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.2.3
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

#include "Shapes_Control_comp_exec.h"
#include "tao/ORB_Core.h"
#include "ace/Reactor.h"

namespace CIAO_Shapes_Control_comp_Impl
{

  /**
   * Component Executor Implementation Class: Control_comp_exec_i
   */

  Control_comp_exec_i::Control_comp_exec_i (void)
    : rate_ (0)
      , max_x_ (0)
      , max_y_ (0)
      , max_size_ (0)
      , resize_shape_ (false)
  {
  }

  Control_comp_exec_i::~Control_comp_exec_i (void)
  {
  }

  // Supported operations and attributes.
  ACE_Reactor*
  Control_comp_exec_i::reactor (void)
  {
    ACE_Reactor* reactor = 0;
    ::CORBA::Object_var ccm_object =
      this->ciao_context_->get_CCM_object();
    if (! ::CORBA::is_nil (ccm_object.in ()))
      {
        ::CORBA::ORB_var orb = ccm_object->_get_orb ();
        if (! ::CORBA::is_nil (orb.in ()))
          {
            reactor = orb->orb_core ()->reactor ();
          }
      }
    if (reactor == 0)
      {
        throw ::CORBA::INTERNAL ();
      }
    return reactor;
  }

  // Component attributes and port operations.

  ::CORBA::ULong
  Control_comp_exec_i::rate (void)
  {
    return this->rate_;
  }

  void
  Control_comp_exec_i::rate (
    const ::CORBA::ULong rate)
  {
    this->rate_ = rate;
  }

  ::CORBA::UShort
  Control_comp_exec_i::max_x (void)
  {
    return this->max_x_;
  }

  void
  Control_comp_exec_i::max_x (
    const ::CORBA::UShort max_x)
  {
    this->max_x_ = max_x;
  }

  ::CORBA::UShort
  Control_comp_exec_i::max_y (void)
  {
    return this->max_y_;
  }

  void
  Control_comp_exec_i::max_y (
    const ::CORBA::UShort max_y)
  {
    this->max_y_ = max_y;
  }

  ::CORBA::UShort
  Control_comp_exec_i::max_size (void)
  {
    return this->max_size_;
  }

  void
  Control_comp_exec_i::max_size (
    const ::CORBA::UShort max_size)
  {
    this->max_size_ = max_size;
  }

  ::CORBA::Boolean
  Control_comp_exec_i::resize_shape (void)
  {
    return this->resize_shape_;
  }

  void
  Control_comp_exec_i::resize_shape (
    const ::CORBA::Boolean resize_shape)
  {
    this->resize_shape_ = resize_shape;
  }

  // Operations from Components::SessionComponent.

  void
  Control_comp_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::Shapes::CCM_Control_comp_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Control_comp_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Control_comp_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }

  void
  Control_comp_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Control_comp_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C" SHAPES_CONTROL_COMP_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Shapes_Control_comp_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Control_comp_exec_i);

    return retval;
  }
}
