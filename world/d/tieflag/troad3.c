//troad3
inherit ROOM;

void create()
{
        set("short", "危崖前");
        set("long", @LONG
小路到此突然中断，一道危崖档住你的去路。崖上藤条(tree)缠绕 ，显的颇为古怪。
一只通身雪白的波斯猫伏在地上一动不动。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"troad2",
]));
        set("objects", ([
        __DIR__"npc/cat" : 1,
                        ]) ); 
        set("item_desc", ([
                "tree": "这里的藤条(tree)很密，似乎经过人工布置。\n",
                "藤条": "这里的藤条(tree)很密，似乎经过人工布置。\n" 
	]) );
        
	set("outdoors","tieflag"); 	
        setup();
}
void init()
{
        add_action("do_west", "w");
        add_action("do_west", "west");
}
int do_west(string arg)
{
	object me;
	object room;
	me = this_player();
	if(me->query_temp("mark/cat"))
        {       
		me->delete_temp("mark/cat");
		message_vision("$N掀开藤条，从西面的一个山洞钻了进去。\n", me);
		room = load_object(__DIR__"dong0");
		if(room) me->move(room);
		return 1;
	}
	return 0;
}

