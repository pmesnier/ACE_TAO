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

#include "ThreeComp_Master_exec.h"
#include "ace/OS_NS_unistd.h"


namespace CIAO_ThreeComp_Master_Impl
{
  CORBA::Boolean asynch = false;
  //============================================================
  // Worker thread for asynchronous invocations for State
  //============================================================
  asynch_state_generator::asynch_state_generator (
   ::ThreeComp::CCM_Master_Context_ptr context,
    Atomic_UShort  &nr_of_rec,
    Atomic_UShort  &nr_of_sent)
  : context_(::ThreeComp::CCM_Master_Context::_duplicate (context)),
    nr_of_rec_(nr_of_rec),
   nr_of_sent_(nr_of_sent)
  {
  }

  int asynch_state_generator::svc ()
  {
    ::ThreeComp::AMI4CCM_State_var my_state_ami_  =
       context_->get_connection_sendc_run_my_state();

    ACE_OS::sleep(2);
   ::ThreeComp::AMI4CCM_StateReplyHandler_var cb =
        new AMI4CCM_StateReplyHandler_run_my_state_i (
                                                  this->nr_of_rec_,
                                                  this->nr_of_sent_);

    if (CORBA::is_nil (my_state_ami_))
      {
         ACE_ERROR ((LM_ERROR, "ERROR Master (ASYNCH) :"
                             "\tstate_ami is NIL !\n"));
         return 1;
      }
    //Invoke Asynchronous calls to test

    for (int i = 0; i < 3; i ++)
      {
        ++this->nr_of_sent_;
        my_state_ami_->sendc_bar ( cb.in(), 1);
        ACE_DEBUG ((LM_DEBUG, "OK: Master sends  ASYNCHRONOUS call to Sender.\n"));
      }
    //there is more than 1 message sent, without receiving callbacks,
    //so it is asynchronous
    if (this->nr_of_sent_.value() > 1)
      {
        asynch = true;
      }
    return 0;
  }
  //============================================================
  // Worker thread for synchronous invocations for State
  //============================================================
  synch_state_generator::synch_state_generator (
   ::ThreeComp::CCM_Master_Context_ptr context)
  : context_(::ThreeComp::CCM_Master_Context::_duplicate (context))
  {
  }

  int synch_state_generator::svc ()
  {
    ::ThreeComp::State_var my_state_ami_ =
         context_->get_connection_run_my_state ();

    ACE_OS::sleep(1);
    CORBA::Boolean wait = false;
    for (int i = 0; i < 3; ++i)
      {
        // Run some synch calls, answer has to come before the next step.
         CORBA::String_var answer;
         ::CORBA::Long ret = 0;
         try
           {
             if ( wait==true)
               {
                 ACE_ERROR ((LM_ERROR,
                             "ERROR: NOT RECEIVED SYNCHRONOUS answer.\n"));
               }
             wait = true;
             ACE_DEBUG ((LM_DEBUG, "OK: Master send SYNCHRONOUS call to Sender.\n"));
             ret = my_state_ami_->bar (2,answer.out());
             if (ret == 2)
               {
                 ACE_DEBUG ((LM_DEBUG, "OK: Master received SYNCHRONOUS answer from Sender <%C>\n",
                                       answer.in ()));
                 wait = false;
               }
            }
          catch (const ThreeComp::InternalError&)
            {
              ACE_ERROR ((LM_ERROR, "ERROR: synch_state_generator::state: "
                                    "Unexpected exception.\n"));
            }
       }
    return 0;
  }
  /**
   * Component Executor Implementation Class: Master_exec_i
   */

  Master_exec_i::Master_exec_i (void)
  : asynch_state_gen(0),
    synch_state_gen(0),
    nr_of_rec_ (0),
    nr_of_sent_(0)
  {
  }

  Master_exec_i::~Master_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  // Operations from Components::SessionComponent.

  void
  Master_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::ThreeComp::CCM_Master_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Master_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Master_exec_i::ccm_activate (void)
  {
    this->asynch_state_gen =
       new asynch_state_generator (this->ciao_context_.in (),
                                    this->nr_of_rec_,
                                    this->nr_of_sent_);
    this->asynch_state_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

    this->synch_state_gen =
        new synch_state_generator (this->ciao_context_.in());
    this->synch_state_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);
  }

  void
  Master_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Master_exec_i::ccm_remove (void)
  {
    if ((asynch == false) || (this->nr_of_rec_.value() != 3))
      {
        ACE_ERROR ((LM_ERROR,
                   "ERROR: Test not asynchronous or not received back"
                   " all requests ( %u/3)!\n",
                   this->nr_of_rec_.value() ));
      }
    else
      {
        ACE_DEBUG ((LM_DEBUG, "OK: Test Master.\n"));
      }
    delete this->asynch_state_gen;
    this->asynch_state_gen = 0;
    delete this->synch_state_gen;
    this->synch_state_gen = 0;
  }

  AMI4CCM_StateReplyHandler_run_my_state_i::AMI4CCM_StateReplyHandler_run_my_state_i (
      Atomic_UShort  &nr_of_rec,
       Atomic_UShort  &nr_of_sent)
   : nr_of_rec_(nr_of_rec),
     nr_of_sent_(nr_of_sent)
  {
  }

  AMI4CCM_StateReplyHandler_run_my_state_i::~AMI4CCM_StateReplyHandler_run_my_state_i (void)
  {
  }

  void
  AMI4CCM_StateReplyHandler_run_my_state_i::bar (
    ::CORBA::Long  ami_return_val,
    const char * answer)
  {
    if (ami_return_val == 1)
       {
         ++this->nr_of_rec_;
         --this->nr_of_sent_;
         ACE_DEBUG ((LM_DEBUG, "OK: Master get ASYNCHRONOUS callback "
                    "from Sender: <%C>.\n",
                    answer));
       }
  }

  void
  AMI4CCM_StateReplyHandler_run_my_state_i::bar_excep (
    ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  extern "C" THREECOMP_MASTER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_ThreeComp_Master_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Master_exec_i);

    return retval;
  }
}
