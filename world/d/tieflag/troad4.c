// searoad.c
inherit ROOM;
void create()
{
        set("short", "山中小路");
        set("long", @LONG
这里往东，地势略略向下倾斜。路两旁的灌木渐渐换成乔木，越走地势越开阔，
再走下去显然要走到大道上去了。南边是一条通向山上的小路。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"troad2",
  "south" : __DIR__"road",	
  "east" : __DIR__"plain",
]));
        set("outdoors", "tieflag");
        setup();
}


int valid_leave(object who,string dir)
{
   	if(userp(who) && random(3))
   	{
   		who->move(this_object());
   		return notify_fail(""); 
   	}
   	return 1;
}
