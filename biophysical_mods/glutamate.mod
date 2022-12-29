COMMENT
//****************************//
// Created by Alon Polsky 	//
//    apmega@yahoo.com		//
//		2007			//
//****************************//
ENDCOMMENT

TITLE NMDA synapse with depression

NEURON {
	POINT_PROCESS glutamate
	USEION ca READ cai WRITE ica VALENCE 2
	NONSPECIFIC_CURRENT inmda,iampa
	RANGE e ,gmax,ntar,local_v,inmda,iampa,gh
	RANGE del,Tspike,Nspike
	RANGE gnmda,gampa
	GLOBAL n, gama,tau1,tau2,tau_ampa,tauh,cah
}

UNITS {
	(nA) 	= (nanoamp)
	(mV)	= (millivolt)
	(nS) 	= (nanomho)
	(mM)    = (milli/liter)
        F	= 96480 (coul)
        R       = 8.314 (volt-coul/degC)

}

PARAMETER {
	gmax=1	(nS)
	e= 0.0	(mV)
	tau1=90	(ms)	
	tau2=5	(ms)	
	tau_ampa=2	(ms)	
	n=0.25 	(/mM)	
	gama=0.08 	(/mV) 
	dt (ms)
	ntar=.3	:NMDA to AMPA ratio
	v		(mV)
	del=30	(ms)
	Tspike=10	(ms)
	Nspike=1
	cah   = 10	(/ms)		: max act rate  
	tauh   = 1000	(/ms)		: max deact rate 
}

ASSIGNED { 
	inmda		(nA)  
	iampa		(nA)  
	gnmda		(nS)
	gh		(nS)
	ica 		(mA/cm2)
	local_v	(mV):local voltage
	cai		(mM)	
}
STATE {
	A (nS)
	B (nS)
	gampa
	h		(nS)

}

INITIAL {
      gnmda=0 
      gampa=0 
	h=0
	A=0
	B=0

}    

BREAKPOINT {  
    
	LOCAL count
	SOLVE state METHOD cnexp
	FROM count=0 TO Nspike-1 {
		IF(at_time(count*Tspike+del)){
			state_discontinuity( A, A+ gmax)
			state_discontinuity( B, B+ gmax)
			state_discontinuity( gampa, gampa+ gmax/ntar)
		}
	}

	gnmda=(A-B)/(1+n*exp(-gama*v) )
	gh=(exp(-h))
	inmda =(1e-3)* gnmda * gh * (v-e)
	ica=inmda/10
	iampa= (1e-3)*gampa* (v- e)
	local_v=v
}

DERIVATIVE state {
	A'=-A/tau1
	B'=-B/tau2
	gampa'=-gampa/tau_ampa
	h'=(cah*cai-h)/tauh
}





