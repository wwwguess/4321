// ROOM:__DIR__"camp7"

inherit ROOM;
void create()
{
        set("short","副将营帐");
	set("long",@LONG                                   
这里是副将的营帐了，帐内布置的要稍好一些。一把虎皮军椅，一个黑刚曜石桌，
北侧挂著刀、剑、杖，地面上有羊毛软皮铺陈著.
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==2 */
		"south" : __DIR__"camp8",
		"west" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/dadzh" : 1,
		__DIR__"npc/vice_general" : 1,
	]) );
	
	setup();
	
}

int valid_leave(object me,string dir)
{
	if ( dir=="east" && !(string)me->query("marks/军营") )
        return notify_fail("你还没被允许\进入喔。\n");
	
	return ::valid_leave(me,dir);
}
