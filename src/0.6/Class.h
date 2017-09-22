#ifndef h_Class
#define h_Class

#define new(TYPE)   init##TYPE()
#define $(VAR)      ( ((VAR)->func)(VAR) )
#define this(TYPE)  (*get##TYPE##This())
#define extends(VAR) VAR

#define Name(VAR) VAR
#define DataInit(VAR) (VAR)
#define FuncInit(VAR) (VAR)

#define initFunc(...)
#define initData(...)
#define getFunc(...)
#define Func void

#define CreateClass(...) 			\
	CrtClass(__VA_ARGS__)
#define CrtClass(TYPE,DATAinit,			\
			FUNCinit, ...) 		\
	typedef struct TYPE##Data{		\
		struct TYPE##Func (*func)(	\
			struct TYPE##Data*);	\
		TYPE##_DATA			\
	}TYPE##Data;				\
	typedef TYPE##Data* TYPE;		\
						\
	typedef struct TYPE##Func{		\
		TYPE##_FUNC			\
	}TYPE##Func;				\
						\
	TYPE* get##TYPE##This();		\
	TYPE##Func get##TYPE##Func(TYPE);	\
	TYPE init##TYPE();			\
						\
						\
	int init##TYPE##Func(			\
			TYPE##Func* this){	\
		init##__VA_ARGS__##Func(	\
			(__VA_ARGS__##Func*)	\
			this);			\
		extends FUNCinit		\
		return 0;			\
	}					\
	int init##TYPE##Data(TYPE this){	\
		init##__VA_ARGS__##Data(	\
			(__VA_ARGS__)this);	\
		this->func = get##TYPE##Func;	\
		extends DATAinit		\
		return 0;			\
	}					\
	TYPE* get##TYPE##This(){		\
		static TYPE m##TYPE##Data =NULL;\
		return &m##TYPE##Data;		\
	}					\
	TYPE##Func get##TYPE##Func(		\
			TYPE m##TYPE){		\
		( *get##TYPE##This() ) =m##TYPE;\
		get##__VA_ARGS__##Func(		\
			(__VA_ARGS__)m##TYPE);	\
						\
		static TYPE##Func m##TYPE##Func;\
		static int FuncInit = 0;	\
		if(!FuncInit){			\
			init##TYPE##Func(	\
				&m##TYPE##Func);\
			FuncInit = 1;		\
		}				\
		return m##TYPE##Func;		\
	}					\
	TYPE init##TYPE(){			\
		TYPE m##TYPE = (TYPE)malloc	\
			(sizeof(TYPE##Data));	\
		init##TYPE##Data(m##TYPE);	\
		return m##TYPE;			\
	}
/* end define CreateClass */

#endif


