/*
  Copyright (c) 1996 Blake McBride
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are
  met:

  1. Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/



/*  This file automatically generated by dpp - do not edit  */

#define	DPP_STRATEGY	2
#define	DPP_FASTWIDE	0




#define	CLASS	Dictionary_c
#define	ivType	Dictionary_iv_t

#include "generics.h"

object	Dictionary_c;


#line 39 "Dictionary.d"
#include "set1.h" 


#define LTYPE 1 

static gLookup_t Lookup; 

imeth objrtn Dictionary_im_gAddValue(object self, object key, object value)
{ 
	ChkArg(key, 2); 
	ChkArgNul(value, 3); 
	return Lookup(self, key, HT_ADD, 0, LTYPE, value); 
} 

imeth objrtn Dictionary_im_gFindValue(object self, object key)
{ 
	object x; 

	ChkArg(key, 2); 
	x = Lookup(self, key, HT_FIND, 0, LTYPE, NULL); 
	return x ? gValue(x) : x; 
} 

imeth objrtn Dictionary_im_gFind(object self, object key)
{ 
	ChkArg(key, 2); 
	return Lookup(self, key, HT_FIND, 0, LTYPE, NULL); 
} 

imeth objrtn Dictionary_im_gChangeValueWithObj(object self, object key, object val)
{ 
	object x; 
	ChkArg(key, 2); 
	ChkArgNul(val, 3); 
	x = Lookup(self, key, HT_FIND, 0, LTYPE, NULL); 
	return x ? gChangeValue(x, val) : x; 
} 

imeth objrtn Dictionary_im_gFindAddValue(object self, object key, object value)
{ 
	ChkArg(key, 2); 
	ChkArgNul(value, 3); 
	return Lookup(self, key, HT_FINDADD, 0, LTYPE, value); 
} 

imeth objrtn Dictionary_im_gDispose(object self)
{ 
	return gDispose1(self); 
} 

imeth objrtn Dictionary_im_gDisposeAllNodes(object self)
{ 
	return gDisposeAllNodes1(self); 
} 

imeth objrtn Dictionary_im_gRemoveObj(object self, object key)
{ 
	ChkArg(key, 2); 
	return Lookup(self, key, HT_DELETE, 1, LTYPE, NULL); 
} 

imeth objrtn Dictionary_im_gDeepDisposeObj(object self, object key)
{ 
	ChkArg(key, 2); 
	return Lookup(self, key, HT_DELETE, 2, LTYPE, NULL); 
} 

static void init_class(void) 
{ 
	Lookup = imcPointer(Set, gLookup); 
} 

#line 121 "Dictionary.c"

objrtn	Dictionary_initialize(void)
{
	static  CRITICALSECTION  cs;
	static  int volatile once = 0;

	ENTERCRITICALSECTION(_CI_CS_);
	if (!once) {
		INITIALIZECRITICALSECTION(cs);
		once = 1;
	}
	LEAVECRITICALSECTION(_CI_CS_);

	ENTERCRITICALSECTION(cs);

	if (Dictionary_c) {
		LEAVECRITICALSECTION(cs);
		return Dictionary_c;
	}
	INHIBIT_THREADER;
	Set_initialize();
	if (Dictionary_c)  {
		ENABLE_THREADER;
		LEAVECRITICALSECTION(cs);
		return Dictionary_c;
	}
	Dictionary_c = gNewClass(Class, "Dictionary", 0, 0, Set, END);
	iMethodFor(Dictionary, gDeepDisposeObj, Dictionary_im_gDeepDisposeObj);
	iMethodFor(Dictionary, gChangeValueWithObj, Dictionary_im_gChangeValueWithObj);
	iMethodFor(Dictionary, gFind, Dictionary_im_gFind);
	iMethodFor(Dictionary, gDisposeObj, Dictionary_im_gDeepDisposeObj);
	iMethodFor(Dictionary, gDisposeAllNodes, Dictionary_im_gDisposeAllNodes);
	iMethodFor(Dictionary, gRemoveObj, Dictionary_im_gRemoveObj);
	iMethodFor(Dictionary, gDispose, Dictionary_im_gDispose);
	iMethodFor(Dictionary, gFindAddValue, Dictionary_im_gFindAddValue);
	iMethodFor(Dictionary, gAddValue, Dictionary_im_gAddValue);
	iMethodFor(Dictionary, gFindValue, Dictionary_im_gFindValue);

	init_class();

	ENABLE_THREADER;

	LEAVECRITICALSECTION(cs);

	return Dictionary_c;
}



