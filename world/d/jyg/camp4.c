// ROOM:__DIR__"camp4"

inherit ROOM;
void create()
{
        set("short","守兵营帐");
	set("long",@LONG                                   
这里有一大群的守兵，不知道是在做什么，营帐中央有一张桌子，上
面堆满了各式各样的赌具，小板凳，和茶水。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"north" : __DIR__"camp1",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/xinbing" : 2,
		__DIR__"npc/laobing" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
