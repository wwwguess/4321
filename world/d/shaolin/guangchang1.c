// Room: /d/shaolin/smdian.c
// Date: YZC 96/01/19
#include <ansi.h>

inherit ROOM;


void init();
void close_gate();
int do_open(string);
int do_close(string);
string look_gate();


void create()
{
    set("short", "�㳡");
        set("long", "������������ǰ�Ĺ㳡�������㳡�ɴ�����ʯ�̳ɣ���Ϊƽ̹��
���������Զ������Щ���𡣴Դ�С�ݴ�ʯ��ķ�϶�г��˳������㳡
��Χ�������ܵ������֣��Ľ��ϸ����˼���ʯ�����ּ�����Ϊģ������
ǰ����ǽ���ߣ��������ݣ�����һ�����������������ߵ����ɼľ��
�ߴ���(gate)���Ϸ�һ����ң����ɷ��������"+"\n\n"+

"                          "+YEL "��    ��    ��" NOR +

"\n\n"+"��ǰ����������վ�ż���ɮ�ˡ�"  
);     
    set("exits", ([
        "east" : __DIR__"guangchang1e",
        "south" : __DIR__"shijie11",
        "west" : __DIR__"guangchang1w",
    ]));

    set("outdoors", "shaolin");
    set("item_desc",([
        "gate"        :    (: look_gate :),
    ]));
    set("objects",([
        CLASS_D("shaolin") + "/qing-fa" : 1,
    ]));
    setup();
        // To "load" the board, don't ever "clone" a bulletin board.
        call_other( "/obj/board/shaolin_b", "???" );     
}
void init()
{
    add_action("do_open", "open");
}   
void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"smdian")) )
		room = load_object(__DIR__"smdian");
	if(objectp(room))
	{
		delete("exits/north");
			message("vision", "ɮ����ǰ�Ѵ��Ź���������\n", this_object());
		room->delete("exits/south");
		message("vision", "ƹ��һ�����������˰Ѵ��Ź����ˡ�\n", room);
	}
}

int do_close(string arg)
{
	if (!query("exits/south"))
		return notify_fail("�����Ѿ��ǹ��ŵ��ˡ�\n");

	if (!arg || (arg != "gate" && arg != "north"))
		return notify_fail("��Ҫ��ʲô��\n");

//	message_vision("$N��ɮ�����˵�ͷ��\n", this_player());

	remove_call_out("close_gate");
	call_out("close_gate", 2);

	return 1;
}

int do_open(string arg)
{
	object room;

	if (query("exits/north"))
		return notify_fail("�����Ѿ��ǿ����ˡ�\n");

	if (!arg || (arg != "gate" && arg != "north"))
		return notify_fail("��Ҫ��ʲô��\n");

	if(!( room = find_object(__DIR__"smdian")) )
		room = load_object(__DIR__"smdian");
	if(objectp(room))
	{
		set("exits/north", __DIR__"smdian");
		message_vision("$Nʹ���Ѵ��Ŵ��˿�����\n", this_player());
		room->set("exits/south", __FILE__);
		message("vision", "֨��һ�����������˰Ѵ��Ŵ��ˡ�\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}

string look_gate()
{
	return "һ���������ߵ����ɼľ��ͭ���š�\n����Գ��Դ�(open)����\n";
}

/*
int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "south" ) return 0;

	return ::valid_leave(me, dir);
}
*/
