// ROOM:__DIR__"camp8"

inherit ROOM;
void create()
{
        set("short","大将军营帐");
	set("long",@LONG                                   
这里就是大将军的营帐，布置的并不豪华，这也许是霍将军
与众不同的地方，东侧一个长条木桌，摆放着整整齐齐的书籍，
表明将军不仅是只会武功的猛将，还是一位很有学问的智者。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1*/
        	"north" : __DIR__"camp7",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/general" : 1,
		__DIR__"npc/adviser" : 1,
	]) );
	
	setup();
	
//	replace_program(ROOM);
} //EOF
