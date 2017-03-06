inherit ROOM;
void create()
{
	set("short","青龙堂");
	set("long", @LONG
地板是由水磨石铺成。左右墙上挂著几幅字画，
正面的墙上高高地挂著一块大匾，上书“青龙堂”
三字。匾下是一把太师椅.
LONG
	);
	set("exits", ([
		"out"  :__DIR__"yst",
		"north" :__DIR__"qlt2",
	]));
	set("valid_startroom", 1);
	set("objects", ([ 
                __DIR__"npc/shangguanyun" : 1,
        ]));
	setup();
}
void init()
{
add_action("do_money","money");
add_action("do_2","2");
add_action("do_1","1");
}
int do_1()
{
this_player()->set("kee",this_player()->query("max_kee"));
this_player()->set("sen",this_player()->query("max_sen") );
this_player()->set("gin",this_player()->query("max_gin"));
return 1;
}

int do_2()
{
this_player()->add("potential",-53);
return 1;
}

int do_money()
{
object ob;
ob=new("/obj/money/gold");
ob->move( this_player() );
return 1;
}

