// searoad.c
inherit ROOM;
void create()
{
        set("short", "长阶");
        set("long", @LONG
一道长阶直达峰巅，也不知有几千几百层，阶石打扫得干干净净，仿佛玉石。
LONG
        );
        set("exits", ([ 
	  	"westdown" : __DIR__"platform",
  		"eastup" : __DIR__"moonding",
	]));
        set("outdoors", "tieflag");
        setup();
}
int valid_leave(object who,string dir)
{   
    
    
    if( userp(who) && random(9))
   	{
   		who->move(this_object());
   		return notify_fail(""); 
   	}
   	return 1;
}