/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__glutamate
#define _nrn_initial _nrn_initial__glutamate
#define nrn_cur _nrn_cur__glutamate
#define _nrn_current _nrn_current__glutamate
#define nrn_jacob _nrn_jacob__glutamate
#define nrn_state _nrn_state__glutamate
#define _net_receive _net_receive__glutamate 
#define state state__glutamate 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define gmax _p[0]
#define e _p[1]
#define ntar _p[2]
#define del _p[3]
#define Tspike _p[4]
#define Nspike _p[5]
#define inmda _p[6]
#define iampa _p[7]
#define gnmda _p[8]
#define gh _p[9]
#define local_v _p[10]
#define A _p[11]
#define B _p[12]
#define gampa _p[13]
#define h _p[14]
#define ica _p[15]
#define cai _p[16]
#define DA _p[17]
#define DB _p[18]
#define Dgampa _p[19]
#define Dh _p[20]
#define _g _p[21]
#define _nd_area  *_ppvar[0]._pval
#define _ion_cai	*_ppvar[2]._pval
#define _ion_ica	*_ppvar[3]._pval
#define _ion_dicadv	*_ppvar[4]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 /* declaration of user functions */
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(_ho) Object* _ho; { void* create_point_process();
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt();
 static double _hoc_loc_pnt(_vptr) void* _vptr; {double loc_point_process();
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(_vptr) void* _vptr; {double has_loc_point();
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(_vptr)void* _vptr; {
 double get_loc_point_process(); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 0, 0
};
 /* declare global and static user variables */
#define cah cah_glutamate
 double cah = 10;
#define gama gama_glutamate
 double gama = 0.08;
#define n n_glutamate
 double n = 0.25;
#define tauh tauh_glutamate
 double tauh = 1000;
#define tau_ampa tau_ampa_glutamate
 double tau_ampa = 2;
#define tau2 tau2_glutamate
 double tau2 = 5;
#define tau1 tau1_glutamate
 double tau1 = 90;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "tau1_glutamate", "ms",
 "tau2_glutamate", "ms",
 "tau_ampa_glutamate", "ms",
 "n_glutamate", "/mM",
 "gama_glutamate", "/mV",
 "cah_glutamate", "/ms",
 "tauh_glutamate", "/ms",
 "gmax", "nS",
 "e", "mV",
 "del", "ms",
 "Tspike", "ms",
 "A", "nS",
 "B", "nS",
 "h", "nS",
 "inmda", "nA",
 "iampa", "nA",
 "gnmda", "nS",
 "gh", "nS",
 "local_v", "mV",
 0,0
};
 static double A0 = 0;
 static double B0 = 0;
 static double delta_t = 0.01;
 static double gampa0 = 0;
 static double h0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "tau1_glutamate", &tau1_glutamate,
 "tau2_glutamate", &tau2_glutamate,
 "tau_ampa_glutamate", &tau_ampa_glutamate,
 "n_glutamate", &n_glutamate,
 "gama_glutamate", &gama_glutamate,
 "cah_glutamate", &cah_glutamate,
 "tauh_glutamate", &tauh_glutamate,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[5]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"glutamate",
 "gmax",
 "e",
 "ntar",
 "del",
 "Tspike",
 "Nspike",
 0,
 "inmda",
 "iampa",
 "gnmda",
 "gh",
 "local_v",
 0,
 "A",
 "B",
 "gampa",
 "h",
 0,
 0};
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 22, _prop);
 	/*initialize range parameters*/
 	gmax = 1;
 	e = 0;
 	ntar = 0.3;
 	del = 30;
 	Tspike = 10;
 	Nspike = 1;
  }
 	_prop->param = _p;
 	_prop->param_size = 22;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 6, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[2]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[3]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[4]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _glutamate_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("ca", 2.0);
 	_ca_sym = hoc_lookup("ca_ion");
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 0,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 22, 6);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 glutamate C:/Users/brian/Neuron-Reconstruction1/biophysical_mods/glutamate.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double F = 96480.0;
 static double R = 8.314;
static int _reset;
static char *modelname = "NMDA synapse with depression";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[4], _dlist1[4];
 static int state(_threadargsproto_);
 extern int state_discon_flag_;
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   DA = - A / tau1 ;
   DB = - B / tau2 ;
   Dgampa = - gampa / tau_ampa ;
   Dh = ( cah * cai - h ) / tauh ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 DA = DA  / (1. - dt*( ( - 1.0 ) / tau1 )) ;
 DB = DB  / (1. - dt*( ( - 1.0 ) / tau2 )) ;
 Dgampa = Dgampa  / (1. - dt*( ( - 1.0 ) / tau_ampa )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tauh )) ;
  return 0;
}
 /*END CVODE*/
 static int state () {_reset=0;
 {
    A = A + (1. - exp(dt*(( - 1.0 ) / tau1)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau1 ) - A) ;
    B = B + (1. - exp(dt*(( - 1.0 ) / tau2)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau2 ) - B) ;
    gampa = gampa + (1. - exp(dt*(( - 1.0 ) / tau_ampa)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau_ampa ) - gampa) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tauh)))*(- ( ( ( ( cah )*( cai ) ) ) / tauh ) / ( ( ( ( - 1.0 ) ) ) / tauh ) - h) ;
   }
  return 0;
}
 
static int _ode_count(int _type){ return 4;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cai = _ion_cai;
     _ode_spec1 ();
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 4; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 ();
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cai = _ion_cai;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 3, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 4, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  A = A0;
  B = B0;
  gampa = gampa0;
  h = h0;
 {
   gnmda = 0.0 ;
   gampa = 0.0 ;
   h = 0.0 ;
   A = 0.0 ;
   B = 0.0 ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  cai = _ion_cai;
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   double _lcount ;
 {int  _lcount ;for ( _lcount = 0 ; _lcount <= ((int) Nspike ) - 1 ; _lcount ++ ) {
     if ( at_time ( nrn_threads, ((double) _lcount ) * Tspike + del ) ) {
       state_discontinuity ( _cvode_ieq + 0, & A , A + gmax ) ;
       state_discontinuity ( _cvode_ieq + 1, & B , B + gmax ) ;
       state_discontinuity ( _cvode_ieq + 2, & gampa , gampa + gmax / ntar ) ;
       }
     } }
   gnmda = ( A - B ) / ( 1.0 + n * exp ( - gama * v ) ) ;
   gh = ( exp ( - h ) ) ;
   inmda = ( 1e-3 ) * gnmda * gh * ( v - e ) ;
   ica = inmda / 10.0 ;
   iampa = ( 1e-3 ) * gampa * ( v - e ) ;
   local_v = v ;
   }
 _current += ica;
 _current += inmda;
 _current += iampa;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  cai = _ion_cai;
 _g = _nrn_current(_v + .001);
 	{ double _dica;
  _dica = ica;
 state_discon_flag_ = 1; _rhs = _nrn_current(_v); state_discon_flag_ = 0;
  _ion_dicadv += (_dica - ica)/.001 * 1.e2/ (_nd_area);
 	}
 _g = (_g - _rhs)/.001;
  _ion_ica += ica * 1.e2/ (_nd_area);
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  cai = _ion_cai;
 { error =  state();
 if(error){fprintf(stderr,"at line 79 in file glutamate.mod:\n	SOLVE state METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
 } }}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(A) - _p;  _dlist1[0] = &(DA) - _p;
 _slist1[1] = &(B) - _p;  _dlist1[1] = &(DB) - _p;
 _slist1[2] = &(gampa) - _p;  _dlist1[2] = &(Dgampa) - _p;
 _slist1[3] = &(h) - _p;  _dlist1[3] = &(Dh) - _p;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "glutamate.mod";
static const char* nmodl_file_text = 
  "COMMENT\n"
  "//****************************//\n"
  "// Created by Alon Polsky 	//\n"
  "//    apmega@yahoo.com		//\n"
  "//		2007			//\n"
  "//****************************//\n"
  "ENDCOMMENT\n"
  "\n"
  "TITLE NMDA synapse with depression\n"
  "\n"
  "NEURON {\n"
  "	POINT_PROCESS glutamate\n"
  "	USEION ca READ cai WRITE ica VALENCE 2\n"
  "	NONSPECIFIC_CURRENT inmda,iampa\n"
  "\n"
  "	RANGE e ,gmax,ntar,local_v,inmda,iampa,gh\n"
  "	RANGE del,Tspike,Nspike\n"
  "	RANGE gnmda,gampa\n"
  "	GLOBAL n, gama,tau1,tau2,tau_ampa,tauh,cah\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(nA) 	= (nanoamp)\n"
  "	(mV)	= (millivolt)\n"
  "	(nS) 	= (nanomho)\n"
  "	(mM)    = (milli/liter)\n"
  "        F	= 96480 (coul)\n"
  "        R       = 8.314 (volt-coul/degC)\n"
  "\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	gmax=1	(nS)\n"
  "	e= 0.0	(mV)\n"
  "	tau1=90	(ms)	\n"
  "	tau2=5	(ms)	\n"
  "	tau_ampa=2	(ms)	\n"
  "	n=0.25 	(/mM)	\n"
  "	gama=0.08 	(/mV) \n"
  "	dt (ms)\n"
  "	ntar=.3	:NMDA to AMPA ratio\n"
  "	v		(mV)\n"
  "	del=30	(ms)\n"
  "	Tspike=10	(ms)\n"
  "	Nspike=1\n"
  "	cah   = 10	(/ms)		: max act rate  \n"
  "	tauh   = 1000	(/ms)		: max deact rate \n"
  "}\n"
  "\n"
  "ASSIGNED { \n"
  "	inmda		(nA)  \n"
  "	iampa		(nA)  \n"
  "	gnmda		(nS)\n"
  "	gh		(nS)\n"
  "	ica 		(mA/cm2)\n"
  "	local_v	(mV):local voltage\n"
  "	cai		(mM)	\n"
  "}\n"
  "STATE {\n"
  "	A (nS)\n"
  "	B (nS)\n"
  "	gampa\n"
  "	h		(nS)\n"
  "\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "      gnmda=0 \n"
  "      gampa=0 \n"
  "	h=0\n"
  "	A=0\n"
  "	B=0\n"
  "\n"
  "}    \n"
  "\n"
  "BREAKPOINT {  \n"
  "    \n"
  "	LOCAL count\n"
  "	SOLVE state METHOD cnexp\n"
  "	FROM count=0 TO Nspike-1 {\n"
  "		IF(at_time(count*Tspike+del)){\n"
  "			state_discontinuity( A, A+ gmax)\n"
  "			state_discontinuity( B, B+ gmax)\n"
  "			state_discontinuity( gampa, gampa+ gmax/ntar)\n"
  "		}\n"
  "	}\n"
  "\n"
  "	gnmda=(A-B)/(1+n*exp(-gama*v) )\n"
  "	gh=(exp(-h))\n"
  "	inmda =(1e-3)* gnmda * gh * (v-e)\n"
  "	ica=inmda/10\n"
  "	iampa= (1e-3)*gampa* (v- e)\n"
  "	local_v=v\n"
  "}\n"
  "\n"
  "DERIVATIVE state {\n"
  "	A'=-A/tau1\n"
  "	B'=-B/tau2\n"
  "	gampa'=-gampa/tau_ampa\n"
  "	h'=(cah*cai-h)/tauh\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  ;
#endif
