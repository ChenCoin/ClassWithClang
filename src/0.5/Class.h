#define new(TYPE)   init##TYPE()
#define $(VAR)      (VAR->func)(VAR)
#define this(TYPE)  ( *get##TYPE##This() )

#define DeleteBracket(...)	__VA_ARGS__

#define crtClass(TYPE,DATA,FUNC) \
			typedef struct TYPE##Data{\
	            DeleteBracket DATA\
                struct TYPE##Func (*func)(struct TYPE##Data*);\
            }TYPE##Data;\
            \
            typedef TYPE##Data* TYPE;\
            typedef struct TYPE##Func{\
	            DeleteBracket FUNC\
            }TYPE##Func;\
            \
            TYPE* get##TYPE##This();\
            TYPE##Func get##TYPE##Func(TYPE);\
            TYPE init##TYPE();
            
#define initClass(TYPE, DATA, FUNC) \
            TYPE* get##TYPE##This(){\
                static TYPE m##TYPE##Data = NULL;\
                return &m##TYPE##Data;\
            }\
            TYPE##Func get##TYPE##Func(TYPE m##TYPE){\
	            ( *get##TYPE##This() ) = m##TYPE;\
                static TYPE##Func m##TYPE##Func = {\
	                DeleteBracket FUNC\
                };\
	            return m##TYPE##Func;\
            }\
            TYPE init##TYPE(){\
                TYPE m##TYPE = (TYPE)malloc(1);\
                m##TYPE->func = get##TYPE##Func;\
                this(TYPE) = m##TYPE;\
                DeleteBracket DATA\
                return m##TYPE;\
            }
            
