///classes

#define property(type, name)										\
		protected:													\
		type name;													\
		public:														\
		inline void set##name(type name) { this->name = name; }		\
		inline type get##name() { return this->name; }	
#define readonly __readonly

///logic

#define or ||
#define and &&
#define not !

//for each

#define in :
#define foreach for

//pointers

#define ref &