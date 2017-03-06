// ROOM:__DIR__"camp2"

inherit ROOM;
void create()
{
        set("short","营火区");
	set("long",@LONG
这儿是嘉峪关兵营的营区，地上有一点篝火，还有点事物残喳。在边边则有一个水
井，想必是官兵们用来汲水用的，南侧为李偏将的营帐，东方则是
副将军的营帐，北侧为队长的营帐。如果没有事情冒然进入是会被斥责。
LONG
	); // eof(long)
	
	set("resource/water",1);

	set("exits",([ /* sizeof()==4 */
        	"north" : __DIR__"camp5",
        	"south" : __DIR__"camp6",
        	"east" : __DIR__"camp7",
        	"west" : __DIR__"camp1",
	]) ); //eof(exits)

	
	setup();
	
	replace_program(ROOM);
} //EOF
