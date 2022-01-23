/*****************************************************************************

  Licensed to Accellera Systems Initiative Inc. (Accellera) under one or
  more contributor license agreements.  See the NOTICE file distributed
  with this work for additional information regarding copyright ownership.
  Accellera licenses this file to you under the Apache License, Version 2.0
  (the "License"); you may not use this file except in compliance with the
  License.  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
  implied.  See the License for the specific language governing
  permissions and limitations under the License.

 *****************************************************************************/

/*****************************************************************************

  stimgen.h -- 

  Original Author: Martin Janssen, Synopsys, Inc., 2002-02-15

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

                /************************************/
                /* Interface Filename:	stimgen.h   */
                /************************************/

#include "common.h"

SC_MODULE( stimgen )
{
  SC_HAS_PROCESS( stimgen );

  sc_in_clk clk;

  // Inputs
	const sc_signal_bool_vector&	result;
  // Outputs
	sc_signal<int>&			in1;
	sc_signal<int>&			in2;
	sc_signal<bool>&		ready;

  // Constructor
  stimgen (sc_module_name		NAME,
	sc_clock&			TICK,
	const sc_signal_bool_vector&	RESULT,
	sc_signal<int>&			IN1,
	sc_signal<int>&			IN2,
	sc_signal<bool>&		READY )
	
      : 
	result	(RESULT),
	in1	(IN1),
	in2	(IN2),
	ready   (READY)

  	{
          clk	(TICK);
	  SC_CTHREAD( entry, clk.pos() );
        }

  void entry();
};
