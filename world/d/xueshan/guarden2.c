//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"后院"NOR);
	set("long", @LONG
	  后面的这个院子比前面小些，院中种满了竹子。每当风清月白的夏夜，
主人就会躺在这里，听那海浪般的竹涛声。所以这里又叫〖听竹小院】，后面那
一排房子，就叫〖听竹轩】。可苗人凤他爹当上主人时，却改为〖有竹无肉轩】，
他认为〖听竹】本来很雅，现在却很俗。
LONG
	);
	set("exits", ([
		"west" : __DIR__"lou.c",
		"south" : __DIR__"ting.c",
]));
	setup();
}

void init()
{
	add_action("do_yell", "yell");
}

int do_yell()
{       
	object ob,me;
	me=this_player();

        if( !me->query("mark/玉佩")) return 0;
	
	ob = new(__DIR__"npc/mrfeng");
	ob->move(__DIR__"guarden2");
	tell_room(__DIR__"guarden2", RED"只见苗人凤听到叫声，从竹林中走了出来。\n\n"NOR);
	if ( me->query("mark/玉佩") )
        me->delete("mark/玉佩");         
    		return 1;  
}
