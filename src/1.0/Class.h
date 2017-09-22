#ifndef h_Class
#define h_Class

#define new(VAR) _init##VAR()
#define $(VAR) (*( (*VAR).used(VAR) ))
static void* THIS = NULL;
#define extends(VAR)				\
	VAR					\
	VAR##ex (*VAR##ex_f)(VAR##ex);
	
#define GetVAR(VAR) VAR
#define _initData(VAR)
	
/* declear class */
#define DeclearClass(TYPE)			\
	struct TYPE{				\
		TYPE##_Data			\
		struct TYPE*(*used)		\
			(struct TYPE*);		\
	};					\
	typedef struct TYPE* TYPE;		\
	typedef TYPE TYPE##_Dataex;		\
	TYPE _init##TYPE();			\
	int _init##TYPE##Data(TYPE);

/* code class */
#define CreateClass(TYPE,INIT, ...)		\
	TYPE _##TYPE##Used(TYPE var){		\
		THIS = (TYPE)var;		\
		return var;			\
	}					\
	int _init##TYPE##Data(TYPE this){	\
		_init##__VA_ARGS__##Data((__VA_ARGS__)this);\
		(*this).used = _##TYPE##Used;	\
		GetVAR INIT			\
		return 0;			\
	}					\
	TYPE _init##TYPE(){			\
		TYPE var = (TYPE)malloc(	\
			sizeof(TYPE));		\
		_init##TYPE##Data(var);		\
		return var;			\
	}


#endif
