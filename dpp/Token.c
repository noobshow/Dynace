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



#line 30 "Token.d"
#include "dpp.h" 

#define	CLASS	Token_c
#define	ivType	Token_iv_t

#include "generics.h"

object	Token_c;


#line 50 "Token.c"
typedef struct  _Token_iv_t  {
	object iToken;
	long iLine;
	int iSpace;
}	Token_iv_t;



#line 40 "Token.d"
cmeth objrtn Token_cm_gNew(object self)
{ 
	return gShouldNotImplement(self, "gNew"); 
} 

cmeth objrtn Token_cm_gNewToken(object self, char *tkn, long ln, int sp)
{ 
	object obj; 
	ivType *iv; 

	obj = oSuper(Token_c, gNew, self)(self); 
	iv = ivPtr(obj); 
	iv->iToken = gNewWithStr(String, tkn); 
	iv->iLine = ln; 
	iv->iSpace = sp; 
	return obj; 
} 

imeth objrtn Token_im_gDispose(object self)
{ Token_iv_t *iv = GetIVs(Token, self);
	gDispose(iv->iToken); 
	return oSuper(Token_c, gDispose, self)(self); 
} 

imeth char * Token_im_gStringValue(object self)
{ Token_iv_t *iv = GetIVs(Token, self);
	return gStringValue(iv->iToken); 
} 

imeth objrtn Token_im_gToken(object self)
{ Token_iv_t *iv = GetIVs(Token, self);
	return iv->iToken; 
} 

imeth objrtn Token_im_gChangeToken(object self, char *str)
{ Token_iv_t *iv = GetIVs(Token, self);
	gChangeStrValue(iv->iToken, str); 
	return self; 
} 

imeth long Token_im_gLineNumber(object self)
{ Token_iv_t *iv = GetIVs(Token, self);
	return iv->iLine; 
} 

imeth int Token_im_gSpace(object self)
{ Token_iv_t *iv = GetIVs(Token, self);
	return iv->iSpace; 
} 

imeth objrtn Token_im_gCopy(object self)
{ Token_iv_t *iv = GetIVs(Token, self);
	object obj = oSuper(Token_c, gCopy, self)(self); 
	ivType *niv = ivPtr(obj); 
	niv->iToken = gCopy(iv->iToken); 
	return obj; 
} 

imeth objrtn Token_im_gStringRepValue(object self)
{ Token_iv_t *iv = GetIVs(Token, self);
	return gStringRepValue(iv->iToken); 
} 

imeth objrtn Token_im_gStringRep(object self)
{ Token_iv_t *iv = GetIVs(Token, self);
	object a, b, s; 

	a = oSuper(Token_c, gStringRepValue, self)(self); 
	b = gStringRepValue(iv->iToken); 
	s = vBuild(String, gName(ClassOf(self)), " (", a, ", ", b, ")\n", NULL); 
	DISPOSE(a); 
	DISPOSE(b); 
	return s; 
} 


#line 136 "Token.c"

objrtn	Token_initialize(void)
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

	if (Token_c) {
		LEAVECRITICALSECTION(cs);
		return Token_c;
	}
	INHIBIT_THREADER;
	Link_initialize();
	if (Token_c)  {
		ENABLE_THREADER;
		LEAVECRITICALSECTION(cs);
		return Token_c;
	}
	Token_c = gNewClass(Class, "Token", sizeof(Token_iv_t), 0, Link, END);
	cMethodFor(Token, gNew, Token_cm_gNew);
	cMethodFor(Token, gNewToken, Token_cm_gNewToken);
	iMethodFor(Token, gToken, Token_im_gToken);
	iMethodFor(Token, gSpace, Token_im_gSpace);
	iMethodFor(Token, gLineNumber, Token_im_gLineNumber);
	iMethodFor(Token, gDispose, Token_im_gDispose);
	iMethodFor(Token, gChangeToken, Token_im_gChangeToken);
	iMethodFor(Token, gStringRepValue, Token_im_gStringRepValue);
	iMethodFor(Token, gCopy, Token_im_gCopy);
	iMethodFor(Token, gDeepDispose, Token_im_gDispose);
	iMethodFor(Token, gStringRep, Token_im_gStringRep);
	iMethodFor(Token, gDeepCopy, Token_im_gCopy);
	iMethodFor(Token, gStringValue, Token_im_gStringValue);

	ENABLE_THREADER;

	LEAVECRITICALSECTION(cs);

	return Token_c;
}



