// ROOM:__DIR__"camp5"

inherit ROOM;
void create()
{
        set("short","队长营帐");
	set("long",@LONG                                   
这里是队长的营帐，四周仍旧和小兵营帐一样的空旷，但营帐的布
料倒是比小兵营帐好多了，北侧有两把木椅.是队长们聊天的地方。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"south" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/duizhang" : 2,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
