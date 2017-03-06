//ROOM: d/suzhou/sjin.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"ˮ��"NOR);
	set("long", @LONG
	  ������һ��ˮ���ԡ����������Ѻ�ˮ����һ����������ɺǺ�Ц�ˡ�
LONG
	);  
	set("resource/water", 1);
	set("no_sleep_room", 1);
	set("outdoors","suzhou"); 
	set("exits", ([
		"south" : __DIR__"wroad4",
	]));
	setup();
}

void init()
{
        add_action("do_drink", "drink");
}
int do_drink(string arg)
{
        int current_water;
	int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+70);
            message("vision", me->name()+"ſ��ˮ���ľ�̨����ˮͰҨ��һͰˮ�ȡ�\n"
            , environment(me), ({me}) );
            write("�����һ�ھ��дӵ������ʳ����ĸ�Ȫˮ����ֱ���ۻ���\n");
        }
        else write("���Ų�ҪǮ��ˮ����ô�ȣ�������?\n");

        return 1;
}





