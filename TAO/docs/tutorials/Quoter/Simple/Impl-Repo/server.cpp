// $Id$

//===========================================================================
//
// = FILENAME 
//     server.cpp
// 
// = DESCRIPTION
//     In this example,
//        - Example showing the working of implementation repository.
//          
// = AUTHOR
//     Priyanka Gontla
//
//============================================================================

#include "Stock_Factory_i.h"
#include <iostream>

int 
main (int argc, char* argv[])
{
  try {
    
    // Initialze the ORB.
    CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);
    
    // Get a reference to the RootPOA.
    CORBA::Object_var obj = orb->resolve_initial_references ("RootPOA");
    
    // Get the POA_var object from Object_var.
    PortableServer::POA_var root_poa = 
      PortableServer::POA::_narrow (obj.in ());
    
    // Get the POAManager of the RootPOA.
    PortableServer::POAManager_var poa_manager = 
      root_poa->the_POAManager ();
    
    poa_manager->activate ();

    // Policies for the childPOA to be created.
    CORBA::PolicyList policies;
    policies.length (2);

    policies[0] =
      root_poa->create_id_assignment_policy (PortableServer::USER_ID);
    policies[1] =
      root_poa->create_lifespan_policy (PortableServer::PERSISTENT);

 
    // Create the childPOA under the RootPOA.
    PortableServer::POA_var child_poa = 
      root_poa->create_POA ("childPOA", 
                            poa_manager.in (),
                            policies);

    // Destroy the policy objects
    for (CORBA::ULong i = 0; i != policies.length (); ++i) {
      policies[i]->destroy ();
    }
    
    // Create an instance of class Quoter_Stock_Factory_i.
    Quoter_Stock_Factory_i stock_factory_i;
    
    // Get the Object ID.
    PortableServer::ObjectId_var oid =
      PortableServer::string_to_ObjectId ("Stock_Factory");
    
    // Activate the Stock_Factory object.
    child_poa->activate_object_with_id (oid.in (), 
					&stock_factory_i);
    
    // Get the object reference.
    CORBA::Object_var stock_factory =
      child_poa->id_to_reference (oid.in ());
    
    // Register our child POA with INS also, so we can get simplified
    // reqests.
    orb->_tao_add_to_IOR_table ( "childPOA", stock_factory.in ());
    
    // Stringify all the object referencs.
    CORBA::String_var ior = orb->object_to_string (stock_factory.in ());
    
    orb->run ();
    
    // Destroy POA, waiting until the destruction terminates.
    root_poa->destroy (1, 1);
    orb->destroy ();
  }
  catch (CORBA::Exception &) {
    std::cerr << "CORBA exception raised !" << std::endl;
  }
  return 0;
}

