inherit ROOM;
void create()
{
	set("short","������");
	set("long", @LONG
�ذ�����ˮĥʯ�̳ɡ�����ǽ�Ϲ��������ֻ���
�����ǽ�ϸ߸ߵع���һ����ң����顰�����á�
���֡�������һ��̫ʦ��.
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

